// quickSortWithStack.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "SqList.h"
#include <iostream>
#include "stack.h"
#include "Sort.h"
using namespace std;

void main()
{
	int list1[] = { 1,2,3,4,9,8, 2,5 };
	SqList<int> sqlist(list1, 8);
	cout << sqlist << endl;
	sqlist.insert(10, 3);
	cout << sqlist << endl;
	sqlist.delElem(3);
	quickSort(sqlist, 0, 7);
	cout << sqlist << endl;

	Stack<int> stack;
	stack.push(12);
	stack.push(10);
	stack.pop();
	stack.pop();
	cout << stack << endl;
	system("pause");
}

