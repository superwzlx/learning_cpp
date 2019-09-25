#include "9_21.h"
#include <vector>
#include <iostream>

using namespace std;

//交换函数
static void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//冒泡排序
static void bubbleSort(vector<int> &a)
{
	int size = a.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1 ; j++)
		{
			if (a[j] > a[j+1])
			{
				//交换
				swap(a[j], a[j + 1]);
			}
		}
	}
}

//选择排序
static void selectSort(vector<int> &a)
{
	int size = a.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)  //前i个元素已经排好序,从第i+1个元素开始往后找,比a[i+1]大则交换元素
		{
			if (a[j] < a[i+1])
			{
				swap(a[j], a[i+1]);
			}
		}
	}
}

//插入排序
static void insertSort(vector<int> &a)
{
	int size = a.size();
	for (int i = 0; i < size - 1; i++)
	{
		int j = i;
		int temp = a[i + 1];  //设置temp为a[i+1],然后向前寻找<temp的下标，然后插入
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp; //注意这里是a[j+1]而不是a[j]
	}
}

//快速排序（包含三个函数）
static int partition(vector<int> &a, int left, int right) //将序列分为两个子序列，各个序列排好序并返回mid值
{
	int pivot = a[right];  //设置基准值pivot
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] <= pivot && i < j) //这里的条件记得要带上i<j
		{
			i++;
		}
		//来到这里表示a[i]>pivot,需要交换位置
		a[j] = a[i];
		a[i] = pivot;
		while (a[j] >= pivot && i < j)
		{
			j--;
		}
		//来到这里表示a[j]<pivot,需交换位置
		a[i] = a[j];
		a[j] = pivot;
	}
	if (a[i] = pivot)
	{
		return i;
	}
	else {
		return j;
	}
}
static void quickSort(vector<int> &a, int left, int right)
{
	if (left < right) //当left<right时,递归调用quickSort对左右序列分别进行排序
	{
		int mid = partition(a, left, right);
		quickSort(a, left, mid - 1);
		quickSort(a, mid + 1, right);
	}
}
static void qSort(vector<int> &a)
{
	quickSort(a, 0, a.size() - 1);
}

//归并排序(快排平均O(nlongn),最坏O(n^2),而归并排序时间复杂度一直是O(nlogn)
//链接：http://www.voidcn.com/article/p-gwqluxvb-ed.html
static void merge(vector<int> &a, int start, int mid, int end)  //对左右两部分选择小的元素放到新开辟的数组中
{
	vector<int> tmp;      
	int i = start;
	int j = mid + 1;
	while (i <= mid && j <= end)
	{
		if (a[i] < a[j])
		{
			tmp.push_back(a[i++]);
		}
		else {
			tmp.push_back(a[j++]);
		}
	}
	while (i <= mid)
	{
		tmp.push_back(a[i++]);
	}
	while (j <= end)
	{
		tmp.push_back(a[j++]);
	}
	//将排列好的tmp移动到原数组a的对应位置中
	for (int k = 0; k < tmp.size(); k++)
	{
		a[start + k] = tmp[k];
	}
}
static void mergeSort(vector<int> &a, int start, int end)  //递归调用,左右mergeSort,最后merge
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(a, start, mid);
		mergeSort(a, mid + 1, end);
		merge(a, start, mid, end);     
	}
}

//计数排序(非比较型),该排序的前提为：数组元素范围为(a,b),且a不能是负数,b-a越大,则空间复杂度越大
static void countSort(vector<int> &a)
{
	int size = a.size();
	//找到最大值和最小值
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] < min) min = a[i];
		if (a[i] > max) max = a[i];
	}
	//开辟一个长度为max-min+1的数组,不能用int [max-min+1],因为数组不能用不确定的长度,只能用vector
	vector<int> tmp(max-min+1, 0);
	//计算偏差bias,因为我们从0开始存储，需要进行元素映射
	int bias = 0 - min;
	//对数组的各个元素计数
	for (int i = 0; i < size; i++)
	{
		tmp[a[i] + bias] ++;
	}
	//根据tmp重写原数组a
	int index = 0;
	for (int i = 0; i < tmp.size(); i++)
	{
		while(tmp[i])
		{
			a[index] = i - bias;
			index++;
			tmp[i]--;
		}
	}
}

void test_921()
{
	vector<int> a = { 1,28,3,8,45,23,10,22,9,3 };
	countSort(a);
	for (int i = 0; i < a.size(); i++)
	{
		cout << a[i] << " ";
	}
}