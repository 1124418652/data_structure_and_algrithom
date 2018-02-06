#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	struct LNode *next;
}LNode, *LinkList;

LNode *CreatSLinkList(void){
	int len;                    //len������¼����ĳ���
	ElemType val;               //val������¼�û������ÿ����������ֵ
	int i = 0;
	LinkList PHead, PTail;      //PHead������¼ͷ����λ�ã�PTail��������ƶ�������µĽ��


	if(!(PHead = (LNode *)malloc(sizeof(LNode)))){          //��ͷ������ռ�ʧ��
		printf("don't have enough memory\n");
		exit(1);
	}

	PHead -> next = NULL;
	PTail = PHead;
	
	printf("please input the length of the list:");
	scanf("%d",&len);
	
	for(; i<len; i++){                    //���û������������
		LinkList p;
		if(!(p = (LNode *)malloc(sizeof(LNode)))){               //�����p����ռ�ʧ��
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

