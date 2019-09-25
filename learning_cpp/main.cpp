#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include "9_21.h"

using namespace std;

int main()
{
	//string s;
	//getline(cin, s);
	//vector<string> result;
	//int i = 0;
	//while(i < s.length())
	//{
	//	char* word = "";
	//	while (s[i] != ' ' && i<s.length());
	//	{
	//		word += s[i++];
	//	}
	//	result.push_back(word);
	//	i++;
	//}
	////从后遍历出result容器
	//vector<string>::reverse_iterator iter = result.rbegin();
	//for (; iter != result.rend(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	test_921();
}

/*
9_03:函数包装器和function类
9_04:可变参数模版函数,高度泛化(可变参数模版类那部分还没有理解)
9_06:写了可变参数模板函数的两种展开方式(复习9_04的内容)和简单的lambda表达式
9_19:设计模式，观察者模式，单例模式（没有代码实现）和工厂模式(没有代码实现）
9_20:stl的一些知识
9_21:常见的排序算法
*/