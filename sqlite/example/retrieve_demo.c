#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

int callback(void *,int,char **,char **);

int main(int argc,char *argv[])
{
	sqlite3 *db;
	char *err_msg = 0;
	if(argc < 2)
	{
		fprintf(stderr, "Usage:retrieve_demo dbfile\n");
		return 1;
	}
	int rc = sqlite3_open(argv[1],&db);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "%s:%d  Cannot open database:%s\n",__FILE__,__LINE__,sqlite3_errmsg(db) );
		sqlite3_close(db);

		return 1;
	}

	char *sql = "select * from student";
	rc = sqlite3_exec(db,sql,callback,0,&err_msg);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "%s:%d  SQL error:%s\n",__FILE__,__LINE__,err_msg );
		sqlite3_free(err_msg);
		sqlite3_close(db);

		return 1;
	}
	sqlite3_close(db);

	return 0;
}
/**
 * [callback description]
 * @param  NotUsed   [description]
 * @param  argc      结果中的列数
 * @param  argv      结果中的属性值
 * @param  azColName 列名
 * @return           [description]
 */
int callback(void *NotUsed,int argc,char **argv,char **azColName)
{
	printf("callback...argc = %d\n",argc);
	NotUsed = 0;
	for(int i = 0; i < argc; i++)
	{
		printf("i = %d\n",i);
		printf("%s = %s\n",azColName[i],argv[i] ? argv[i] : "NULL");
	}

	printf("\n");

	return 0;
}
