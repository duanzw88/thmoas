#include <stdio.h>
#include <stdlib.h>

#include "mem.h"
#include "item.h"
#include "rbtree.h"

static int arr[] = {5,1,4,3,2,6};
// static int arr[] = {5,1,4};
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
	// rbtree_t tree = rbtree_new();
	//
	// int len = TBL_SIZE(arr);
	// for(int i = 0;i < len;i++)
	// {
	// 	item_t item = item_new();
	// 	item_setKey(item,arr[i]);
	// 	item_setValue(item,arr[i]);
	//
	// 	rbtree_insert(tree,item);
	// 	rbtree_inorder(tree);
	// 	// printf("count = %d\n\n\n",rbtree_count(tree));
	// 	printf("\n\n\n");
	//
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

	rbtree_t tree = rbtree_new();
	int *a = (int *)malloc(count * sizeof(int));

	for(int i = 0;i < count;i++)
	{
		fscanf(file,"%d",&a[i]);
		item_t item = item_new();
		item_setKey(item,a[i]);
		item_setValue(item,a[i]);
		rbtree_insert(tree,item);
	}
	free(a);
	//
	printf("\n\n");
	rbtree_inorder(tree);
	printf("\n\n");
	printf("height = %d\n",rbtree_height(tree));
	printf("bst count = %d\n",rbtree_count(tree));
	item_t item = rbtree_get(tree,864355);
	if(item != NULL)
	{
		printf("get Item key = %d value = %d\n",item_getKey(item),item_getValue(item));
	}
	else{
		printf("search null\n");
	}

	item = rbtree_min(tree);
	printf("item min = (%d %d)\n",item_getKey(item),item_getValue(item));
	//
	item = rbtree_max(tree);
	printf("item max = (%d %d)\n",item_getKey(item),item_getValue(item));


	printf("After deleteMin:\n");
	rbtree_deleteMin(tree);
	item = rbtree_min(tree);
	printf("item min = (%d %d)\n",item_getKey(item),item_getValue(item));

	printf("After deleteMax:\n");
	rbtree_deleteMax(tree);
	item = rbtree_max(tree);
	printf("item max = (%d %d)\n",item_getKey(item),item_getValue(item));


	rbtree_free(tree);

	// mem_leak((void *)inuse,stdout);
	// getchar();
}
