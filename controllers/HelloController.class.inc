<?php

class HelloController extends BaseController {
	public function hello($args) {
		global $user;
		if(isset($args[0])) {
			$name = $args[0];
		}
		else {
			$name = "Anonymous";
		}
		$this->setVar('name',$name);
		if($user->uid) {
			return $this->render();
		}
		return $this->render('hello_guest');
	}
	public function denied() {
		return t('this page should be inaccessible');

	}
	/**
	 */
	public function access() {
		global $method;
		if($method == 'denied') {
			return false;
		}
		return true;
	}

}
?>
