#ifndef PHP_POPPLER_H
#define PHP_POPPLER_H

#define PHP_POPPLER_VERSION "0.1"
#define PHP_POPPLER_EXTNAME "poppler"

PHP_FUNCTION(poppler_pdf_info);

extern zend_module_entry poppler_module_entry;
#define phpext_poppler_ptr &poppler_module_entry

#endif /* PHP_POPPLER_H */
