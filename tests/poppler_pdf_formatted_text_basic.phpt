--TEST--
basic test for poppler_pdf_formatted_text()
--FILE--
<?php
$p = poppler_pdf_open("sample.pdf");
var_dump(poppler_pdf_formatted_text($p, 0));
?>
--EXPECT--
array(6) {
  [0]=>
  array(4) {
    ["text"]=>
    string(25) "This is a Sample Document"
    ["font_name"]=>
    string(19) "LiberationSans-Bold"
    ["font_size"]=>
    int(18)
    ["is_underlined"]=>
    bool(false)
  }
  [1]=>
  array(4) {
    ["text"]=>
    string(8) "Subtitle"
    ["font_name"]=>
    string(21) "LiberationSans-Italic"
    ["font_size"]=>
    int(14)
    ["is_underlined"]=>
    bool(false)
  }
  [2]=>
  array(4) {
    ["text"]=>
    string(14) "Some Body Text"
    ["font_name"]=>
    string(15) "LiberationSerif"
    ["font_size"]=>
    int(12)
    ["is_underlined"]=>
    bool(false)
  }
  [3]=>
  array(4) {
    ["text"]=>
    string(13) "First Heading"
    ["font_name"]=>
    string(19) "LiberationSans-Bold"
    ["font_size"]=>
    int(16)
    ["is_underlined"]=>
    bool(false)
  }
  [4]=>
  array(4) {
    ["text"]=>
    string(19) "Some more Body Text"
    ["font_name"]=>
    string(15) "LiberationSerif"
    ["font_size"]=>
    int(12)
    ["is_underlined"]=>
    bool(false)
  }
  [5]=>
  array(4) {
    ["text"]=>
    string(10) "Underlined"
    ["font_name"]=>
    string(15) "LiberationSerif"
    ["font_size"]=>
    int(18)
    ["is_underlined"]=>
    bool(false)
  }
}
