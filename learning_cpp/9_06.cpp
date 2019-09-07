#include <iostream>
#include "9_06.h"

using std::cout;
using std::cin;
using std::endl;

template<class... Args>
static void fun1(Args... args)
{
	cout << sizeof...(args) << endl;
}

static void fun2()
{
	cout << "empty" << endl;
}

template<class T,class... Args>
static void fun2(T t, Args... args)
{
	cout << t << endl;
	fun2(args...);
}

template<class T>
static void fun3(T t)
{
	cout << t << endl;
}

template<class... Args>
static void fun4(Args... args)
{
	int arr[] = { (fun3(args),0)... }; 
}

void test_96()
{
	cout << sizeof(std::string) << endl;
}