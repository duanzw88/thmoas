#ifndef _PRIORITYQUEUE_H
#define _PRIORITYQUEUE_H

#define T pqueue_t
typedef struct T *T;


extern T 		pq_new(int itemsize,int length);
extern void 	pq_insert(T pq,void *sv);
extern void    *pq_delMax(T pq);
extern int 		pq_length(T pq);
extern int 		pq_isEmpty(T pq);

#undef T
#endif
