#include <stdio.h>
#include <stdlib.h>
#include "sqlite3.h"

int main(int argc,char *argv[])
{
	sqlite3 *db;
	char *err_msg = 0;
	sqlite3_stmt *res;
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

	char *sql = "SELECT id, age, name from student where id = ?";
	rc = sqlite3_prepare_v2(db,sql,-1,&res,0);
	if(rc == SQLITE_OK)
	{
		sqlite3_bind_int(res,1,3);
	}
	else
	{
		fprintf(stderr, "%s:%d  Failed to execute statemenet:%s\n",__FILE__,__LINE__, sqlite3_errmsg(db));
	}

	int step = sqlite3_step(res);
	if(step == SQLITE_ROW)
	{
		printf("%s: ",sqlite3_column_text(res,0));
		printf("%d ",sqlite3_column_int(res,1));
		printf("%s\n",sqlite3_column_text(res,2));
	}
	printf("-------\n");
	char *sql2 = "select id,age,name from student where id = @id";
	rc = sqlite3_prepare_v2(db,sql2,-1,&res,0);
	if(rc == SQLITE_OK)
	{
		int idx = sqlite3_bind_parameter_index(res,"@id");
		int value = 3;
		sqlite3_bind_int(res,idx,value);
	}
	else
	{
		fprintf(stderr, "%s:%d  Failed to execute statemenet:%s\n",__FILE__,__LINE__, sqlite3_errmsg(db));
	}

	step = sqlite3_step(res);
	if(step == SQLITE_ROW)
	{
		printf("%s: ",sqlite3_column_text(res,0));
		printf("%d ",sqlite3_column_int(res,1));
		printf("%s\n",sqlite3_column_text(res,2));
	}

	sqlite3_finalize(res);
	sqlite3_close(db);

	return 0;
}
