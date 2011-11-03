<?php

class BaseController {
  protected $data;
  public function __construct() {
    $this->data = array();
  }
  public function access() {
    return false;
  }
  protected function render($template = NULL) {
    global $controllerName, $method, $module_path;
    if(!$template) {
      $template = "$method";
    }
    foreach($this->data as $key => $value) {
      $$key = $value;
    }
    ob_start();
    include("$module_path/views/$controllerName/$template.html.php");
    $template = ob_get_contents();
    ob_end_clean();
    return $template;

  }
  protected function setVar($name,$var) {
    $this->data[$name] = $var;
  }
}
