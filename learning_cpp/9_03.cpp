#include <iostream>
#include <functional>

using std::cout;
using std::endl;
using std::function;

//������װ����һ����������һ������ָ�����һ��
//question1. ģ�嶨�巵��ֵ���͵����⣺�����·���ģ�壬����ֵ���ͱ�����ģ���ж������͵�����һ��(������������ʧ��������ô��?)

static int count = 0;

//��������������װ��
template<typename T, typename F>
static T run(T t, F fun)
{
	//ʵ�ּ���
	count++;
	cout << "��" << count << "�ε��ú���" << endl;
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
	//ʹ��lambda���ʽ,����һ������double,��������double������function<double(double,double)>��
	function<double(double, double)> fun1 = [](double x, double y) {return x*y; };
	//ʹ���ⲿ�ĺ���,��ʼ��һ��function��
	function<double(double)> fun2 = fun;

	//����,ǰ������function��fun1,��fun2����
	cout << run(a, fun2) << endl;
	cout << run(a, b, fun1) << endl;
	//����,ֱ�����ⲿ����fun����run��װ�����е���
	//question2:����ֱ����fun,ת����function���������ʲô?
	cout << run(a, fun) << endl;
}