
#include <stdlib.h>
#include <stdio.h>
#include "counter.h"

int main()
{
	counter_t counter = counter_new("test");

	counter_increment(counter);
	printf("name = %s\n",counter_get_name(counter));
	printf("result = %d\n",counter_get_tally(counter));
}
