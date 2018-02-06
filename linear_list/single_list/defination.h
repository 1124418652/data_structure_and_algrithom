#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LNode *CreatSLinkList(void){
	int len;                    //len用来记录链表的长度
	ElemType val;               //val用来记录用户输入的每个结点的数据值
	int i = 0;
	LinkList PHead, PTail;      //PHead用来记录头结点的位置，PTail用来向后移动，添加新的结点


	if(!(PHead = (LNode *)malloc(sizeof(LNode)))){          //给头结点分配空间失败
		printf("don't have enough memory\n");
		exit(1);
	}

	PHead -> next = NULL;
	PTail = PHead;
	
	printf("please input the length of the list:");
	scanf("%d",&len);
	
	for(; i<len; i++){                    //由用户逐个输入数据
		LinkList p;
		if(!(p = (LNode *)malloc(sizeof(LNode)))){               //给结点p分配空间失败
			printf("don't have enough memory\n");
			exit(1);
		}
		printf("please input the value of node %d:", i);
		val = scanf("%d", &val);
		p -> data = val;
		p -> next = NULL;
		PTail -> next = p;
		PTail = p;
	}

	return PHead;
}

