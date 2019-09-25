#include "9_19.h"
#include <iostream>
using std::cout;
using std::endl;
void Blog::Attach(Observer * observer)
{
	m_observers.push_back(observer);
}

void Blog::Remove(Observer * observer)
{
	m_observers.remove(observer);
}

void Blog::Notify()
{
	list<Observer*>::iterator iter = m_observers.begin();
	for (; iter != m_observers.end(); iter++)
	{
		(*iter)->Update();       //iter��ָ��,�ǵô��Ͻ��������*�õ�����
	}
}

void ObserverBlog::Update()
{
	string status = m_blog->GetStatus();
	cout << m_blog->GetName() << "�����˶�̬: " << m_blog->GetStatus() << endl;
}

void test_919()
{
	BlogCSDN *blog = new BlogCSDN("����123");
	Observer *observer1 = new ObserverBlog("�۲���1",blog);
	blog->Attach(observer1);
	blog->SetStatus("2019.09.19�����һ�θ���");
	blog->Notify();
	delete blog;
	delete observer1;
}