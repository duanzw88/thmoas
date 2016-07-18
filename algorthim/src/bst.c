/**
 * 二叉查找树
 * 二叉查找树是继承了链表插入的灵活性和有序数组查找的高效性
 * 二叉查找树的实现：
 * 一颗二叉查找树，其中每个节点都含有一个键和一个值，
 * 				且每个节点的键都大于其左子树种的任意节点
 * 				而小于右子树的任意节点的键
 * 难点：
 * 插入：
 * 插入是利用递归的方式实现的，
 * 如果树是空的，就插入到二叉查找树的根节点
 * 如果被插入的节点的键小于根节点的键，会递归在左子树中插入该键
 * 如果被插入的节点的键大于根节点的键,会递归在右子树中插入该键
 * 递归的实现：
 *   把新节点想象成沿着树往下走，它会新节点的键和每个节点的键值相比较，
 *   然后根据比较结果决定向左或者向右移动到下一个节点
 * date:2016-6-21
 */

#include <stdlib.h>
#include <stdio.h>
#include "assert.h"
#include "mem.h"

#include "bst.h"

#define T bst_t
struct T
{
	int count;
	struct bst_node
	{
		item_t item;
		struct bst_node *leftChild;
		struct bst_node *rightChild;
	}*head;
};
typedef struct bst_node* BstNode;


/**
 * 新建一颗二叉查找树
 * @return [description]
 */
T 	bst_new()
{
	T bst;
	NEW(bst);
	bst->count = 0;
	bst->head = 0;
	return bst;
}
int bst_count(T bst)
{
	assert(bst);
	return bst->count;
}


void insert(BstNode node,item_t item)
{
	item_t nodeItem = node->item;

	if(item_getKey(nodeItem) == item_getKey(item))
	{
		node->item = item;
	}
	else if(item_getKey(nodeItem) < item_getKey(item))
	{
		if(node->rightChild == NULL)
		{
			BstNode newNode;
			NEW(newNode);
			newNode->item = item;
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;

			node->rightChild = newNode;
		}
		else
		{
			insert(node->rightChild,item);
		}

	}
	else
	{
		if(node->leftChild == NULL)
		{
			BstNode newNode;
			NEW(newNode);
			newNode->item = item;
			newNode->leftChild = NULL;
			newNode->rightChild = NULL;

			node->leftChild = newNode;
		}
		else
		{
			insert(node->leftChild,item);
		}

	}
}
/**
 * 在二叉查找树中插入元素
 * @param bst  目标二叉查找树
 * @param item 要插入的元素(如果已经存在该元素的Key，则只进行更新)
 */
void bst_insert(T bst,item_t item)
{
	assert(bst);
	assert(item);

	if(bst->head == NULL)
	{
		BstNode node;
		NEW(node);
		node->item = item;
		node->leftChild = NULL;
		node->rightChild = NULL;

		bst->head = node;
		bst->count++;
	}
	else
	{
		insert(bst->head,item);
		bst->count++;
	}

}
item_t search(BstNode node,Key key)
{
	if(node == NULL)
	{
		return NULL;
	}
	item_t item = node->item;
	if(item_getKey(item) == key)
	{
		return item;
	}
	else if(item_getKey(item) < key)
	{
		return search(node->rightChild,key);
	}
	else
	{
		return search(node->leftChild,key);
	}
}
item_t bst_search(T bst,Key key)
{
	if(bst == NULL)
	{
		return NULL;
	}

	return search(bst->head,key);

}


void inorder(BstNode node)
{
	if(node == NULL)
	{
		return;
	}
	item_t item = node->item;

	inorder(node->leftChild);
	printf("%d  ",item_getValue(item));
	inorder(node->rightChild);
}
/**
 * 前序遍历
 * @param bst 对二叉查找树进行前序遍历(前序遍历就是排序后的结果)
 */
void bst_inorder(T bst)
{
	printf("inorder:\n");
	inorder(bst->head);
}
item_t min(BstNode node)
{
	if(node->leftChild == NULL)
	{
		return node->item;
	}
	return min(node->leftChild);
}
/**
 * 二叉查找树中最小的元素
 * @param  bst 目标二叉查找树
 * @return     最小的元素的键值
 */
item_t  bst_min(T bst)
{
	if(bst == NULL || bst->head == NULL)
	{
		return NULL;
	}
	return min(bst->head);
}

item_t max(BstNode node)
{
	if(node->rightChild == NULL)
	{
		return node->item;
	}
	return max(node->rightChild);
}
/**
 * 二叉查找树中最大的元素
 * @param  bst 目标二叉查找树
 * @return     最大的元素
 */
item_t  bst_max(T bst)
{
	if(bst == NULL || bst->head == NULL)
	{
		return NULL;
	}
	return max(bst->head);
}

void freeNode(BstNode node)
{
	if(node == NULL)
	{
		return;
	}
	item_free(node->item);
	freeNode(node->leftChild);
	freeNode(node->rightChild);
	FREE(node);
}
void     bst_free(T bst)
{
	freeNode(bst->head);
	FREE(bst);
}
