#include "���� 9_25.h"
#include <iostream>
#include <vector>
#include <io.h> 
#include <string>
//linux��,�ǵ���<dirent.h>,linux�е�ʵ�ָ�windows��˼·���
//��struct dirent *dirp����_finddata_t fileInfo,dirp->d_name��dirp->d_type(�ļ�����,�ж���Ŀ¼�����ļ�
//ʹ��DIR *dp,�ļ�Ŀ¼ָ��,dp = opendir(dirname.c_str())
//Ȼ��dirp = readdir(dp),һ�ζ�ȡһ���ļ���


using namespace std;

static void getFilesName(const string path, vector<string> &files, bool recursion = false)
{
	_finddata_t fileInfo;   //_finddata_t��,����ļ���Ϣ
	long long hFile = 0;    //�ļ����,��long long����
	string p;

	//_findfirst��һ��������Ҫʹ��c_str()ת��Ϊchar *,������ʹ��_findnext���±���,    != -1���������������в��ҵ��ļ�������.
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileInfo)) != -1) {
		do  //ʹ��do...while(),��ִ��,���ж�
		{
			if (strcmp(fileInfo.name, ".") != 0 && strcmp(fileInfo.name, "..") != 0)
			{
				//�����Ŀ¼
				if (fileInfo.attrib & _A_SUBDIR)  //λ����,_A_SUBDIR��attrib������ֵ֮һ
				{
					if (recursion) //��Ҫ�ݹ�
					{
						getFilesName(p.assign(path).append("\\").append(fileInfo.name), files, true);
					}
					else //����Ҫ�ݹ�
					{
						files.push_back(p.assign(path).append("\\").append(fileInfo.name));
					}
				}
				else //������ļ�
				{
					files.push_back(p.assign(path).append("\\").append(fileInfo.name));
				}
			}
		} while (_findnext(hFile, &fileInfo) != -1);
		_findclose(hFile);   //ʹ��_findclose()�ر��ļ����
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