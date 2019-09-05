#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;

//函数包装器：一个函数接受一个函数指针调用一下
//question1. 模板定义返回值类型的问题：例如下方的模板，返回值类型必须是模版中定义类型的其中一种(那这样精度损失的问题怎么办?)

static int count = 0;

//重载两个函数包装器
template<typename T, typename F>
static T run(T t, F fun)
{
	//实现计数
	count++;
	cout << "第" << count << "次调用函数" << endl;
	return fun(t);
}

template<typename T, typename F>
static T run(T t1, T t2, F fun)
{
	return fun(t1, t2);
}

static double fun(double x)
{
	return x*x;
}

void test_93()
{
	double a = 9.8;
	double b = 9;
	//使用lambda表达式,定义一个返回double,接受两个double参数的function<double(double,double)>类
	function<double(double, double)> fun1 = [](double x, double y) {return x*y; };
	//使用外部的函数,初始化一个function类
	function<double(double)> fun2 = fun;

	//调用,前两个用function类fun1,和fun2传参
	cout << run(a, fun2) << endl;
	cout << run(a, b, fun1) << endl;
	//调用,直接用外部函数fun传入run包装器进行调用
	//question2:可以直接用fun,转换成function类的意义是什么?
	cout << run(a, fun) << endl;
}