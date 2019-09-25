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
		(*iter)->Update();       //iter是指针,记得带上解运算符号*得到对象
	}
}

void ObserverBlog::Update()
{
	string status = m_blog->GetStatus();
	cout << m_blog->GetName() << "更新了动态: " << m_blog->GetStatus() << endl;
}

void test_919()
{
	BlogCSDN *blog = new BlogCSDN("博主123");
	Observer *observer1 = new ObserverBlog("观察者1",blog);
	blog->Attach(observer1);
	blog->SetStatus("2019.09.19添加了一次更新");
	blog->Notify();
	delete blog;
	delete observer1;
}