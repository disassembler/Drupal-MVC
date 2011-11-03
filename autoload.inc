<?php
class AutoLoader {
	protected static $paths = array();
	public static function load($class) {
		if(class_exists($class, FALSE)) {
			return;
		}
		foreach (self::$paths as $path) {
			if(file_exists("$path/controllers/$class.class.inc")) {
				require_once("$path/controllers/$class.class.inc");
				return;
			}
			else if(file_exists("$path/models/$class.class.inc")) {
				require_once("$path/models/$class.class.inc");
				return;
			}

		}
	}
	public static function addPath($path) {
		$path = realpath($path);
		if($path) {
			self::$paths[] = $path;
		}
	}
}
spl_autoload_register(array('AutoLoader', 'load'));
