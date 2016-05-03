# SQLite常用API
## 打开
- 接口

```
	sqlite3_open(const char *filename,sqlite3 **ppDb);
```
- 说明
	该接口打开一个指向SQLite数据库文件的连接，返回一个用于其他SQLite程序的数据库连接对象。
	如果filename参数是NULL或':memory:',那么sqlite3_open将会在RAM中创建一个内存数据库，这只会在session的有效时间内持续。
	如果filename不为NULL，那么sqlite3_open()将使用这个参数值尝试打开数据库文件，
	如果该名称的文件不存在，sqlite3_open()将创建一个新的命名为该名称的数据库文件并打开
## 执行

```
	sqlite3_exec(sqlite3 *,const char *sql,sqlite_callback,void *data,char **errmsg);
```
- 说明
	该接口提供了一个执行SQL命令的快捷方式，SQL命令由sql参数提供，可以由多个SQL命令组成。
	第一个参数书打开的数据库对象
	sqlite_callback是一个回调
	data作为回调函数的第一个参数，通常为0
	errmsg将被返回用来获取程序生成的任何错误
	该接口解析并执行由sql参数所给的每个命令，直到字符串结束或者遇到错误为止。

## 关闭
- 接口
```
	sqlite3_close(sqlite3*)
```
- 说明
	该接口关闭以上调用的sqlite3_open打开的数据库，所有与连接相关的语句都应在连接关闭之前完成。
	如果查询没有完成，sqlite3_close将返回SQLITE_BUSY禁止关闭的错误消息
