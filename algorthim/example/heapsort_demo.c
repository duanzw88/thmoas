#include <stdio.h>
#include <stdlib.h>

#include "sort.h"

#define NUM 16

int main(int argc,char *argv[])
{
	// // char char_data[] = {'K','R','A','T','E','L','E','P','U','I','M','Q','C','X','O','S'};
	// char char_data[] = {'S','O','R','T','E','X','A','M','P','L','E'};
	//
	// heap_sort(char_data,0,10,sizeof(char),cmp_char);
	// // for(int i = 0;i < 11;i++)
	// // {
	// // 	printf("%c ",char_data[i]);
	// // }
	// // printf("\n");
	// timer_start(timer);
	int i,num;
    FILE* in = fopen(argv[1],"r");
	FILE* out = fopen(argv[2],"w");
    if(in == NULL || out == NULL)
        return 1;

    fscanf(in,"%d",&num);
	int *a = (int *)malloc(num * sizeof(int));
    for(i=0;i < num;++i)
	{
		fscanf(in,"%d",&a[i]);
	}
	heap_sort(a,0,num-1,sizeof(int),cmp_int);
	for(i=0;i < num;++i)
	{
		fprintf(out,"%d\n",a[i]);
	}
    fclose(in);
	fclose(out);
}
