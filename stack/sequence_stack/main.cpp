#include <stdio.h>
#include <stdlib.h>
#include "defination.h"

void main()
{
	SqStack stack;
	InitStack(stack);
	char elem;
	char topelem, popelem;

	while(elem!='#')
	{
		printf("please input the element:\t");
		elem = getchar();
		printf("\n");

		if(elem=='['||elem=='(')
		{
			PushElem(stack, elem);
		}

		if(elem==']'||elem==')')
		{
			topelem = GetTopElem(stack);
			if(!ElemMatch(topelem, elem))
			{
				printf("don't match!\n");
				continue;
			}
			popelem = PopElem(stack);
			printf("the matched elements are:%c\t%c\n",popelem,elem);
		}

		if(stack.top == stack.base)
		{
			printf("the stack is empty!\n");
			exit(1);
		}
	}
	system("pause");
}