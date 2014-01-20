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
  string(14) "Metadata Title"
  ["author"]=>
  NULL
  ["subject"]=>
  string(16) "Metadata Subject"
  ["keywords"]=>
  string(17) "Metadata Keywords"
  ["creator"]=>
  string(6) "Writer"
  ["producer"]=>
  string(15) "LibreOffice 4.1"
  ["pages"]=>
  int(1)
  ["creation_date"]=>
  int(1390224912)
  ["modification_date"]=>
  int(-1)
}
