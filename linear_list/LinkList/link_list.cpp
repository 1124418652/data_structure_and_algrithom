#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode{
	ElemType data;
	LNode *next;
}LNode, *pNode;

pNode Create_list(void){       //��������
	int i, len;
	ElemType val;
	pNode pHead, pTail;   //pHeadָ���Ǳ�ʾ�����׵�ַ�ģ������ƶ�

	if(!(pHead = (pNode)malloc(sizeof(LNode)))){
		printf("can't find enough memory\n");
		exit(1);
	}

	pHead->data = 0;
	pHead->next = NULL;
	pTail = pHead;

	printf("please input the length of list:");
	scanf("%d", &len);

	for(i=0; i<len; i++){
		pNode p;             //�ڵ�pΪ�����ӵĽڵ�
		if(!(p = (pNode)malloc(sizeof(LNode)))){
			printf("can't find enough memory\n");
			exit(1);
		}

		printf("please input the value of node %d:", i);
		scanf("%d", &val);
		p->data = val;
		p->next = NULL;

		pTail->next = p;         
		pTail = p;
	}
	return pHead;
}

void Show_list(pNode phead){       //��ʾ����
	if(!phead){
		printf("the list if empty!\n");
	}
	
	printf("the value of head node is:%d\n", phead->data);
	phead = phead->next;
	for(int i=1; phead!=NULL; i++){
		printf("the value of node %d is: %d\n", i, phead->data);
		phead = phead->next;
	}
}

bool Insert_list(pNode phead, int pos, ElemType val){     //��ָ��λ�ò���Ԫ��
	pNode p = phead;         //��pָ�뻬���������Ҳ���λ��
	int i = 0;
	while((i<pos-1)&&(p!=NULL)){
		p = p->next;
		i++;
	}
	if((p==NULL)||(i>pos-1))
		return false;
	pNode tmp = (pNode)malloc(sizeof(LNode));
	tmp->data = val;
	tmp->next = p->next;
	p->next = tmp;
	return true;
}

ElemType Delet_list(pNode phead, int pos){      //ɾ��ָ��λ�ýڵ�
	int i = 0;
	ElemType val = NULL;
	pNode p = phead;
	while((i<pos-1)&&(p->next!=NULL)){
		p = p->next;
		i++;
	}
	pNode q = p->next;
	val = q->data;
	p->next = q->next;
	free(q);
	q = NULL;
	return val;
}

void main(){
	pNode list = Create_list();
	if(Insert_list(list, 2, 10)){
		Show_list(list);
	}
	printf("%d\n",Delet_list(list, 2));
	Show_list(list);
	int time;
	while(true){
		time++;
	}
}