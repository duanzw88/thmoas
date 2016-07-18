/**
 * 二叉查找树
 */

#ifndef BST_H
#define BST_H

#include "item.h"

#define T bst_t
typedef struct T *T;

extern T 	    bst_new();
extern int 	    bst_count(T bst);

extern void     bst_insert(T bst,item_t item);
extern item_t   bst_search(T bst,Key key);
extern void     bst_inorder(T bst);

extern item_t   bst_min(T bst);
extern item_t   bst_max(T bst);

extern void     bst_free(T bst);



#undef T
#endif
