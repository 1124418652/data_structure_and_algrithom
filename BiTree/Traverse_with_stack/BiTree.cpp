#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"
#include "Stack.h"

void Visit(BiTree T)
{
	printf("the data:%8d\n", T->data);
}

void InsertTree(BiTree &T, TElemType e)
{
	if(NULL==T)
	{
		if(!(T=(BiTree)malloc(sizeof(BiNode))))
		{
			printf("Don't have enough memory space!\n");
			exit(1);
		}
		T->data = e;
//		printf("insert %d\n", e);
		T->lchild = NULL;
		T->rchild = NULL;
	}else
	{
		if(e>=(T->data)) InsertTree(T->rchild, e);
		else InsertTree(T->lchild, e);
	}
}

void PreOrderTraverse(BiTree T, void (* Visit)(BiTree T))
{
	if(T)
	{
		Visit(T);
		PreOrderTraverse(T->lchild, Visit);
		PreOrderTraverse(T->rchild, Visit);
	}
}

void InOrderTraverse(BiTree T, void (* Visit)(BiTree T))
{
	if(T)
	{
		InOrderTraverse(T->lchild, Visit);
		Visit(T);
		InOrderTraverse(T->rchild, Visit);
	}
}

void InOrderTraverse(BiTree T)
{
	if(T)
	{
		InOrderTraverse(T->lchild);
		printf("the data: %d\n", T->data);
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T, void (* Visit)(BiTree T))
{
	if(T)
	{
		PostOrderTraverse(T, Visit);
		PostOrderTraverse(T, Visit);
		Visit(T);
	}
}

void PreShow(BiTree T, void (* Visit)(BiTree T))
{
	SqStack S;
	InitStack(S);
	BiTree P = T;
	while(P||!isEmpty(S))
	{
		if(P)
		{
			Visit(P);
			Push(S, P);
			P = P->lchild;
		}else
		{
			Pop(S, P);
			P = P->rchild;
		}
	}
}

void PostShow(BiTree T, void (* Visit)(BiTree T))
{
	SqStack S, S2;
	InitStack(S);
	int label[10];
	int i = 0;
	BiTree P = T;

	while(P||!isEmpty(S))
	{
		while(P)
		{
			Push(S, P);
			label[i++] = 0;
			P = P->lchild;
		}
		while(!isEmpty(S)&&label[i-1]==1)
		{
			Pop(S, P);
			Visit(P);
			i--;
//			printf("i=%d\t;label[%d]=%d\n",i,i,label[1]);
		}
		if(!isEmpty(S))
		{
			GetTop(S, P);
			label[i-1] = 1;
			P = P->rchild;
		}
		else break;
	}
}