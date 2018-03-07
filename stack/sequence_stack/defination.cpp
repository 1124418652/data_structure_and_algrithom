#include <stdio.h>
#include <stdlib.h>
#include "defination.h"

void InitStack(SqStack &S)
{
	if(!(S.base=(SElemType *)malloc(sizeof(SElemType)*INITLENGTH)))
	{
		printf("don't have enough memory!\n");
		exit(1);
	}
	S.top = S.base; 
	S.stacksize = INITLENGTH;
	printf("have initial the stack!\n");
}

void PushElem(SqStack &S, SElemType e)
{
	if(S.base==NULL)
	{
		printf("the stack is not existing!\n");
		exit(1);
	}

	if((S.top-S.base)>=S.stacksize)
	{
		if(!(S.base=(SElemType *)realloc(S.base,
			(S.stacksize+STACKINCREMENT)*sizeof(SElemType))))
		{
			printf("don't have enough memory!\n");
			exit(1);
		}
		S.top = S.base + S.stacksize;
		S.stacksize += STACKINCREMENT;
		printf("%d",S.top-S.base);
	}

	*S.top++ = e;
	printf("have pushed the element into the stack!\n");
}

int StackLength(SqStack &S)
{
	return S.top-S.base;
}

SElemType PopElem(SqStack &S)
{
	if(S.base==S.top)
	{
		printf("the stack has been empty!\n");
		exit(1);
	}
	SElemType e;
	e = *--S.top;
	return e;
}