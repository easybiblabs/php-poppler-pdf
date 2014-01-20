php-poppler-pdf
===============

[![Build Status](https://travis-ci.org/easybiblabs/php-poppler-pdf.png?branch=master)](https://travis-ci.org/easybiblabs/php-poppler-pdf)

WARNING
-------

Work-in-progress, do not use yet!

---

A PHP extension using [libpoppler](http://poppler.freedesktop.org/).

This is (will be) a high-level binding (a bit like `pdfinfo` and `pdftotext`), and
does not expose the whole poppler API.

todo
----

* proper documentation
* setup/install stuff
* gcov on travis / https://github.com/eddyxu/cpp-coveralls

build
-----

    $ phpize
    $ ./configure
    $ make

functions
---------

    poppler_pdf_open($filename);

Returns a PopplerDocument resource, or `null` on errors.

    poppler_pdf_info(PopplerDocument $doc);

Returns an array with PDF meta-data.

    poppler_pdf_text(PopplerDocument $doc, $page_number);

Returns a string with the (unformatted) text of that page.

    poppler_pdf_formatted_text(PopplerDocument $doc, $page_number);

Returns a list of chunks of that page's text, including formatting
information.  The keys for each chunk are:
* `text` - the raw text
* `font_name` - the name of the font
* `font_size` - the font size
* `is_underlined` - whether or not the text is underlined (not very reliable)

license
-------

Copyright (C) 2013 by Richard Wossal <richard@r-wos.org>

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject
to the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

