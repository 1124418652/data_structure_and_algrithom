#pragma once
#include <iostream>
using namespace std;

#define INIT_STACK_SIZE 100
#define INCREASE 10

template<class ElemType>
class Stack
{
	int stackSize;
	ElemType *bottom;
	int top;
public:
	Stack()
	{
		bottom = new ElemType[INIT_STACK_SIZE];
		stackSize = INIT_STACK_SIZE;
		top = 0;
	};
	~Stack()
	{
		delete[] bottom;
		cout << "Free the memory of current stack!" << endl;
	};
	void push(const ElemType x);
	ElemType pop();
	int getLength() { return top-1; };
	template<typename T>
	friend ostream& operator<<(ostream& out, const Stack<T>& stack);
};

template<class ElemType>
void Stack<ElemType>::push(const ElemType x)
{
	if (top >= stackSize)
	{
		ElemType* newbase = (ElemType *)realloc(bottom, sizeof(ElemType) * (INIT_STACK_SIZE + INCREASE));
		if (!newbase)
		{
			cout << "Don't have enough memory!" << endl;
			exit(-1);
		}
		bottom = newbase;
	}
	bottom[top] = x;
	top++;
}

template<class ElemType>
ElemType Stack<ElemType>::pop()
{
	if (top <= 0)
	{
		cout << "The stack is empty!" << endl;
		exit(-1);
	}
	return bottom[top--];
}

template<typename T>
ostream& operator<<(ostream& out, const Stack<T>& stack)
{
	if (stack.top <= 0)
	{
		out << "The stack is empty!" << endl;
		return out;
	}
	out << "{";
	for (int i = 0; i < stack.top - 1; i++) {
		out << stack.bottom[i] << ',';
	}
	out << stack.bottom[stack.top - 1] << '}' << endl;
	return out;
}
