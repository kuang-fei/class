#include"DoubleLink.h"

template<class T>
CDoubleLink<T>::CDoubleLink() :length(0)
{
	phead = new CNode<T>();
	phead->prev = phead;
	phead->next = phead;
}
template<class T>
CDoubleLink<T>::~CDoubleLink()
{
	CNode<T>* pindex = phead;
	CNode<T>* ptemp;
	while (pindex != nullptr)
	{
		ptemp = pindex;
		pindex = pindex->next;
		delete ptemp;
		ptemp = nullptr;
	}
}

template<class T>
int CDoubleLink<T>::size()
{
	return length;
}

template <class T>
void CDoubleLink<T>::insert(int index, T value)
{
	if (index< 0 || index > length)
	{
		cout << "index out of size" << endl;
	}
	CNode<T>* pIndex = getNode(index);
	CNode<T>* pNewNode = new CNode<T>(value, pIndex->prev, pIndex);
	pIndex->prev->next = pNewNode;
	pIndex->prev = pNewNode;

	length++;
}

template<class T>
int CDoubleLink<T>::del(int index)
{
	if (index< 0 || index > length)
	{
		cout << "index out of size" << endl;
	}
	CNode<T>* pIndex = getNode(index);
	pIndex->prev->next = pIndex->next;
	pIndex->next->prev = pIndex->prev;
	delete pIndex;
	pIndex = nullptr;
}

template<class T>
T CDoubleLink<T>::get(int index)
{
	if (index< 0 || index > length)
	{
		cout << "index out of size" << endl;
	}
	CNode<T>* pIndex = getNode(index);
	return pIndex->value;
}

template<class T>
CNode<T>* CDoubleLink<T>::getNode(int index)
{

	if (index< 0 || index > length)
	{
		cout << "index out of size" << endl;
	}

	
	if (index < length / 2)
	{
		CNode<T>* pIndex = phead;
		while (index--  > 0)
		{
			pIndex = pIndex->next;
		}
		return pIndex;
	}
	else
	{
		CNode<T>* pIndex = phead->prev;
		while (length - ++index > 0)
		{
			pIndex = pIndex->prev;
		}
		return pIndex;
	}
}