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
	////�Ӻ������result����
	//vector<string>::reverse_iterator iter = result.rbegin();
	//for (; iter != result.rend(); iter++)
	//{
	//	cout << *iter << " ";
	//}
	test_921();
}

/*
9_03:������װ����function��
9_04:�ɱ����ģ�溯��,�߶ȷ���(�ɱ����ģ�����ǲ��ֻ�û�����)
9_06:д�˿ɱ����ģ�庯��������չ����ʽ(��ϰ9_04������)�ͼ򵥵�lambda���ʽ
9_19:���ģʽ���۲���ģʽ������ģʽ��û�д���ʵ�֣��͹���ģʽ(û�д���ʵ�֣�
9_20:stl��һЩ֪ʶ
9_21:�����������㷨
*/