#include <stdio.h>
#include <stdlib.h>
//#include <alloc.h>
#define LIST_INIT_SIZE 100         //线性表初始分配值
#define LISTINCREMENT 10           //线性表存储空间的分配增量

typedef int ElemType;              //数据元素的类型，假设是int型
typedef struct{
	ElemType *elem;          //存储空间的基地址
	int length;              //线性表长度
	int listsize;            //当前分配的存储容量
}Sqlist;

/*定义线性表的操作*/
int InitList(Sqlist &L){
	/*使用malloc函数开辟一块存储空间，并将首地址赋给L.Elem指针*/
	if(!(L.elem=(ElemType *)malloc(LIST_INIT_SIZE*sizeof(ElemType)))){
		printf("don't have enough memory to allocte buter!\n");
		exit(1);                       //分配失败
	}
	L.length = 0;                      //当前长度
	L.listsize = LIST_INIT_SIZE;       //当前分配量
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
	else if(L.length>=LIST_INIT_SIZE){     //当存储空间不足时，重新分配存储空间
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