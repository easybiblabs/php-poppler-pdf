--TEST--
poppler_open() function - basic test for poppler_open()
--FILE--
<?php
var_dump(poppler_open("something"));
?>
--EXPECT--
Hello somethingstring(11) "Hello World"
