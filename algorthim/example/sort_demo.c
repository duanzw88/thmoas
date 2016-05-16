#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "timer.h"
#include "sort.h"

double  *initRandom(int N)
{
	int i;
	double *a = (double *)malloc(N * sizeof(double));
	//随机生成N个数据保存到数组中
	srand((unsigned)time(NULL));
	for(i = 0;i < N;i++)
	{
		// a[i] = (int)(rand() % 2000001 - 1000000);
		a[i] = (double)(rand() / (double)(RAND_MAX)/100);
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
		insert_sort(data,0,N-1,sizeof(double),cmp_double);
	}
	else if(strcmp(sort_function,"Selection") == 0)
	{
		select_sort(data,0,N-1,sizeof(double),cmp_double);
	}
	else if(strcmp(sort_function,"Shell") == 0)
	{
		shell_sort(data,0,N-1,sizeof(double),cmp_double);
	}
	else if(strcmp(sort_function,"Merge") == 0)
	{
		merge_sort(data,0,N-1,sizeof(double),cmp_double);
	}
	else if(strcmp(sort_function,"Merge2") == 0)
	{
		merge_sort2(data,5,N-1,sizeof(double),cmp_double);
	}
	else if(strcmp(sort_function,"Quick") == 0)
	{
		quick_sort(data,0,N-1,sizeof(double),cmp_double);
	}
	else if(strcmp(sort_function,"Quick3") == 0)
	{
		quick3way_sort(data,0,N-1,sizeof(double),cmp_double);
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
		double *data = initRandom(N);
		// if(N < 300)
		// {
		// 	for(int i = 0;i < N;i++)
		// 	{
		// 		printf("%.6f ",data[i]);
		// 		if(i % 10 == 0)
		// 		{
		// 			printf("\n");
		// 		}
		// 	}
		// 	printf("\n");
		// }
		// printf("----------------------\n");
		total += timeTrial(sort_function,data,N);
		// if(N < 300)
		// {
		// 	for(int i = 0;i < N;i++)
		// 	{
		// 		printf("%.6f ",data[i]);
		// 		if(i % 10 == 0)
		// 		{
		// 			printf("\n");
		// 		}
		// 	}
		// 	printf("\n");
		// }
	}
	return total;
}

int main(int argc,char *argv[])
{
	int N = 100;
	int T = 10;


	double insertT = timeRandomInput("Insertion",N,T);
	double shellT  = timeRandomInput("Shell",N,T);
	double selectT = timeRandomInput("Selection",N,T);
	double mergeT  = timeRandomInput("Merge",N,T);
	double quickT  = timeRandomInput("Quick",N,T);
	double quick3wayT = timeRandomInput("Quick3",N,T);
	printf("insertT = %f  shellT = %f selectT = %f mergeT = %f quickT = %f quick3T = %f\n",insertT,shellT,selectT,mergeT,quickT,quick3wayT);

	// double quickT  = timeRandomInput("Quick",200,1);

}
