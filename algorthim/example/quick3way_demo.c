#include <stdlib.h>
#include <stdio.h>

#include "sort.h"

#define NUM 16
int main()
{
	// char data[] = {'M','E','R','G','E','S','O','R','T','E','X','A','M','P','L','E'};

	// double data[] = {10.0,20.0,-10.0,40.0,-100.0,1000.0,400.0,-1990.0,-824.0,100.0,2444.0,10000.0,24.0,1154.0,-245.0,345.0};
	// quick3way_sort(data,0,NUM-1,sizeof(double),cmp_double);
	// for(int i = 0;i < NUM;i++)
	// {
	// 	printf("%.2f ",data[i]);
	// }
	// printf("\n");
	//
	char char_data[] = {'K','R','A','T','E','L','E','P','U','I','M','Q','C','X','O','S'};

	quick3way_sort(char_data,0,NUM-1,sizeof(char),cmp_char);
	for(int i = 0;i < NUM;i++)
	{
		printf("%c ",char_data[i]);
	}
	printf("\n");
}
