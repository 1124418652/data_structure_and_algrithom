#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "BiTree.h"

void InitStack(SqStack &S)
{
	if(!(S.base=(SElemType *)malloc(INITLEN*sizeof(SElemType))))
	{
		printf("Don't have enough memory space!\n");
		exit(1);
	}

	S.top = S.base;
	S.size = INITLEN;
}

void Push(SqStack &S, SElemType e)
{
	if(NULL==S.base) InitStack(S);
	
	if(S.top-S.base>=S.size)
	{
		if(!(S.base=(SElemType *)realloc(S.base,
			(INITLEN+INCREMENT)*sizeof(SElemType))))
		{
			printf("Don't have enough memory space!\n");
			exit(1);
		}
		S.size += INCREMENT;
		S.top = S.base + S.size;
	}

	*S.top++ = e;
}

void Pop(SqStack &S, SElemType &e)
{
	if(isEmpty(S))
	{
		printf("The stack is empty!\n");
		exit(0);
	}

	e = *(--S.top);
}

void GetTop(SqStack S, SElemType &e)
{
	e = *(--S.top);
}

bool isEmpty(SqStack S)
{
	return S.base==S.top? true:false;
}