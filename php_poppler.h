#ifndef PHP_POPPLER_H
#define PHP_POPPLER_H

#define PHP_POPPLER_VERSION "0.1"
#define PHP_POPPLER_EXTNAME "poppler"

#define PHP_POPPLER_DOCUMENT_NAME "PopplerDocument"

PHP_MINIT_FUNCTION(poppler);
PHP_MSHUTDOWN_FUNCTION(poppler);

PHP_FUNCTION(poppler_pdf_open);

PHP_FUNCTION(poppler_pdf_info);
PHP_FUNCTION(poppler_pdf_text);
PHP_FUNCTION(poppler_pdf_formatted_text);

extern zend_module_entry poppler_module_entry;
#define phpext_poppler_ptr &poppler_module_entry

#endif /* PHP_POPPLER_H */
