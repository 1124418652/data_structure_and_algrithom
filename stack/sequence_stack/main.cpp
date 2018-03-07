#include <stdio.h>
#include <stdlib.h>
#include "defination.h"

void main()
{
	SqStack stack;
	InitStack(stack);

	for(int i=0; i<20; i++)
	{
		PushElem(stack, i);
	}

	printf("the number of the element is:\t%d\n",StackLength(stack));
	printf("the value of the pop element is:\t%d\n",PopElem(stack));
	system("pause");
}