#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

int main()
{
	btree_t root,leftChild1,rightChild1;

	root = btree_new();
	leftChild1 = btree_new_by_data(2);
	rightChild1 = btree_new_by_data(3);
	btree_add_data(root,1);
	btree_insertLeftNode(root,leftChild1);
	btree_insertRightNode(root,rightChild1);

	printf("------------前序遍历-------------\n");
	btree_preOrder(root);
	printf("\n");
	printf("------------中序遍历-------------\n");
	btree_inOrder(root);
	printf("\n");
	printf("------------后序遍历-------------\n");
	btree_postOrder(root);
	printf("\n");
	printf("------------所有叶子节点数据-------------\n");
	btree_outputLeaf(root);
	printf("\n");
	printf("leaf count = %d\n",btree_getLeafCount(root));
	printf("depth = %d\n",btree_getDepth(root));
	printf("node count = %d\n",btree_getAllNode(root));
	printf("\n\n\n\n");

	printf("root = %p\n",root);
	printf("left = %p\n",leftChild1);
	printf("right = %p\n",rightChild1);

	printf("------------搜索-------------\n");
	btree_t p = btree_search(root,2);
	printf("serach p = %p\n",p);
	printf("serach p depth = %d\n",btree_getDepth(p));
	btree_deleteNode(root,p);

	// printf("---------------删除左节点--------------\n");
	// btree_deleteLeftNode(root);
	// printf("leaf count = %d\n",btree_getLeafCount(root));
	// printf("depth = %d\n",btree_getDepth(root));
	// printf("node count = %d\n",btree_getAllNode(root));
	// printf("---------------删除右节点--------------\n");
	// btree_deleteRightNode(root);
	// printf("leaf count = %d\n",btree_getLeafCount(root));
	// printf("depth = %d\n",btree_getDepth(root));
	// printf("node count = %d\n",btree_getAllNode(root));

	// btree_free(root);
}
