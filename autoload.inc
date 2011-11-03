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
    /** 
     * Since we override drupal's autoloader, make sure we
     * hand it off to drupal if nothing is found.
		 */
		return _registry_check_code('class', $class);
	}
	public static function addPath($path) {
		$path = realpath($path);
		if($path) {
			self::$paths[] = $path;
		}
	}
}
spl_autoload_register(array('AutoLoader', 'load'));
