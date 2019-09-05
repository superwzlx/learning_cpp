#include <iostream>
#include "9_04.h"

using std::cout;
using std::cin;
using std::endl;

//����һ����ֹ�ݹ麯��
static void print()
{
	cout << "empty" << endl;
}

template<class T,class... Args>	//ArgsΪģ�������
//�ݹ�չ������
static void print(T t, Args... args)	//argsΪ����������
{
	cout << t << endl;
	cout << "ʣ��ĺ�����������" << sizeof...(args) << endl;  //����sizeof...(args)��ȡ������size
	print(args...);	//args...,�ǵò�Ҫ���Ե�ʡ�Ժ�
}



//���ű��ʽչ������
template<class T>
static void print(T t)
{
	cout << t << endl;
}

template<class... Args>	
static void expand(Args... args)	//չ�������ĺ���,print�Ǵ�������ĺ���
{
	//args��ʾ��������,args...��ʾ����������,���������...���ڶ��ű��ʽ����,���Ǻܶ�!
	int arr[] = { (print(args),0)... };	//���������ֻ�ǵ����ر�������չ������,arr��ֵΪ0,��СΪsizeof...(args)������!
}



void test_94()
{
	print(1, 2, 3, 4, 'a');
}