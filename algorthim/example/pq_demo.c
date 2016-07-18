#include <stdio.h>

#include "priorityQueue.h"
int main()
{
	// double xx = 2.0;
	// double *value = &xx;
	// pqueue_t pq = pq_new(sizeof(double),10);
	// pq_insert(pq,(void *)value);
	// pq_print(pq);
	double xx[10] = {1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0,10.0};
	pqueue_t pq = pq_new_by_array(xx,sizeof(double),10);
	// pqueue_t pq = pq_new(sizeof(double),10);
	// for(int i = 0;i < 10;i++)
	// {
	// 	void *value = &xx[i];
	// 	pq_insert(pq,(void *)value);
	// }
	// pq_print(pq);
	double *ret = pq_delMax(pq);
	printf("max = %f\n",*ret);
	pq_print(pq);


}
