#include <stdio.h>
#include <stdlib.h>
#include "SequenceStack.h"

void InitStack(SqStack &S)
{
	//if don't have enough memory
	if(!(S.base=(ElemType *)malloc(INITLENGTH*sizeof(ElemType))))
	{
		printf("don't have enough memory!\n");
		exit(1);
	}

	S.top = S.base;
	S.stacklength = INITLENGTH;
//	printf("the stack has been initialized!\n");
}

void PushElem(SqStack &S, ElemType e)
{
	//if the stack has been full
	if(S.top-S.base>=S.stacklength)
	{
		//search for another memory space
		if(!(S.base=(ElemType *)realloc(S.base,
			(INITLENGTH+INCREMENT)*sizeof(ElemType))))
		{
			printf("don't have enough memory space!\n");
			exit(1);
		}
		S.top = S.base+S.stacklength;
		S.stacklength += INCREMENT;
	}
	*S.top++ = e;
}

bool GetTopElem(SqStack S, ElemType &e)
{
	//the stack was empty
	if(S.base==S.top)
	{
		printf("the stack is empty!\n");
		return false;
	}
	e = *(S.top-1);
	return true;
}

bool Pop(SqStack &S)
{
	if(S.base==S.top)
	{
		printf("'the stack is empty!\n");
		return false;
	}
	--S.top;
	return true;
}

void ClearStack(SqStack &S)
{
	while(S.top!=S.base)
	{
		*(--S.top)=NULL;
	}
}

void DestroyStack(SqStack &S)
{
	while(S.top!=S.base)
	{
		*(--S.top)=NULL;
	}
	free(S.base);
}

bool isEmpty(SqStack S)
{
	if(S.top==S.base) return true;
	return false;
}

SqStack ReverseStack(SqStack &S)
{
	if(isEmpty(S))
	{
		printf("can't reverse the stack!\n");
		exit(1);
	}
	static SqStack stmp;
	InitStack(stmp);
	ElemType e;

	while(!isEmpty(S))
	{
		if(GetTopElem(S, e))
		{
			PushElem(stmp, e);
			Pop(S);
		}
	}

	return stmp;
}