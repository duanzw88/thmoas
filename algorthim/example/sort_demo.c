#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "timer.h"
#include "sort.h"

int  *initRandom(int N)
{
	int i;
	int *a = (int *)malloc(N * sizeof(int));
	//随机生成N个数据保存到数组中
	srand((unsigned)time(NULL));
	for(i = 0;i < N;i++)
	{
		// a[i] = (int)(rand() % 2000001 - 1000000);
		a[i] = (int)(rand() % 2000001 - 1000000);
		//printf("%d ",a[i]);
	}
	//printf("\n");
	//对数组进行排序
	//qsort(a,N,sizeof(a[0]),cmp_int);

	return a;
}
static double timeTrial(const char *sort_function,void *data,int N)
{
	double time_normal = 0.0;

	timer_t timer = timer_new();
	timer_start(timer);
	if(strcmp(sort_function,"Insertion") == 0)
	{
		//插入排序
		insert_sort(data,0,N-1,sizeof(int),cmp_int);
	}
	else if(strcmp(sort_function,"Selection") == 0)
	{
		select_sort(data,0,N-1,sizeof(int),cmp_int);
	}
	else if(strcmp(sort_function,"Shell") == 0)
	{
		shell_sort(data,0,N-1,sizeof(int),cmp_int);
	}
	else if(strcmp(sort_function,"Merge") == 0)
	{
		merge_sort(data,0,N-1,sizeof(char),cmp_char);
	}

	time_normal = timer_elapsedTime(timer);

	return time_normal;

}
/**
 * N个元素的数组进行T次测试花费的总时间
 * @param  cmp [description]
 * @return     [description]
 */
static double timeRandomInput(const char *sort_function,int N,int T)
{
	double total = 0.0;
	for(int t = 0; t < T;t++)
	{
		int *data = initRandom(N);
		total += timeTrial(sort_function,data,N);
	}
	return total;
}
int main()
{
	// int *data = initRandom(100);
	// double t = timeTrial("Shell",data,100);
	// for(int i = 0;i < 100;i++)
	// {
	// 	printf("%d ",data[i]);
	// }
	// printf("\n");
	//
	char data[] = {'M','E','R','G','E','S','O','R','T','E','X','A','M','P','L','E'};
	// int *data = initRandom(16);
	//int data[] = {10,20,-10,40,-100,1000,400,-1990,-824,100,2444,10000,24,1154,-245,345};
	timeTrial("Merge",data,16);


	// for(int i = 0;i < 16;i++)
	// {
	// 	printf("%c ",data[i]);
	// }
	// printf("\n");

}
// int main(int argc,char *argv[])
// {
// 	// int N = 1000;
// 	// int T = 100;
// 	//
// 	//
// 	// double insertT = timeRandomInput("Insertion",N,T);
// 	// double shellT  = timeRandomInput("Shell",N,T);
// 	// double selectT = timeRandomInput("Selection",N,T);
// 	// double mergeT  = timeRandomInput("Merge",N,T);
// 	// printf("insertT = %f  shellT = %f selectT = %f mergeT = %f\n",insertT,shellT,selectT,mergeT);
// 	for(int i = 0;i < 10000;i++)
// 	{
// 		printf("i = %d\n",i);
// 		void *x = (void *)malloc(10);
// 		free(x);
// 	}
// }
