#include <stdio.h>
#include <stdlib.h>
#include "mem.h"
#include "item.h"
#include "bst.h"

static int arr[] = {1,5,4,3,2,6};
#define TBL_SIZE(a)  ((sizeof(a)) / sizeof(a[0]))

void inuse(const void *ptr,long size,const char *file,int line,void *cl)
{
	FILE *log = cl;

	fprintf(log,"**memory in use at %p\n",ptr);
	fprintf(log,"This block is %ld bytes long and was allocted from %s:%d\n",size,file,line);
}

int main(int argc,char *argv[])
{
	//功能测试用例
	// bst_t bst = bst_new();
	//
	// int len = TBL_SIZE(arr);
	// for(int i = 0;i < len;i++)
	// {
	// 	item_t item = item_new();
	// 	item_setKey(item,arr[i]);
	// 	item_setValue(item,arr[i]);
	// 	bst_insert(bst,item);
	// 	bst_inorder(bst);
	// 	printf("\n\n\n");
	// }


	//性能测试用例
	if(argc < 2)
	{
		printf("Usage bst_demo test_file\n");
		return -1;
	}
	FILE *file = fopen(argv[1],"r");
	if(file == NULL)
	{
		printf("fopen file failed...\n");
		return -1;
	}
	int count;
	fscanf(file,"%d",&count);
	printf("count = %d\n",count);

	bst_t bst = bst_new();
	int *a = (int *)malloc(count * sizeof(int));

	for(int i = 0;i < count;i++)
	{
		fscanf(file,"%d",&a[i]);
		item_t item = item_new();
		item_setKey(item,a[i]);
		item_setValue(item,a[i]);
		bst_insert(bst,item);
	}

	printf("\n\n");
	bst_inorder(bst);
	printf("\n\n");
	printf("bst count = %d\n",bst_count(bst));
	item_t item = bst_search(bst,864355);
	if(item != NULL)
	{
		printf("get Item key = %d value = %d\n",item_getKey(item),item_getValue(item));
	}
	else{
		printf("search null\n");
	}

	item = bst_min(bst);
	printf("item min = (%d %d)\n",item_getKey(item),item_getValue(item));

	item = bst_max(bst);
	printf("item max = (%d %d)\n",item_getKey(item),item_getValue(item));

	free(a);
	bst_free(bst);

	mem_leak((void *)inuse,stdout);
	// getchar();
}
