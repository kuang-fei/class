#include <iostream>
#include "DoubleLink.h"
#include"DoubleLink.cpp"
using namespace std;

// 双向链表操作int数据
void int_test()
{
	int iarr[4] = { 10, 20, 30, 40 };

	cout << "\n----int_test----" << endl;
	// 创建双向链表
	CDoubleLink<int>* pdlink = new CDoubleLink<int>();

	pdlink->insert(0, 20);      
	cout << "size()=" << pdlink->size() << endl;

	// 打印双向链表中的数据
	int sz = pdlink->size();
	for (int i = 0; i<sz; i++)
		cout << "pdlink(" << i << ")=" << pdlink->get(i) << endl;
}

void string_test()
{
	string sarr[4] = { "ten", "twenty", "thirty", "forty" };

	cout << "\n----string_test----" << endl;
	// 创建双向链表
	CDoubleLink<string>* pdlink = new CDoubleLink<string>();

	pdlink->insert(0, sarr[1]);        

	cout << "size()=" << pdlink->size() << endl;

	// 打印双向链表中的数据
	int sz = pdlink->size();
	for (int i = 0; i < sz; i++)
	{
		string str = pdlink->get(i);
		cout << "pdlink(" << i << ")=" << str.c_str() << endl;
	}
}

struct stu
{
	int id;
	char name[20];
};

static stu arr_stu[] =
{
	{ 10, "sky" },
	{ 20, "jody" },
	{ 30, "vic" },
	{ 40, "dan" },
};
#define ARR_STU_SIZE ( (sizeof(arr_stu)) / (sizeof(arr_stu[0])) )

void object_test()
{
	cout << "\n----object_test----" << endl;
	// 创建双向链表
	CDoubleLink<stu>* pdlink = new CDoubleLink<stu>();

	pdlink->insert(0, arr_stu[1]);       

	cout << "size()=" << pdlink->size() << endl;

	// 打印双向链表中的数据
	int sz = pdlink->size();
	struct stu p;
	for (int i = 0; i<sz; i++)
	{
		p = pdlink->get(i);
		cout << "pdlink(" << i << ")=[" << p.id << ", " << p.name << "]" << endl;
	}
}


int main()
{
	int_test();        // 演示向双向链表操作“int数据”。
	string_test();    // 演示向双向链表操作“字符串数据”。
	object_test();    // 演示向双向链表操作“对象”。

	system("pause");
	return 0;
}