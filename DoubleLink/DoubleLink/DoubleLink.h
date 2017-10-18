#pragma once

template<class T>
struct CNode
{
public:
	CNode(){};
	CNode(T t, CNode* pre, CNode* nxt)
	{
		value = t;
		prev = pre;
		next = nxt;
	}
	~CNode(){};

public:
	T value;
	CNode * prev;
	CNode * next;

};

template<class T>
class CDoubleLink
{
public:
	CDoubleLink();
	~CDoubleLink();

	int size();
	void insert(int index, T value);
	int del(int index);
	T get(int index);
	
private:
	CNode<T>* getNode(int index);

	CNode<T>* phead;
	int length;
};