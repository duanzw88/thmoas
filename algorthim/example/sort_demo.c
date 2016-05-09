#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

int main()
{
	// int str[] = {1,-2, 5, 1, 10, 8, 5, 4, 3, 9,-100};
	// select_sort(str,0,10,sizeof(int),cmp_int);
	//const char* str[] = {"chenwei", "dmr", "skyline", "wel", "what"};
	char str[12] = {'S','O','R','T','E','X','A','M','P','L','E','\0'};
	select_sort(str,0,10,sizeof(char),cmp_char);

	// for(int i = 0;i < 11;i++)
	// {
	// 	printf("%c ",str[i]);
	// }
	// printf("\n");
	printf("result = %s\n",str);
}
