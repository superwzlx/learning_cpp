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
9_03:������װ����function��
9_04:�ɱ����ģ�溯��,�߶ȷ���(�ɱ����ģ�����ǲ��ֻ�û�����)
9_06:д�˿ɱ����ģ�庯��������չ����ʽ(��ϰ9_04������)�ͼ򵥵�lambda���ʽ
9_19:���ģʽ���۲���ģʽ������ģʽ��û�д���ʵ�֣��͹���ģʽ(û�д���ʵ�֣�
9_20:
*/