#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "binarySearch.h"
#include "timer.h"

int cmp(const void *a,const void *b)
{
	return (*(int *)a - *(int *)b);
}
static int count(int a[],int length)
{
	int zero_count = 0;
	int i,j,k;
	for(i = 0; i < length; i++)
	{
		for(j = i+1; j < length; j++)
		{
			for(k = j + 1;k < length; k++)
			{
				if((a[i] + a[j] + a[k]) == 0)
				{
					zero_count++;
				}
			}
		}
	}
	return zero_count;
}
static int sum3fast(int a[],int length)
{
	int zero_count = 0;
	int i,j,k;
	for(i = 0; i < length; i++)
	{
		for(j = i+1; j < length; j++)
		{
			//用二分法查找
			if(binary_rank(-a[i]-a[j],a,length) > j)
			{
				zero_count++;
			}
		}
	}
	// printf("zero_count = %d\n",zero_count);
	return zero_count;
}
/**
 * 随机产生一个包含N个元素的数组，计算相邻三个任意三个元素的和是否为0
 * @param  N [description]
 * @return   [description]
 */
static double timeTrial(int a[],int N)
{
	int count_normal = 0;
	double time_normal = 0.0;

	timer_t timer = timer_new();
	timer_start(timer);
	count_normal = count(a,N);
	time_normal = timer_elapsedTime(timer);
	// printf("N = %d count_normal = %d time_normal = %f(s)\n",N,count_normal,time_normal);
	printf("N = %d count_normal = %d time_normal = %f(s) ",N,count_normal,time_normal);
	return time_normal;

}
static double timeTrialFast(int a[],int N)
{
	int i;

	int count_fast = 0;
	double time_fast = 0.0;
	timer_t timer = timer_new();

	timer_start(timer);
	count_fast = sum3fast(a,N);
	time_fast = timer_elapsedTime(timer);
	printf("N = %d count_fast = %d time_fast = %f(s) ",N,count_fast,time_fast);

	return time_fast;

}

int  *initRandom(int N)
{
	int i;
	int *a = (int *)malloc(N * sizeof(int));
	//随机生成N个数据保存到数组中
	srand((unsigned)time(NULL));
	for(i = 0;i < N;i++)
	{
		a[i] = (int)(rand() % 2000001 - 1000000);
	}
	//对数组进行排序
	qsort(a,N,sizeof(a[0]),cmp);
	// for(i = 0;i < N;i++)
	// {
	// 	printf("a[%d] = %d\n",i,a[i]);
	// }
	return a;
}

int main(int argc,char *argv[])
{
	int i;
    int num = 0;


	// timer_start(timer);
    // FILE* fp1 = fopen(argv[1],"r");
    // if(fp1==NULL)
    //     return 1;
	//
    // fscanf(fp1,"%d",&num);
	// int *a = (int *)malloc(num * sizeof(int));
    // for(i=0;i < num;++i)
	// {
	// 	fscanf(fp1,"%d",&a[i]);
	// }
	//
	// printf("sum0 count = %d time = %f(s)\n",count(a,num),timer_elapsedTime(timer));
    // fclose(fp1);
    int *b = initRandom(125);
	double  prev = timeTrialFast(b,125);
	free(b);
	for(i = 250; i < 1000000;i += i)
	{
		//生产随机数
		int *a = initRandom(i);

		//timeTrial(a,i);
		double current = timeTrialFast(a,i);
		// printf("N = %d ",i);
		printf("Ratio = %f(s)\n",current / prev);
		prev = current;
		free(a);
	}
    return 0;
}
