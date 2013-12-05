
/* php boilerplate */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_poppler.h"

/* poppler */
#include <poppler.h>
#include <glib.h>

static zend_function_entry poppler_functions[] = {
    PHP_FE(poppler_pdf_info, NULL)
    PHP_FE(poppler_pdf_open, NULL)
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
    PopplerDocument *doc = (PopplerDocument*)rsrc->ptr;

    if (doc != NULL) {
        g_free(doc);
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

    PopplerDocument *doc;
    GError *err = NULL;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }

    doc = poppler_document_new_from_file(name, NULL, &err);
    if (doc == NULL) {
        /* TODO: throw exception? */
        /* php_printf("ERROR: %s\n", err->message); */
        RETURN_NULL();
    }

    ZEND_REGISTER_RESOURCE(return_value, doc, le_poppler_document);
}

PHP_FUNCTION(poppler_pdf_info)
{
    PopplerDocument *doc;
    zval *zdoc;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "r", &zdoc) == FAILURE) {
        RETURN_NULL();
    }
    ZEND_FETCH_RESOURCE(doc, PopplerDocument*, &zdoc, -1, PHP_POPPLER_DOCUMENT_NAME, le_poppler_document);

    array_init(return_value);

    add_assoc_maybe_string(return_value, "pdf_version", poppler_document_get_pdf_version_string(doc));

    add_assoc_maybe_string(return_value, "title", poppler_document_get_title(doc));
    add_assoc_maybe_string(return_value, "author", poppler_document_get_author(doc));
    add_assoc_maybe_string(return_value, "subject", poppler_document_get_subject(doc));
    add_assoc_maybe_string(return_value, "keywords", poppler_document_get_keywords(doc));
    add_assoc_maybe_string(return_value, "creator", poppler_document_get_creator(doc));
    add_assoc_maybe_string(return_value, "producer", poppler_document_get_producer(doc));

    add_assoc_long(return_value, "creation_date",     poppler_document_get_creation_date(doc));
    add_assoc_long(return_value, "modification_date", poppler_document_get_modification_date(doc));
}
