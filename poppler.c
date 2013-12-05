
/* php boilerplate */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_poppler.h"

static zend_function_entry poppler_functions[] = {
    PHP_FE(poppler_pdf_info, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry poppler_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_POPPLER_EXTNAME,
    poppler_functions,
    NULL,
    NULL,
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

/* poppler */

#include <poppler.h>
#include <glib.h>

/* main */

PHP_FUNCTION(poppler_pdf_info)
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

    php_printf("title: %s\n", poppler_document_get_title(doc));
    php_printf("author: %s\n", poppler_document_get_author(doc));
    php_printf("subject: %s\n", poppler_document_get_subject(doc));
    php_printf("keywords: %s\n", poppler_document_get_keywords(doc));
    php_printf("creator: %s\n", poppler_document_get_creator(doc));

    free(doc);
    RETURN_STRING("Hello World", 1);
}
