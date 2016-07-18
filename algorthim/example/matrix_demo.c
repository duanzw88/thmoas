#include <stdio.h>

#include "mem.h"
#include "matrix.h"

void inuse(const void *ptr,long size,const char *file,int line,void *cl)
{
	FILE *log = cl;

	fprintf(log,"**memory in use at %p\n",ptr);
	fprintf(log,"This block is %ld bytes long and was allocted from %s:%d\n",size,file,line);
}
void test_copy()
{
	matrix_t foo = matrix_new(3,3);
	matrix_put(foo,1,1,10.0);
	matrix_t bar = matrix_copy(foo);
	matrix_print(bar);
	matrix_free(foo);
	matrix_free(bar);
}

void test_inverse()
{
	matrix_t foo = matrix_new_by_value(4,4,
	     1.0, 2.0, 3.0, 4.0,
	     4.0, 1.0, 7.0, 9.0,
	     0.0, 0.0, -4.0, -4.0,
	     2.3, 3.4, 3.1, 0.0);

	printf("原矩阵:\n");
  	matrix_print(foo);
	printf("转置矩阵:\n");
	matrix_t fooT = matrix_transpose(foo);
	matrix_print(fooT);
	printf("逆矩阵:\n");
	matrix_t fooInv = matrix_inverse(foo);//matrix_transpose(foo);
  	matrix_print(fooInv);
	printf("原矩阵*逆矩阵:\n");
	matrix_t result = matrix_mul_and_matrix(foo,fooInv);
    matrix_print(result);

  	matrix_free(foo);
  	matrix_free(fooT);
	matrix_free(fooInv);
	matrix_free(result);
}
int main()
{
	test_copy();
	// test_inverse();
	// mem_leak((void *)inuse,stdout);

}
