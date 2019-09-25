#include "9_21.h"
#include <vector>
#include <iostream>

using namespace std;

//��������
static void swap(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

//ð������
static void bubbleSort(vector<int> &a)
{
	int size = a.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1 ; j++)
		{
			if (a[j] > a[j+1])
			{
				//����
				swap(a[j], a[j + 1]);
			}
		}
	}
}

//ѡ������
static void selectSort(vector<int> &a)
{
	int size = a.size();
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)  //ǰi��Ԫ���Ѿ��ź���,�ӵ�i+1��Ԫ�ؿ�ʼ������,��a[i+1]���򽻻�Ԫ��
		{
			if (a[j] < a[i+1])
			{
				swap(a[j], a[i+1]);
			}
		}
	}
}

//��������
static void insertSort(vector<int> &a)
{
	int size = a.size();
	for (int i = 0; i < size - 1; i++)
	{
		int j = i;
		int temp = a[i + 1];  //����tempΪa[i+1],Ȼ����ǰѰ��<temp���±꣬Ȼ�����
		while (j >= 0 && a[j] > temp)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = temp; //ע��������a[j+1]������a[j]
	}
}

//�������򣨰�������������
static int partition(vector<int> &a, int left, int right) //�����з�Ϊ���������У����������ź��򲢷���midֵ
{
	int pivot = a[right];  //���û�׼ֵpivot
	int i = left;
	int j = right;
	while (i < j)
	{
		while (a[i] <= pivot && i < j) //����������ǵ�Ҫ����i<j
		{
			i++;
		}
		//���������ʾa[i]>pivot,��Ҫ����λ��
		a[j] = a[i];
		a[i] = pivot;
		while (a[j] >= pivot && i < j)
		{
			j--;
		}
		//���������ʾa[j]<pivot,�轻��λ��
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
	if (left < right) //��left<rightʱ,�ݹ����quickSort���������зֱ��������
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

//�鲢����(����ƽ��O(nlongn),�O(n^2),���鲢����ʱ�临�Ӷ�һֱ��O(nlogn)
//���ӣ�http://www.voidcn.com/article/p-gwqluxvb-ed.html
static void merge(vector<int> &a, int start, int mid, int end)  //������������ѡ��С��Ԫ�طŵ��¿��ٵ�������
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
	//�����кõ�tmp�ƶ���ԭ����a�Ķ�Ӧλ����
	for (int k = 0; k < tmp.size(); k++)
	{
		a[start + k] = tmp[k];
	}
}
static void mergeSort(vector<int> &a, int start, int end)  //�ݹ����,����mergeSort,���merge
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		mergeSort(a, start, mid);
		mergeSort(a, mid + 1, end);
		merge(a, start, mid, end);     
	}
}

//��������(�ǱȽ���),�������ǰ��Ϊ������Ԫ�ط�ΧΪ(a,b),��a�����Ǹ���,b-aԽ��,��ռ临�Ӷ�Խ��
static void countSort(vector<int> &a)
{
	int size = a.size();
	//�ҵ����ֵ����Сֵ
	int min = a[0];
	int max = a[0];
	for (int i = 0; i < size; i++)
	{
		if (a[i] < min) min = a[i];
		if (a[i] > max) max = a[i];
	}
	//����һ������Ϊmax-min+1������,������int [max-min+1],��Ϊ���鲻���ò�ȷ���ĳ���,ֻ����vector
	vector<int> tmp(max-min+1, 0);
	//����ƫ��bias,��Ϊ���Ǵ�0��ʼ�洢����Ҫ����Ԫ��ӳ��
	int bias = 0 - min;
	//������ĸ���Ԫ�ؼ���
	for (int i = 0; i < size; i++)
	{
		tmp[a[i] + bias] ++;
	}
	//����tmp��дԭ����a
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