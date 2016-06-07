php-poppler-pdf
===============

[![Build Status](https://travis-ci.org/easybiblabs/php-poppler-pdf.png?branch=master)](https://travis-ci.org/easybiblabs/php-poppler-pdf)

[![Coverity Scan Build Status](https://scan.coverity.com/projects/1379/badge.svg)](https://scan.coverity.com/projects/1379)

A PHP extension using [libpoppler](http://poppler.freedesktop.org/).

This is a high-level binding (a bit like `pdfinfo` and `pdftotext`), and
does not expose the whole poppler API.

Build
-----

    $ phpize
    $ ./configure
    $ make

If you happen to be on Ubuntu 12.04 LTS, you can also use [our
PPA](https://launchpad.net/~easybib/+archive/php55). This extension
is in there under the name `php5-easybib-poppler-pdf`.

Functions
---------

    poppler_pdf_open($filename);

Returns a PopplerDocument resource, or `null` on errors.

    poppler_pdf_info(PopplerDocument $doc);

Returns an array with PDF meta-data (like `pdfinfo`).

    poppler_pdf_text(PopplerDocument $doc, $page_number);

Returns a string with the (unformatted) text of that page (like `pdftotext`).

    poppler_pdf_formatted_text(PopplerDocument $doc, $page_number);

Returns a list of chunks of that page's text, including formatting
information.  The keys for each chunk are:
* `text` - the raw text
* `font_name` - the name of the font
* `font_size` - the font size
* `is_underlined` - whether or not the text is underlined (not very reliable)
