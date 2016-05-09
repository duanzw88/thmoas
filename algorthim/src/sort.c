#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "assert.h"
#include "sort.h"
void swap(void *a,void *b,int size)
{
	assert(a != NULL && b != NULL);
	void *buffer = (void *)malloc(size);
	memcpy(buffer,a,size);
	memcpy(a,b,size);
	memcpy(b,buffer,size);

	free(buffer);
}
void q_sort(void *base,int start,int end,int size,int (*cmp)(const void *a,const void *b))
{
	assert(base != NULL && size >= 1 && cmp != NULL);
	if(start >= end)
	{
		return;
	}

	char *pleft = (char *)base + start * size;
	char *pkey = (char *)base + (start + (end - start) / 2) * size;
	swap(pleft,pkey,size);
	int last = start;
	char *plast = (char *)base + last * size;
	for(int i = start + 1;i <= end; ++i)
	{
		char *pi = (char *)base + i * size;
		if(cmp(pi,pleft) < 0)
		{
			++last;
			plast = (char *)base + last * size;
			swap(pi,plast,size);
		}
	}
	q_sort(base,start,last - 1,size,cmp);
	q_sort(base,last + 1,end,size,cmp);
}
void select_sort(void *base,int start,int end,int size,int (*cmp)(const void *a,const void *b))
{
	int i;

	for(i = start; i <= end; i++)
	{
		char *min = (char *)base + i * size;
		for(int j = i + 1; j <= end; j++)
		{
			char *current = (char *)base + j * size;
			if(cmp(current,min) < 0)
			{
				min = current;
			}
		}
		char *data = (char *)base + i * size;
		swap(data,min,size);
	}

}

int cmp_int(const void *a,const void *b)
{
	assert(a != NULL && b != NULL);
	const int * lhs = (const int *)a;
	const int * rhs = (const int *)b;

	if(*lhs < *rhs)
	{
		return -1;
	}
	else if(*lhs == *rhs)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int cmp_double(const void *a,const void *b)
{
	assert(a != NULL && b != NULL);
	const double * lhs = (const double *)a;
	const double * rhs = (const double *)b;

	if(*lhs < *rhs)
	{
		return -1;
	}
	else if(*lhs == *rhs)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int cmp_char(const void *a,const void *b)
{
	assert(a != NULL && b != NULL);
	const char * lhs = (const char *)a;
	const char * rhs = (const char *)b;

	if(*lhs < *rhs)
	{
		return -1;
	}
	else if(*lhs == *rhs)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int  cmp_string(const void *a,const void *b)
{
	assert(a != NULL && b != NULL);
	const char ** lhs = (const char **)a;
	const char ** rhs = (const char **)b;

	return strcmp(*lhs,*rhs);
}
