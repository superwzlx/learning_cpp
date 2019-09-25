#pragma once
#include <string>
#include <list>
using std::string;
using std::list;

//观察者模式,以博客订阅为例子，博客订阅者为观察者，博主为被观察者

//下面定义观察者和博主的基类和接口
class Observer
{
public:
	Observer() {};
	virtual ~Observer() {};
	virtual void Update() {};
};

class Blog
{
private:
	list<Observer*> m_observers; //观察者列表
protected:
	string m_status; //状态
public:
	Blog() {};
	virtual ~Blog() {};
	void Attach(Observer *observer); //添加观察者
	void Remove(Observer *observer); //删除观察者
	void Notify(); //通知观察者
	virtual void SetStatus(string s) {	m_status = s;} //设置状态
	virtual string GetStatus() { return m_status; }; //获得状态
};

//下面定义具体的子类，继承于上面的基类
class BlogCSDN :public Blog
{
private:
	string m_name; //博主名称
public:
	BlogCSDN(string s):m_name(s) {};
	~BlogCSDN() {};
	string GetName() { return m_name; };
	//设置和获取动态基类已经实现,这里不再实现
};

class ObserverBlog :public Observer
{
private:
	string m_name; //观察者名称
	BlogCSDN *m_blog; //观察者的博客,设置成列表更好,可以关注多个博客的状态
public:
	ObserverBlog(string s,BlogCSDN *blog):m_name(s),m_blog(blog) {};
	~ObserverBlog() {};
	void Update(); //获得更新动态
};

void test_919();