/**
 * 优先队列：
 * 		普通的队列是一种先进先出的数据结构，元素在队列尾追加。
 * 		在优先队列中，元素被赋予优先级，当访问元素时，具有最高优先级的元素最先删除。
 * 		优先队列具有最高级先出的行为特征
 * 	优先队列支持两种基本操作：
 * 		1.向优先队列中插入一个新的数据项
 * 		2. 删除(最大)优先队列中的关键字最大的数据项
 * 	优先队列具有很好的灵活性，能支持的操作如下:
 * 		1.根据N各数据项构造一个优先队列
 * 		2.插入一个数据项
 * 		3.删除最大值的数据项
 * 		4.改变任意给定的数据项的优先级
 * 		5.删除任意给定的数据项
 * 		6.合并两个优先队列为一个优先队列
 */
#include <stdlib.h>
#include "priorityQueue.h"

#define T pqueue_t
struct T
{
	void *data;
	int itemsize;
	int length;
}


extern T 		pq_new(int itemsize,int length);
extern void 	pq_insert(T pq,void *sv);
extern void    *pq_delMax(T pq);
extern int 		pq_size(T pq);
extern int 		pq_isEmpty(T pq);
