--TEST--
basic test for poppler_pdf_info()
--FILE--
<?php
$p = poppler_pdf_open("sample.pdf");
$info = poppler_pdf_info($p);
unset($info["creation_date"]); // XXX changes on travis-CI
var_dump($info);
?>
--EXPECT--
array(9) {
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
  ["modification_date"]=>
  int(-1)
}
