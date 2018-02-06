/*sequence storage structure*/
#include "defination.h"

void main(){
	Sqlist list;
	InitList(list);
	
	ElemType l_a[] = {1,2,3,4,5};
	for(int i=0; i<sizeof(l_a)/sizeof(l_a[0]); i++){
		list.elem[i] = l_a[i];
		list.length++;
	}
	
	ShowList(list);

	ElemType I_e = 3;
	InsertElem(list, 2, 3);
	ShowList(list);

	ClearList(list);
	
	ShowList(list);
}