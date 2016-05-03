
#include <stdio.h>
#include <sqlite3.h>

int main(void)
{
	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open("test.db",&db);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "%s:%d  Cannot open database:%s\n",__FILE__,__LINE__,sqlite3_errmsg(db) );
		sqlite3_close(db);

		return 1;
	}

	char *sql = "insert into student(age,name) values(40,'stu5')";

	// char *sql = "select * from sqlite_master";
	rc = sqlite3_exec(db,sql,0,0,&err_msg);
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
