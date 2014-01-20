--TEST--
basic test for poppler_pdf_open()
--FILE--
<?php
$p = poppler_pdf_open("sample.pdf");
var_dump($p);
$p = poppler_pdf_open("/not there pdf");
var_dump($p);
?>
--EXPECT--
resource(4) of type (PopplerDocument)
Error: Couldn't open file '/not there pdf': No such file or directory.
NULL
