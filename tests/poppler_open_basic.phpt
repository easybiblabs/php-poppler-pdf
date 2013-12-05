--TEST--
poppler_open() function - basic test for poppler_open()
--FILE--
<?php
$p = poppler_pdf_open("file:///home/richard/src/work/pdfminer/purification-green-fluor-protein-kit.pdf");
var_dump(poppler_pdf_info($p));
?>
--EXPECT--
TODO
