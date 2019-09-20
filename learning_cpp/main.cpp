#include <iostream>
#include <thread>
#include "9_19.h"
#include <iostream>
using std::cout;
using std::endl;

void fun()
{
	static int n = 10;
}

int main()
{
	test_919();
}

/*
9_03:函数包装器和function类
9_04:可变参数模版函数,高度泛化(可变参数模版类那部分还没有理解)
9_06:写了可变参数模板函数的两种展开方式(复习9_04的内容)和简单的lambda表达式
9_19:设计模式，观察者模式，单例模式（没有代码实现）和工厂模式(没有代码实现）
9_20:
*/