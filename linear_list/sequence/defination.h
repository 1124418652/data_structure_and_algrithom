#include <stdio.h>
#include <stdlib.h>
//#include <alloc.h>
#define LIST_INIT_SIZE 100         //���Ա��ʼ����ֵ
#define LISTINCREMENT 10           //���Ա�洢�ռ�ķ�������

typedef int ElemType;              //����Ԫ�ص����ͣ�������int��
typedef struct{
	ElemType *elem;          //�洢�ռ�Ļ���ַ
	int length;              //���Ա���
	int listsize;            //��ǰ����Ĵ洢����
}Sqlist;

/*�������Ա�Ĳ���*/
int InitList(Sqlist &L){
	/*ʹ��malloc��������һ��洢�ռ䣬�����׵�ַ����L.Elemָ��*/
	if(!(L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType)))){
		printf("don't have enough memory to allocte buter!\n");
		exit(1);                       //����ʧ��
	}
	L.length = 0;                      //��ǰ����
	L.listsize = LIST_INIT_SIZE;       //��ǰ������
	return 0;
}

void DestroyList(Sqlist &L){
	free(L.elem);
}

void ClearList(Sqlist &L){
	int len = L.length;
	for(int i=len-1; i>=0; i--){
		L.elem[i]=NULL;
		L.length--;
	}
	if(L.length==0)printf("have clear the list\n");
}

void InsertElem(Sqlist &L, int i, ElemType e){
	if(i<0||i>L.length-1){
		printf("can't insert the element\n");
	}
	else if(L.length>=LIST_INIT_SIZE){     //���洢�ռ䲻��ʱ�����·���洢�ռ�
		ElemType *newbase = (ElemType *)malloc((L.listsize+LISTINCREMENT)*sizeof(ElemType));
		L.elem = newbase;
	}
	else{
		ElemType *p, *q;
		p = &(L.elem[i-1]);
		for(q=&(L.elem[L.length-1]); q>=p; q--){
			*(q+1) = *q;
		}
		*p = e;
		++L.length;
	}
}

int ShowList(Sqlist L){
	if(L.length == 0){
		printf("don't have any element!\n");
		return 0;
	}
	for(int i=0; i<L.length; i++){
		printf("%d-->%d\n", i+1, L.elem[i]);
	}
	return 1;
}

int DeletElem(Sqlist &L, int i, ElemType &e){
	if(i<0||i>=L.length){
		printf("can't delete the element\n");
		return 0;
	}
	ElemType *p, *q;
	p = &(L.elem[i-1]);
	e = *p;
	q = L.elem + L.length -1;
	for(p; p<q; p++){
		*p = *(p+1);
		L.length--;
	}
	return 1;
}