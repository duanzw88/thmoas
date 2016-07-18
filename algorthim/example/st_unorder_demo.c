#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "item.h"
#include "st_unorder.h"

#define N 10

Key randkey()
{
  return (rand() % 100);
}
Item randItem(Key key)
{
  Item item = malloc(sizeof(Item));

  key(item) = key;
  // item->value = (rand() % 1000);
  item->value = key * 10 + 1;
  return item;
}

int main(int argc,char *argv[])
{
	Item item;
	Key key,search_key;
	st_unorder_t st = st_new(N);

	srand(time(NULL));
	for(int i = 0; i < N; i++)
	{
		// key = randkey();
		key = i + 1;
		if(st_search(st,key) != NULL)
		{
			continue;
		}

		item = randItem(key);
		printf("insert(%d %d)\n",item->key,item->value);
		st_insert(st,item);

	}

	for(int i = 0;i < N;i++)
	{
		key = i + 1;
		Item result = st_search(st,key);
		printf("(%d,%d)\n",result->key,result->value);
	}
	st_free(st);
	return 0;
}
