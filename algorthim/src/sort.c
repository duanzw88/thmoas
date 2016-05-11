/**
 * 排序算法集结
 * @author duanzw
 * 选择排序:
 * 		一种最简单的排序，
 * 		首先，找到数组中最小的那个元素，
 * 		其次，将它和数组的第一个元素交换位置
 * 		再次，在剩下的元素中找到最小的元素和数组的第二个元素交换
 * 		如此往复，直到将整个数组排序
 * 	  该算法的时间效率取决于比较的次数
 * 	  对于长度为N的数组，选择排序需要N*N/2次比较和N次交换
 * 	  特点：
 * 		 运行时间和输入无关
 * 		 数据移动是最少的：交换次数和数组的大小是线性关系
 * 插入排序:
 * 		与选择排序一样，当前索引左边的所有元素都是有序的，但他们的最终位置还不确定，
 * 		为了给更小的元素腾出空间，他们可能会被移动，
 * 		当索引数组达到右端是，数组排序就完成了
 * 	  插入排序所需的时间取决于元素中的初始顺序
 * 	  对于长度为N的数组，平均情况下排序需要约等于N*N/4次比较和约等于N*N/4次交换
 * 	  				  最坏的情况需要N*N/2次比较和N*N/2交换
 * 	  				  最好的情况需要N-1次比较和0次交换
 * 希尔排序:
 * 		希尔排序是插入排序的演化增强版，
 * 		希尔排序的思想是使数组中任意间隔为h的元素都是有序的，这样的数组称为h有序数组。
 * 		用插入法将h个子数组独立的排序，然后逐步减小h的值直到1 就完成了排序
 * 归并排序:
 * 		思想:归并排序是另一种利用分治法排序的算法，首先将数据集二等分为左右两个区间，分别在左右两个区间上递归使用归并排序算法，
 * 			然后将排序后的两个区间合并为一个有序区间。
 * 		将两个有序的数组归并成一个更大的有序数组
 * 		要将一个数组排序，可以先(递归的)将它分成两半分别排序，然后将结果归并起来
 * 		原地归并抽象方法：将数组的子数组a[lo .. mid]和数组a[mid+1 .. hi]归并成一个有序的数组并将结果存放在a[lo .. hi]中
 * 		自顶向下的归并排序:
 * 								a[0..15]
 * 									|
 * 					 -----------------------------------
 * 					 |                                 |
 * 			     a[0..7]                           a[8..15]
 * 					|								   |
 * 	        -----------------               ----------------------
 * 			|		        |               |                    |
 * 		a[0..3]	 		a[4..7] 		a[8..11]     		a[12..15]
 * 		   |			   |			   |         	        |
 * 	   --------- 	    --------       ----------	        ---------
 * 	   |       |	    |      |       |        |           |       |
 * a[0..1]  a[2..3]	a[4..5] a[6..7]	a[8..9] a[10..11]   a[12..13]  a[14..15]
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "mem.h"
#include "assert.h"
#include "sort.h"
void swap(void *a,void *b,int size)
{
	assert(a != NULL && b != NULL);
	void *buffer = (void *)malloc(size);
	memcpy(buffer,a,size);
	memcpy(a,b,size);
	memcpy(b,buffer,size);

	free(buffer);
}

void q_sort(void *base,int start,int end,int size,int (*cmp)(const void *a,const void *b))
{
	assert(base != NULL && size >= 1 && cmp != NULL);
	if(start >= end)
	{
		return;
	}

	char *pleft = (char *)base + start * size;
	char *pkey = (char *)base + (start + (end - start) / 2) * size;
	swap(pleft,pkey,size);
	int last = start;
	char *plast = (char *)base + last * size;
	for(int i = start + 1;i <= end; ++i)
	{
		char *pi = (char *)base + i * size;
		if(cmp(pi,pleft) < 0)
		{
			++last;
			plast = (char *)base + last * size;
			swap(pi,plast,size);
		}
	}
	q_sort(base,start,last - 1,size,cmp);
	q_sort(base,last + 1,end,size,cmp);
}
//选择排序
void select_sort(void *base,int start,int end,int size,int (*cmp)(const void *a,const void *b))
{
	int i;

	for(i = start; i <= end; i++)
	{
		char *min = (char *)base + i * size;
		for(int j = i + 1; j <= end; j++)
		{
			char *current = (char *)base + j * size;
			if(cmp(current,min) < 0)
			{
				min = current;
			}
		}
		char *data = (char *)base + i * size;
		swap(data,min,size);
	}

}
//插入排序
void insert_sort(void *base,int start,int end,int size,int (*cmp)(const void *a,const void *b))
{
	int i,j;
	for(i = start + 1; i <= end;i++)
	{
		for(j = i; j > 0; j--)
		{
			char *prev = (char *)base + (j-1) * size;
			char *after = (char *)base + j * size;
			if(cmp(prev,after) > 0)
			{
				swap(prev,after,size);
			}
		}
	}
}
//希尔排序
void shell_sort(void *a,int start,int end,int size,int (*cmp)(const void *a,const void *b))
{
	int h = 1;
	int length = end - start + 1;
	while(h < length / 3)
	{
		h = 3 *h + 1;
	}
	while(h >= 1)
	{
		//将数组变为h有序
		for(int i = start;i <= end;i++)
		{
			//将a[i]插入到a[i-h],a[i-2*h] a[i-3*h]...之中
			for(int j = i;j >= h;j-=h)
			{
				char *prev = (char *)a + (j - h) * size;
				char *after = (char *)a + j * size;
				if(cmp(prev,after) > 0)
				{
					swap(prev,after,size);
				}
			}
		}
		h = h / 3;
	}
}

// void merge(void *a,int lo,int mid,int hi,int size,int (*cmp)(const void *a,const void *b))
// {
// 	printf("%s:%d merge(%d,%d,%d)\n",__FILE__,__LINE__,lo,mid,hi);
// 	//将a[lo .. mid] 和 a[mid+1 .. hi]归并
// 	int i = lo;
// 	int j = mid + 1;
//
// 	// char  *pd = (char *)data;
// 	printf("---------0\n");
// 	void  *aux = (void *)malloc((hi - lo + 1) * size);
// 	printf("---------\n");
// 	// if(aux == NULL)
// 	// {
// 	// 	printf("malloc error!!\n");
// 	// 	return;
// 	// }
// 	// void *buffer = (void *)malloc(size);
// 	for(int k = lo; k <= hi; k++)
// 	{
// 		//将a[lo .. hi]复制到aux[lo .. hi]中
// 		char *aux_data = (char *)aux + k * size;
// 		char *a_data = (char *)a + k * size;
// 		memcpy(aux_data,a_data,size);
// 	}
// 	for(int k = lo;k <= hi;k++)
// 	{
//
// 		char *a_data = (char *)a + k * size;
// 		char *jtmp = (char *)aux + j * size;
// 		char *itmp = (char *)aux + i * size;
// 		if(i > mid)
// 		{
// 			memcpy(a_data,jtmp,size);
// 			j++;
// 		}
// 		else if(j > hi)
// 		{
// 			memcpy(a_data,itmp,size);
// 			i++;
// 		}
// 		else if(cmp(jtmp,itmp) < 0)
// 		{
// 			memcpy(a_data,jtmp,size);
// 			j++;
// 		}
// 		else
// 		{
// 			memcpy(a_data,itmp,size);
// 			i++;
// 		}
// 	}
//
// 	free(aux);
//
// 	printf("%s:%d merge...end\n",__FILE__,__LINE__);
// }
void merge(void *data,int lpos,int dpos,int rpos,int esize,int (*cmp)(const void *a,const void *b))
{
	printf("%s:%d merge(%d,%d,%d)\n",__FILE__,__LINE__,lpos,dpos,rpos);

	char*   pd = (char*)data;
    char*   m;
    int pl, pr, pm;

    /* 初始化指示器 */
    pl = lpos;          /* pl指向分割后的左分区 */
    pr = dpos + 1;      /* pr指向分割后的右分区 */
    pm = 0;             /* pm指向合并后的分区 */

    /* 分配归并后结果的存储空间 */
    if((m = (char*)malloc((rpos - lpos + 1) * esize)) == NULL)
        return ;

    /* 两个区间中仍然有需要合并的元素 */
    while(pl <= dpos || pr <= rpos)
    {
        if(pl > dpos)
        {
            /* 左分区元素已经全部合并 */
            while(pr <= rpos)               /* 此时将右分区剩下的元素全部接在m的后边 */
            {
                memcpy(&m[pm * esize], &pd[pr * esize], esize);
                pr++;
                pm++;
            }
            continue;
        }
        else if(pr > rpos)
        {
            /* 右分区元素已经全部合并 */
            while(pl <= dpos)               /* 此时将左分区剩下的元素全部接在m的后边 */
            {
                memcpy(&m[pm * esize], &pd[pl * esize], esize);
                pl++;
                pm++;
            }
            continue;
        }

        /* 将下一个有序集合添加到合并结果中 */
        if(cmp(&pd[pl * esize], &pd[pr * esize]) < 0)
        {
            memcpy(&m[pm * esize], &pd[pl * esize], esize);
            pl++;
            pm++;
        }
        else
        {
            memcpy(&m[pm * esize], &pd[pr * esize], esize);
            pr++;
            pm++;
        }
    }

    /* 复制合并结果到data中，然后释放m */
    memcpy(&pd[lpos * esize], m, (rpos - lpos + 1) * esize);

    /* 释放空间 */
    free(m);
}
void merge_sort(void *a,int lo,int hi,int size,int (*cmp)(const void *a,const void *b))
{
	//printf("%s:%d merge_sort(%d,%d)\n",__FILE__,__LINE__,lo,hi);
	int mid;

	if(hi <= lo)
	{
		return;
	}

	/*计算中间位置*/
	mid = lo + (hi - lo) / 2;
	/*递归进行对左分区进行归并排序*/
	merge_sort(a,lo,mid,size,cmp);
	merge_sort(a,mid+1,hi,size,cmp);
	merge(a,lo,mid,hi,size,cmp);
}

int cmp_int(const void *a,const void *b)
{
	assert(a != NULL && b != NULL);
	const int * lhs = (const int *)a;
	const int * rhs = (const int *)b;

	if(*lhs < *rhs)
	{
		return -1;
	}
	else if(*lhs == *rhs)
	{
		return 0;
	}
	else
	{
		return 1;
	}
	//return (*(int *)a - *(int *)b);

}
int cmp_double(const void *a,const void *b)
{
	assert(a != NULL && b != NULL);
	const double * lhs = (const double *)a;
	const double * rhs = (const double *)b;

	if(*lhs < *rhs)
	{
		return -1;
	}
	else if(*lhs == *rhs)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int cmp_char(const void *a,const void *b)
{
	assert(a != NULL && b != NULL);
	const char * lhs = (const char *)a;
	const char * rhs = (const char *)b;

	if(*lhs < *rhs)
	{
		return -1;
	}
	else if(*lhs == *rhs)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int  cmp_string(const void *a,const void *b)
{
	assert(a != NULL && b != NULL);
	const char ** lhs = (const char **)a;
	const char ** rhs = (const char **)b;

	return strcmp(*lhs,*rhs);
}
