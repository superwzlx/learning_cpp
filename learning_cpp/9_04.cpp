#include <iostream>
#include "9_04.h"

using std::cout;
using std::cin;
using std::endl;

//重载一个终止递归函数
static void print()
{
	cout << "empty" << endl;
}

template<class T,class... Args>	//Args为模版参数包
//递归展开参数
static void print(T t, Args... args)	//args为函数参数包
{
	cout << t << endl;
	cout << "剩余的函数参数个数" << sizeof...(args) << endl;  //这里sizeof...(args)获取参数的size
	print(args...);	//args...,记得不要忽略掉省略号
}



//逗号表达式展开参数
template<class T>
static void print(T t)
{
	cout << t << endl;
}

template<class... Args>	
static void expand(Args... args)	//展开参数的函数,print是处理参数的函数
{
	//args表示单个参数,args...表示整个参数包,但是这个的...加在逗号表达式后面,不是很懂!
	int arr[] = { (print(args),0)... };	//这里的数组只是单纯地被借助来展开参数,arr是值为0,大小为sizeof...(args)的数组!
}



void test_94()
{
	print(1, 2, 3, 4, 'a');
}