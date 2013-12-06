#include <iostream>
#include <poppler-document.h>
#include <poppler-page.h>

#include <poppler.h>

using namespace std;

/* php boilerplate */
#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_poppler.h"

static zend_function_entry poppler_functions[] = {
    PHP_FE(poppler_pdf_open, NULL)
    PHP_FE(poppler_pdf_info, NULL)
    PHP_FE(poppler_pdf_text, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry poppler_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_POPPLER_EXTNAME,
    poppler_functions,
    PHP_MINIT(poppler),
    PHP_MSHUTDOWN(poppler),
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_POPPLER_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_POPPLER
ZEND_GET_MODULE(poppler)
#endif

int le_poppler_document;

static void php_poppler_document_free(zend_rsrc_list_entry *rsrc TSRMLS_DC)
{
    poppler::document *doc = (poppler::document*)rsrc->ptr;

    if (doc != NULL) {
        delete doc;
    }
}

PHP_MINIT_FUNCTION(poppler)
{
    le_poppler_document = zend_register_list_destructors_ex(
        php_poppler_document_free,
        NULL,
        PHP_POPPLER_DOCUMENT_NAME,
        module_number
    );
    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(poppler)
{
    return SUCCESS;
}

/* main */

void add_assoc_maybe_string(zval *ret, const char *key, char *s)
{
    if (s == NULL) {
        add_assoc_null(ret, key);
    } else {
        add_assoc_string(ret, key, s, 1);
    }
}

PHP_FUNCTION(poppler_pdf_open)
{
    char *name;
    size_t name_len;

    poppler::document *doc;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }

    string s(name);
    doc = poppler::document::load_from_file(s);

    if (doc == NULL) {
        /* TODO: throw exception? */
        /* php_printf("ERROR: %s\n", err->message); */
        RETURN_NULL();
    }

    ZEND_REGISTER_RESOURCE(return_value, doc, le_poppler_document);
}


// XXX pretty sure we're leaking here
#define st(x) (reinterpret_cast<char *>(&(x.to_latin1()[0])))

PHP_FUNCTION(poppler_pdf_info)
{
    poppler::document *doc;
    zval *zdoc;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &zdoc) == FAILURE) {
        RETURN_NULL();
    }
    ZEND_FETCH_RESOURCE(doc, poppler::document*, &zdoc, -1, PHP_POPPLER_DOCUMENT_NAME, le_poppler_document);

    array_init(return_value);

    // XXX TODO: get_pdf_id, get_pdf_version

    add_assoc_maybe_string(return_value, "title", st(doc->info_key("Title")));
    add_assoc_maybe_string(return_value, "author", st(doc->info_key("Author")));
    add_assoc_maybe_string(return_value, "subject", st(doc->info_key("Subject")));
    add_assoc_maybe_string(return_value, "keywords", st(doc->info_key("Keywords")));
    add_assoc_maybe_string(return_value, "creator", st(doc->info_key("Creator")));
    add_assoc_maybe_string(return_value, "producer", st(doc->info_key("Producer")));

    add_assoc_long(return_value, "pages", doc->pages());
    add_assoc_long(return_value, "creation_date", doc->info_date("CreationDate"));
    add_assoc_long(return_value, "modification_date", doc->info_date("ModDate"));
}

PHP_FUNCTION(poppler_pdf_text)
{
    poppler::document *doc;
    poppler::page *page;
    long page_i;
    char *text;
    size_t textlen;
    zval *zdoc;

    GList *attr_list;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rl", &zdoc, &page_i) == FAILURE) {
        RETURN_NULL();
    }
    ZEND_FETCH_RESOURCE(doc, poppler::document*, &zdoc, -1, PHP_POPPLER_DOCUMENT_NAME, le_poppler_document);

    if (page_i < 0 || page_i >= doc->pages()) {
        RETURN_NULL();
    }
    page = doc->create_page(page_i);
    if (page == NULL) {
        RETURN_NULL();
    }

    text = st(page->text(page->page_rect(), page->raw_order_layout));
    textlen = strlen(text);

    array_init(return_value);

    // XXX TODO

    attr_list = poppler_page_get_text_attributes(page);
    {
        GList *el;
        PopplerTextAttributes *attr;
        zval *text_part;

        for (el = g_list_first(attr_list); el; el = el->next) {
            attr = (PopplerTextAttributes *)el->data;
            ALLOC_INIT_ZVAL(text_part);
            array_init(text_part);

            add_assoc_stringl(text_part, "text", text + (attr->start_index), (attr->end_index) - (attr->start_index), 1);
            add_assoc_maybe_string(text_part, "font_name", attr->font_name);
            add_assoc_long(text_part, "font_size", attr->font_size);
            add_assoc_bool(text_part, "is_underlined", attr->is_underlined);
            add_next_index_zval(return_value, text_part);
        }
    }
}
