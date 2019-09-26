#include "9_25.h"
#include <iostream>
#include <vector>
#include <io.h>
#include <string>

using namespace std;

static void getFilesName(const string path, vector<string> &files, bool recursion = false)
{
	_finddata_t fileInfo;   //_finddata_t类,存放文件信息
	long long hFile = 0;    //文件句柄,用long long类型
	string p;

	//_findfirst第一个参数需要使用c_str()转换为char *,接下来使用_findnext往下遍历,    != -1是他们两个函数有查找到文件的条件.
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileInfo)) != -1) {
		do  //使用do...while(),先执行,后判断
		{
			if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0)
			{
				//如果是目录
				if (fileInfo.attrib & _A_SUBDIR)  //位运算,_A_SUBDIR是attrib的属性值之一
				{
					if (recursion) //需要递归
					{
						getFilesName(p.assign(path).append("\\").append(fileInfo.name), files, true);
					}
					else //不需要递归
					{
						files.push_back(p.assign(path).append("\\").append(fileInfo.name));
					}
				}
				else //如果是文件
				{
					files.push_back(p.assign(path).append("\\").append(fileInfo.name));
				}
			}
		} while (_findnext(hFile, &fileInfo) != -1);
		_findclose(hFile);   //使用_findclose()关闭文件句柄
	}
}

void test_925()
{
	string path = "D:\\Git";
	vector<string> files;
	getFilesName(path, files, false);
	cout << files.size() << endl;
	for (int i = 0; i < files.size(); i++)
	{
		cout << files[i] << endl;
	}
}