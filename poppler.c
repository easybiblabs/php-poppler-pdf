
/* php boilerplate */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_poppler.h"

/* poppler, etc. */
#include <poppler.h>
#include <glib.h>
#include <unistd.h>

static zend_function_entry poppler_functions[] = {
    PHP_FE(poppler_pdf_open, NULL)
    PHP_FE(poppler_pdf_info, NULL)
    PHP_FE(poppler_pdf_text, NULL)
    PHP_FE(poppler_pdf_formatted_text, NULL)
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

static void php_poppler_document_free(zend_resource *rsrc TSRMLS_DC)
{
    PopplerDocument *doc = (PopplerDocument*)rsrc->ptr;

    if (doc != NULL) {
        g_object_unref(doc);
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
    g_type_init();
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
        add_assoc_string(ret, key, s);
    }
}

PHP_FUNCTION(poppler_pdf_open)
{
    char *name;
    size_t name_len;
    gchar *uri;

    PopplerDocument *doc;
    GError *err = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }

    {
        /* file name handling */
        /* XXX this is hacky... */
        gchar *cwd;
        gchar *abs_name;

        cwd = g_get_current_dir();
        if (!g_path_is_absolute(name)) {
            abs_name = g_build_filename(cwd, name, NULL);
        } else {
            abs_name = g_build_filename(name, NULL);
        }
        gfree(cwd);
        uri = g_filename_to_uri(abs_name, NULL, NULL);
        gfree(abs_name);
        if (uri == NULL) {
            /* TODO: throw exception? */
            RETURN_NULL();
        }
    }
    doc = poppler_document_new_from_file(uri, NULL, &err);
    free(uri);

    if (doc == NULL) {
        /* TODO: throw exception? */
        /* php_printf("ERROR: %s\n", err->message); */
        RETURN_NULL();
    }

    RETURN_RES(zend_register_resource(doc, le_poppler_document));
}

PHP_FUNCTION(poppler_pdf_info)
{
    PopplerDocument *doc;
    zval *zdoc;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &zdoc) == FAILURE) {
        RETURN_NULL();
    }
    if (NULL == (doc = (PopplerDocument *)zend_fetch_resource(Z_RES_P(zdoc), PHP_POPPLER_DOCUMENT_NAME, le_poppler_document))) {
        RETURN_NULL();
    }

    array_init(return_value);

    add_assoc_maybe_string(return_value, "pdf_version", poppler_document_get_pdf_version_string(doc));

    add_assoc_maybe_string(return_value, "title", poppler_document_get_title(doc));
    add_assoc_maybe_string(return_value, "author", poppler_document_get_author(doc));
    add_assoc_maybe_string(return_value, "subject", poppler_document_get_subject(doc));
    add_assoc_maybe_string(return_value, "keywords", poppler_document_get_keywords(doc));
    add_assoc_maybe_string(return_value, "creator", poppler_document_get_creator(doc));
    add_assoc_maybe_string(return_value, "producer", poppler_document_get_producer(doc));

    add_assoc_long(return_value, "pages",             poppler_document_get_n_pages(doc));
    add_assoc_long(return_value, "creation_date",     poppler_document_get_creation_date(doc));
    add_assoc_long(return_value, "modification_date", poppler_document_get_modification_date(doc));
}

PHP_FUNCTION(poppler_pdf_text)
{
    PopplerDocument *doc;
    PopplerPage *page;
    long page_i;
    char *text;
    GList *attr_list;
    zval *zdoc;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rl", &zdoc, &page_i) == FAILURE) {
        RETURN_NULL();
    }
    if (NULL == (doc = (PopplerDocument *)zend_fetch_resource(Z_RES_P(zdoc), PHP_POPPLER_DOCUMENT_NAME, le_poppler_document))) {
        RETURN_NULL();
    }

    if (page_i < 0 || page_i >= poppler_document_get_n_pages(doc)) {
        RETURN_NULL();
    }
    page = poppler_document_get_page(doc, page_i);
    if (page == NULL) {
        RETURN_NULL();
    }

    text = poppler_page_get_text(page);
    g_object_unref(page);

    RETURN_STRING(text);
}

PHP_FUNCTION(poppler_pdf_formatted_text)
{
    PopplerDocument *doc;
    PopplerPage *page;
    long page_i;
    char *text;
    GList *attr_list;
    zval *zdoc;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "rl", &zdoc, &page_i) == FAILURE) {
        RETURN_NULL();
    }
    if (NULL == (doc = (PopplerDocument *)zend_fetch_resource(Z_RES_P(zdoc), PHP_POPPLER_DOCUMENT_NAME, le_poppler_document))) {
        RETURN_NULL();
    }

    if (page_i < 0 || page_i >= poppler_document_get_n_pages(doc)) {
        RETURN_NULL();
    }
    page = poppler_document_get_page(doc, page_i);
    if (page == NULL) {
        RETURN_NULL();
    }

    text = poppler_page_get_text(page);

    array_init(return_value);

    attr_list = poppler_page_get_text_attributes(page);
    {
        GList *el;
        PopplerTextAttributes *attr;
        zval text_part;

        for (el = g_list_first(attr_list); el; el = el->next) {
            attr = el->data;
            array_init(&text_part);

            add_assoc_stringl(&text_part, "text", text + (attr->start_index), (attr->end_index) - (attr->start_index));
            add_assoc_maybe_string(&text_part, "font_name", attr->font_name);
            add_assoc_long(&text_part, "font_size", attr->font_size);
            add_assoc_bool(&text_part, "is_underlined", attr->is_underlined);
            add_next_index_zval(return_value, &text_part);
        }
    }

    poppler_page_free_text_attributes(attr_list);
    g_object_unref(page);
}
