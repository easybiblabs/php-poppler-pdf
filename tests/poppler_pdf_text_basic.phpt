--TEST--
basic test for poppler_pdf_text()
--FILE--
<?php
$p = poppler_pdf_open("sample.pdf");
var_dump(poppler_pdf_text($p, 0));
?>
--EXPECT--
string(95) "This is a Sample Document
Subtitle
Some Body Text
First Heading
Some more Body Text
Underlined
"
