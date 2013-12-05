--TEST--
basic test for poppler_pdf_text()
--FILE--
<?php
$p = poppler_pdf_open("sample.pdf");
var_dump(poppler_pdf_text($p, 0));
?>
--EXPECT--
array(30) {
  [0]=>
  array(4) {
    ["text"]=>
    string(1) "Â"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [1]=>
  array(4) {
    ["text"]=>
    string(6) "
SAMPL"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(28)
    ["is_underlined"]=>
    bool(false)
  }
  [2]=>
  array(4) {
    ["text"]=>
    string(1) "Â"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(28)
    ["is_underlined"]=>
    bool(false)
  }
  [3]=>
  array(4) {
    ["text"]=>
    string(6) "LETTER"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(28)
    ["is_underlined"]=>
    bool(false)
  }
  [4]=>
  array(4) {
    ["text"]=>
    string(1) " "
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(28)
    ["is_underlined"]=>
    bool(false)
  }
  [5]=>
  array(4) {
    ["text"]=>
    string(1) "Â"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [6]=>
  array(4) {
    ["text"]=>
    string(5) "
DATE"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [7]=>
  array(4) {
    ["text"]=>
    string(3) " 
Â"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [8]=>
  array(4) {
    ["text"]=>
    string(5) "
Â 
N"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [9]=>
  array(4) {
    ["text"]=>
    string(13) "MEÂ  Â 
Â 
Â "
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [10]=>
  array(4) {
    ["text"]=>
    string(90) "Â 
Â 
Â 
Â 
EQUIFAXÂ PROMOTIONÂ CODE:Â 
ADDRESSÂ LINEÂ 1Â 
ADDRESSÂ LINEÂ 2Â 
ADDRESSÂ LIN"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [11]=>
  array(4) {
    ["text"]=>
    string(3) "Â 3"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [12]=>
  array(4) {
    ["text"]=>
    string(33) " 
CITY,Â STATE,Â ZIPÂ 
Â 
Â 
Dear"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [13]=>
  array(4) {
    ["text"]=>
    string(1) " "
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [14]=>
  array(4) {
    ["text"]=>
    string(543) "oliceÂ PensionÂ FundÂ Member:Â 
Â 
OnÂ Friday,Â FebruaryÂ 27,Â 2009,Â anÂ employeeÂ ofÂ theÂ PoliceÂ PensionÂ FundÂ (PPF)Â wasÂ swiftlyÂ arrestedÂ 
dueÂ toÂ aÂ securityÂ breachÂ atÂ ourÂ DisasterÂ RecoveryÂ SiteÂ (DRS).Â Â AtÂ theÂ timeÂ ofÂ hisÂ arrest,Â thisÂ individualÂ hadÂ 
inÂ hisÂ possessionÂ certainÂ businessÂ recordsÂ belongingÂ toÂ thisÂ Agency.Â Â TheseÂ businessÂ recordsÂ containedÂ 
dataÂ  aboutÂ  retiredÂ  andÂ  activeÂ  membersÂ  ofÂ  theÂ  PoliceÂ  PensionÂ  Fund,Â  specifically,Â  dataÂ  thatÂ  mayÂ  haveÂ 
includedÂ  pe"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [15]=>
  array(4) {
    ["text"]=>
    string(1) "s"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [16]=>
  array(4) {
    ["text"]=>
    string(549) "nalÂ  informationÂ  suchÂ  asÂ  socialÂ  securityÂ  numbers,Â  names,Â  addressesÂ  andÂ  bankÂ  accountÂ 
data.Â  Â  EvenÂ  thoughÂ  theÂ  propertyÂ  wasÂ  recovered,Â  weÂ  cannotÂ  assureÂ  youÂ  thatÂ  theÂ  informationÂ  wasÂ  notÂ 
compromised.Â Â ItÂ isÂ theÂ responsibilityÂ ofÂ theÂ FundÂ toÂ informÂ youÂ andÂ explainÂ whatÂ stepsÂ youÂ mayÂ takeÂ toÂ 
protectÂ yourselfÂ fromÂ theÂ possibilityÂ ofÂ identityÂ theft.Â Â InÂ addition,Â undercoverÂ identitiesÂ andÂ undercoverÂ 
informationÂ WASÂ NOTÂ compromised,Â asÂ theirÂ dataÂ isÂ notÂ"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [17]=>
  array(4) {
    ["text"]=>
    string(1) "m"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [18]=>
  array(4) {
    ["text"]=>
    string(331) "intainedÂ atÂ theÂ DRS.Â Â Furthermore,Â anyoneÂ 
hiredÂ afterÂ MayÂ 2007Â areÂ notÂ affectedÂ byÂ thisÂ breach.Â Â AllÂ informationÂ afterÂ thatÂ dateÂ isÂ encryptedÂ andÂ 
thereforeÂ notÂ vulnerable.Â 
Â 
ToÂ helpÂ youÂ protectÂ personalÂ informationÂ thatÂ thisÂ dataÂ mayÂ haveÂ contained,Â theÂ PoliceÂ PensionÂ 
FundÂ hasÂ ar"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [19]=>
  array(4) {
    ["text"]=>
    string(1) "a"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [20]=>
  array(4) {
    ["text"]=>
    string(265) "gedÂ forÂ youÂ toÂ receiveÂ theÂ EquifaxÂ CreditÂ WatchÂ productÂ freeÂ ofÂ chargeÂ forÂ oneÂ year.Â Â InÂ 
orderÂ toÂ initiateÂ thisÂ creditÂ protection,Â youÂ mustÂ applyÂ byÂ JuneÂ 15,Â 2009.Â Â ThisÂ productÂ isÂ describedÂ inÂ theÂ 
enclosedÂ literature.Â 
Â 
"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [21]=>
  array(4) {
    ["text"]=>
    string(1) "h"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [22]=>
  array(4) {
    ["text"]=>
    string(104) "therÂ orÂ notÂ youÂ chooseÂ toÂ takeÂ advantageÂ ofÂ theÂ offerÂ fromÂ theÂ PPF,Â weÂ recommendÂ thatÂ 
"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [23]=>
  array(4) {
    ["text"]=>
    string(1) "o"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [24]=>
  array(4) {
    ["text"]=>
    string(185) "Â  readÂ  theÂ  enclosedÂ  consumerÂ  alertÂ  fromÂ  theÂ  FederalÂ  TradeÂ  CommissionÂ  describingÂ  additionalÂ  stepsÂ 
thatÂ youÂ canÂ takeÂ toÂ protectÂ yourselfÂ againstÂ identit"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [25]=>
  array(4) {
    ["text"]=>
    string(3) "Â t"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [26]=>
  array(4) {
    ["text"]=>
    string(11) "eft.Â 
Â 
T"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [27]=>
  array(4) {
    ["text"]=>
    string(5) "eÂ Po"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [28]=>
  array(4) {
    ["text"]=>
    string(35) "iceÂ PensionÂ FundÂ deeplyÂ regrets"
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
  [29]=>
  array(4) {
    ["text"]=>
    string(1) " "
    ["font_name"]=>
    string(7) "Calibri"
    ["font_size"]=>
    int(10)
    ["is_underlined"]=>
    bool(false)
  }
}
