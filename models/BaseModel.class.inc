<?php
class BaseModel {
  private $data;

  public function __construct() {
    $this->data = array();

  }
  public function __get($var) {
    if(isset($this->data[$var])) {
      return $this->data[$var];
    }
    return $this->$var;
  }
  public function __set($var,$value) {
    $this->data[$var] = $value;
  }

}
