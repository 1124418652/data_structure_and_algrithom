#pragma once
#include <iostream>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

using namespace std;

template<class ElemType>
class SqList
{
	ElemType *elem;
	int length;                   // 当前线性表的长度
	int listSize;                 // 线性表的大小

public:
	/* 构造函数中进行线性表初始化，构造一个空表 */
	SqList();  
	/* 构造一个长度为 n 的线性表 */
	SqList(const ElemType *, int n);    
	~SqList();
	/* 友元函数不属于类，所以不能和类共用模板定义 */
	template<typename T>          
	friend ostream& operator<<(ostream& out, const SqList<T>& sqlist);
	int getLength() { return length; }
	void insert(const ElemType x, int location);
	ElemType delElem(int location);
	void set(ElemType x, int location);
	ElemType get(int location);
};

template<class ElemType>
SqList<ElemType>::SqList()
{
	elem = new ElemType[LIST_INIT_SIZE];           // 动态内存分配
	length = 0;
	listSize = LIST_INIT_SIZE;
	cout << "create the SqList" << endl;
}

template<class ElemType>
SqList<ElemType>::SqList(const ElemType *list, int n)
{
	listSize = LIST_INIT_SIZE;

	while (n > listSize)
	{
		listSize += LISTINCREMENT;
	}

	elem = new ElemType[listSize];

	for (int i = 0; i < n; i++)
	{
		elem[i] = list[i];
	}
	length = n;
	cout << "create the SqList" << endl;
}

template<class ElemType>
SqList<ElemType>::~SqList()
{
	delete[] elem;
	cout << "Free the memory of current SqList!" << endl;
}

template<typename T>
ostream& operator<<(ostream& out, const SqList<T>& sqlist)
{
	cout << "The list:";
	out << '[';
	for (int i = 0; i < sqlist.length - 1; i++)
		out << sqlist.elem[i] << ',';
	out << sqlist.elem[sqlist.length - 1] << ']';
	return out;
}

template<class ElemType>
void SqList<ElemType>::insert(const ElemType x, int location)
{
	if (location < 0 || location >= length)
	{
		cout << "The location " << location << " is out of the range!" << endl;
		exit(-1);
	}

	if (length >= listSize)                  // 当线性表已满时
	{
		cout << "Increase the SqList memory!" << endl;
		//** 一般只有在使用 malloc 分配内存并且用 free 释放内存时可以这么做
		ElemType* newbase = (ElemType*)realloc(elem, (listSize + LISTINCREMENT) * sizeof(ElemType));  // 扩展elem的内存
		if (!newbase)
		{
			cout << "Don't have enough memory!" << endl;
			exit(-1);
		}
		elem = newbase;
		/*
		ElemType* newbase = new ElemType[listSize + LISTINCREMENT];
		memcpy(newbase, elem, sizeof(elem) * listSize);
		delete[] elem;
		elem = newbase;*/
		listSize += LISTINCREMENT;
	}

	for (int i = length; i >= location; i--) // location 之后的元素后移一位
		elem[i + 1] = elem[i];

	elem[location] = x;
	length += 1;
}

template<class ElemType>
ElemType SqList<ElemType>::delElem(int location)
{
	if (location < 0 || location >= length)
	{
		cout << "The location "<< location <<" is out of the range!" << endl;
		exit(-1);
	}

	ElemType tmp = elem[location];
	for (int i = location + 1; i < length; i++)
		elem[i - 1] = elem[i];
	length--;
	return tmp;
}

template<class ElemType>
void SqList<ElemType>::set(ElemType x, int location)
{
	if (location < 0 || location >= length)
	{
		cout << "The location " << location << " is out of the range!" << endl;
		exit(-1);
	}

	elem[location] = x;
}

template<class ElemType>
ElemType SqList<ElemType>::get(int location)
{
	if (location < 0 || location >= length)
	{
		cout << "The location " << location << " is out of the range!" << endl;
		exit(-1);
	}

	return elem[location];
}