#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define N 		100
#define MAX 	50
#define MIN 	0.1
#define MIU 	2
#define SIGMA 	1
#define PI 		3.14159


double averageRandom(double min,double max)
{
	//产生(min max)之间均匀分布的随机数
	int MINnteger = (int)(min * 10000);
	int MAXnteger = (int)(max * 10000);

	int randInteger = rand() * rand();
	int diffInteger = MAXnteger - MINnteger;
	int resultInteger = randInteger % diffInteger + MINnteger;

	return (double)resultInteger / 10000.0;
}
double logNormal(double x,double miu,double sigma)
{
	//对数正态分布概率密度函数
	return 1.0 / (x * sqrt(2 * PI) * sigma) * exp(-1 * (log(x) - miu) * (log(x) - miu) / (2 * sigma*sigma));
}
double random_lognormal(double miu,double sigma,double min,double max)
{
	double x;
	double dScope;
	double y;

	do {
		x = averageRandom(min,max);
		y = logNormal(x,miu,sigma);
		dScope = averageRandom(0,logNormal(miu,miu,sigma));
	} while(dScope > y);

	return x;
}

int main()
{
	float f1 = 34.6;
	float f2 = 34.5;
	float f3 = 34.0;
	printf("34.6-34.0 = %f\n",f1-f3);
	printf("34.5-34.0 = %f\n",f2-f3);

	float xx[10];
	int i = 0;
	for(i = 0;i < 10 ;i++)
	{
		xx[i] = 5.1;
	}

	float sum = 0;
	for(i = 0;i < 10 ;i++)
	{
		sum += xx[i];
	}
	printf("average = %f\n",sum/10);


	return 0;

}
