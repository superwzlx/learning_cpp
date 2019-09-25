#include "9_20.h"
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#include <list>
#include <deque>

using namespace std;

void test_920()
{
	//set
	set<string> setStudent;
	setStudent.insert("liming");
	setStudent.insert("liming2");
	set<string>::iterator iter1 = setStudent.begin();
	//����set
	for (; iter1 != setStudent.end(); iter1++)
	{
		cout << *iter1 << endl;
	}
	//����
	if (setStudent.find("xiaoming") != setStudent.end())  //���Һ���find�Ƿ���һ��������iter,����õ���������end(),���ʾû�ҵ�
	{
		cout << "Element has been found!" << endl;
	}
	else
	{
		cout << "Element not found in the set!" << endl;
	}
	//map
	map<int, string> mapStudent;
	mapStudent.insert(pair<int, string>(1, "liming"));
	mapStudent.insert(pair<int, string>(2, "liming"));
	mapStudent.insert(pair<int, string>(3, "liming"));
	map<int, string>::reverse_iterator iter = mapStudent.rbegin();
	//����map
	for (; iter != mapStudent.rend(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
	//vector
	//����resize������reserve����
	vector<string> vecStudent;
	vecStudent.push_back("liming1");
	vecStudent.push_back("liming2");
	vecStudent.push_back("liming3");
	vecStudent.reserve(2);
	cout << vecStudent.size() << " " << vecStudent.capacity() << endl;
	vector<string>::iterator iter2 = vecStudent.begin();
	for (; iter2 != vecStudent.end(); iter2++)
	{
		cout << *iter2 << endl;
	}
}