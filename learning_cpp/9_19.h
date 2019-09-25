#pragma once
#include <string>
#include <list>
using std::string;
using std::list;

//�۲���ģʽ,�Բ��Ͷ���Ϊ���ӣ����Ͷ�����Ϊ�۲��ߣ�����Ϊ���۲���

//���涨��۲��ߺͲ����Ļ���ͽӿ�
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
	list<Observer*> m_observers; //�۲����б�
protected:
	string m_status; //״̬
public:
	Blog() {};
	virtual ~Blog() {};
	void Attach(Observer *observer); //��ӹ۲���
	void Remove(Observer *observer); //ɾ���۲���
	void Notify(); //֪ͨ�۲���
	virtual void SetStatus(string s) {	m_status = s;} //����״̬
	virtual string GetStatus() { return m_status; }; //���״̬
};

//���涨���������࣬�̳�������Ļ���
class BlogCSDN :public Blog
{
private:
	string m_name; //��������
public:
	BlogCSDN(string s):m_name(s) {};
	~BlogCSDN() {};
	string GetName() { return m_name; };
	//���úͻ�ȡ��̬�����Ѿ�ʵ��,���ﲻ��ʵ��
};

class ObserverBlog :public Observer
{
private:
	string m_name; //�۲�������
	BlogCSDN *m_blog; //�۲��ߵĲ���,���ó��б����,���Թ�ע������͵�״̬
public:
	ObserverBlog(string s,BlogCSDN *blog):m_name(s),m_blog(blog) {};
	~ObserverBlog() {};
	void Update(); //��ø��¶�̬
};

void test_919();