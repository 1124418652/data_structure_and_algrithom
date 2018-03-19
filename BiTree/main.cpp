#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild;
	struct BiTNode *rchild;
}BiTNode, *BiTree;

bool CreateTree(BiTree &T)
{
	ElemType elem;
	printf("please input the data:");
	scanf("%d", &elem);

	if(0==elem)
	{
		T = NULL;
	}
	else
	{
		if(!(T=(BiTree)malloc(sizeof(BiTNode))))
		{
			printf("don't have enough memory!\n");
			return false;
		}
		T->data = elem;
		CreateTree(T->lchild);
		CreateTree(T->rchild);
	}
	return true;
}

void PreShow(BiTree T)      //�������
{
	if(T)
	{
		printf("the data is:%d\n", T->data);
		PreShow(T->lchild);
		PreShow(T->rchild);
	}
}

void InOrder(BiTree T)     //�������
{
	if(T)
	{
		InOrder(T->lchild);
		printf("the data is:%d\n", T->data);
		InOrder(T->rchild);
	}
}

void PostOrder(BiTree T)    //�������
{
	if(T)
	{
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		printf("the data is:%d\n", T->data);
	}
}

void main()
{
	BiTree tree;
	if(CreateTree(tree))
	{
		PreShow(tree);
		InOrder(tree);
		PostOrder(tree);
	}
	system("pause");
}