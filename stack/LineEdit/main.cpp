#include <stdio.h>
#include <stdlib.h>
#include "SequenceStack.h"

void main()
{
	SqStack stack;
	ElemType e, topelem;
	FILE *fp;
	InitStack(stack);
	printf("input the text:\n");
	e = getchar();
	
	while(e!=EOF)
	{
		while(e!=EOF && e!='\n')
		{
			switch(e)
			{
			case '#': Pop(stack); break;        //use '#' to backspace
			case '@': ClearStack(stack); break; //use '@' to delete the line
			default: PushElem(stack, e);
			}
			e = getchar();
		}

		stack = ReverseStack(stack);

		if((fp=fopen("D:\\outputfile.txt","a"))==NULL)
		{
			printf("can't open the file!\n");
			exit(1);
		}
		while(!isEmpty(stack))
		{
			if(GetTopElem(stack, topelem))
				fwrite(&topelem, sizeof(ElemType), 1, fp);
			if(Pop(stack)){}
		}
		fwrite("\n", sizeof(char), 1, fp);
		fclose(fp);

		e = getchar();
	}
	system("pause");
}