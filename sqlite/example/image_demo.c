#include<stdio.h>
#include "sqlite3.h"

int main(int argc,char *argv[])
{
	FILE *fp = fopen("test.jpg","rb");
	if(fp == NULL)
	{
		fprintf(stderr, "%s:%d   Cannot open image file\n",__FILE__,__LINE__);
		return 1;
	}
	//把文件指针移到文件末尾
	fseek(fp,0,SEEK_END);
	if(ferror(fp))
	{
		fprintf(stderr, "fseek() failed\n");
		int r = fclose(fp);
		if(r == EOF)
		{
			fprintf(stderr, "Cannot close file handler\n");
		}

		return 1;
	}
	//ftell用于得到文件位置指针当前位置对于文件首的偏移字节数
	//既是文件的大小
	int flen = ftell(fp);
	if(flen == -1)
	{
		perror("error occurred");
		int r = fclose(fp);
		if(r == EOF)
		{
			fprintf(stderr, "Cannot close file handler\n");
		}
		return 1;
	}

	//把文件指针设置到文件头
	fseek(fp,0,SEEK_SET);
	if(ferror(fp))
	{
		fprintf(stderr, " fseek() failed\n");
		int r = fclose(fp);
		if(r == EOF)
		{
			fprintf(stderr, "Cannot close file handler\n");
		}
		return 1;
	}

	char data[flen+1];
	int size = fread(data,1,flen,fp);
	if(ferror(fp))
	{
		fprintf(stderr, "fread() failed\n");
		int r = fclose(fp);
		if(r == EOF)
		{
			fprintf(stderr, "Cannot close file handler\n");
		}
		return 1;
	}
	int r = fclose(fp);
	if(r == EOF)
	{
		fprintf(stderr, "Cannot close file handler\n");
	}

	sqlite3 *db;
	char *err_msg = 0;

	int rc = sqlite3_open("test.db",&db);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database:%s\n", sqlite3_errmsg(db));
		sqlite3_close(db);

		return 1;
	}
	sqlite3_stmt *pStmt;
	char *sql = "insert into image(data) values(?)";
	rc = sqlite3_prepare(db,sql,-1,&pStmt,0);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot prepare statement:%s\n",sqlite3_errmsg(db));
		return 1;
	}

	sqlite3_bind_blob(pStmt,1,data,size,SQLITE_STATIC);
	rc = sqlite3_step(pStmt);
	if(rc != SQLITE_DONE)
	{
		printf("execution failed:%s",sqlite3_errmsg(db));
	}
	sqlite3_finalize(pStmt);
	sqlite3_close(db);

	//下面代码是从数据库中读取图像
	FILE  *fp2 = fopen("create_image.jpg","wb");
	if(fp2 == NULL)
	{
		fprintf(stderr, "%s:%d   Cannot open image file\n",__FILE__,__LINE__);
		return 1;
	}
	sqlite3 *db2;
	char *err_msg2 = 0;
	sqlite3_stmt *pStmt2;

	rc = sqlite3_open("test.db",&db2);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "Cannot open database:%s\n", sqlite3_errmsg(db2));
		sqlite3_close(db2);

		return 1;
	}
	char *sql2 = "select data from image where id = 1";
	rc = sqlite3_prepare_v2(db2,sql2,-1,&pStmt2,0);
	if(rc != SQLITE_OK)
	{
		fprintf(stderr, "Failed to prepare statement\n");
		fprintf(stderr, "Cannot open database:%s\n",sqlite3_errmsg(db2) );

		sqlite3_close(db2);

		return 1;
	}
	rc = sqlite3_step(pStmt2);
	int bytes = 0;
	if(rc == SQLITE_ROW)
	{
		bytes = sqlite3_column_bytes(pStmt2,0);
	}
	fwrite(sqlite3_column_blob(pStmt2,0),bytes,1,fp2);
	if(ferror(fp2))
	{
		fprintf(stderr, "fwrite() failed\n");

		return 1;
	}
	r = fclose(fp2);
	if(r == EOF)
	{
		fprintf(stderr, "Cannot close file handler\n");
	}

	rc = sqlite3_finalize(pStmt2);
	sqlite3_close(db2);

	return 0;

}
