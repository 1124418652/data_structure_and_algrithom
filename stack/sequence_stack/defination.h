#include <stdio.h>

#define INITLENGTH 10
#define STACKINCREMENT 5

typedef char SElemType;

typedef struct
{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SqStack;

void InitStack(SqStack &S);     //initial the stack
int StackLength(SqStack &S);    //return the length of the stack
void PushElem(SqStack &S, SElemType e);      //push the element in to the stack
SElemType PopElem(SqStack &S);  //return the element which was poped
SElemType GetTopElem(SqStack &S);            //get the top element
bool ElemMatch(SElemType, SElemType);      