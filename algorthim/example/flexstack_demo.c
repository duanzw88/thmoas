#include <stdlib.h>
#include <stdio.h>
#include "mem.h"
#include "timer.h"
#include "flexstack.h"

#define LENGTH 10
#define RESIZE_LENGTH 15

int main()
{
	int i;
	int data;
	flexstack_t stack;
	timer_t timer = timer_new();
	timer_start(timer);
	stack = flexstack_new(LENGTH,sizeof(int));


	for(i = 0;i <  LENGTH; i++)
	{
		int *p;
		NEW(p);
		*p = i + 1;
		// array_put(array,i,p);
		flexstack_push(stack,p);
	}

	for(i = 0;i <  LENGTH; i++)
	{
		data = *(int *)flexstack_pop(stack);
		printf("item %d:%d\n",i,data);
	}

	printf("program time:%f(s)\n",timer_elapsedTime(timer));
}
