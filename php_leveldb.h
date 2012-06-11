/*
  +----------------------------------------------------------------------+
  | PHP Version 5                                                        |
  +----------------------------------------------------------------------+
  | Copyright (c) 1997-2012 The PHP Group                                |
  +----------------------------------------------------------------------+
  | This source file is subject to version 3.01 of the PHP license,      |
  | that is bundled with this package in the file LICENSE, and is        |
  | available through the world-wide-web at the following url:           |
  | http://www.php.net/license/3_01.txt                                  |
  | If you did not receive a copy of the PHP license and are unable to   |
  | obtain it through the world-wide-web, please send a note to          |
  | license@php.net so we can mail you a copy immediately.               |
  +----------------------------------------------------------------------+
  | Author: Reeze Xia <reeze.xia@gmail.com>                              |
  +----------------------------------------------------------------------+
*/

/* $Id$ */

#ifndef PHP_LEVELDB_H
#define PHP_LEVELDB_H

#define PHP_LEVELDB_VERSION "0.0.1"

extern zend_module_entry leveldb_module_entry;
#define phpext_leveldb_ptr &leveldb_module_entry

#ifdef PHP_WIN32
#	define PHP_LEVELDB_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_LEVELDB_API __attribute__ ((visibility("default")))
#else
#	define PHP_LEVELDB_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_METHOD(LevelDB, __construct);
PHP_METHOD(LevelDB, get);
PHP_METHOD(LevelDB, set);
PHP_METHOD(LevelDB, put);
PHP_METHOD(LevelDB, delete);
PHP_METHOD(LevelDB, write);
PHP_METHOD(LevelDB, destroy);
PHP_METHOD(LevelDB, repair);

PHP_MINIT_FUNCTION(leveldb);
PHP_MSHUTDOWN_FUNCTION(leveldb);
PHP_RINIT_FUNCTION(leveldb);
PHP_RSHUTDOWN_FUNCTION(leveldb);
PHP_MINFO_FUNCTION(leveldb);

PHP_METHOD(LevelDBWriteBatch, __construct);
PHP_METHOD(LevelDBWriteBatch, set);
PHP_METHOD(LevelDBWriteBatch, put);
PHP_METHOD(LevelDBWriteBatch, delete);
PHP_METHOD(LevelDBWriteBatch, clear);

#ifdef ZTS
#define LDB_G(v) TSRMG(leveldb_globals_id, zend_leveldb_globals *, v)
#else
#define LDB_G(v) (leveldb_globals.v)
#endif

#endif	/* PHP_LEVELDB_H */


/*
 * Local variables:
 * tab-width: 4
 * c-basic-offset: 4
 * End:
 * vim600: noet sw=4 ts=4 fdm=marker
 * vim<600: noet sw=4 ts=4
 */
