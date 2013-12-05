--TEST--
basic test for poppler_pdf_info()
--FILE--
<?php
$p = poppler_pdf_open("sample.pdf");
var_dump(poppler_pdf_info($p));
?>
--EXPECT--
array(10) {
  ["pdf_version"]=>
  string(7) "PDF-1.4"
  ["title"]=>
  string(35) "Microsoft Word - Sample Letter .doc"
  ["author"]=>
  string(7) "mbrusco"
  ["subject"]=>
  NULL
  ["keywords"]=>
  NULL
  ["creator"]=>
  string(26) "PScript5.dll Version 5.2.2"
  ["producer"]=>
  string(33) "Acrobat Distiller 8.0.0 (Windows)"
  ["pages"]=>
  int(1)
  ["creation_date"]=>
  int(1236157910)
  ["modification_date"]=>
  int(1236157910)
}
