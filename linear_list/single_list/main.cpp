#include "defination.h"
#include "function.h"

void main(){
	LinkList list, p;
	list = CreatSLinkList();
	while(list->next != NULL){
		printf("%d\n", list->next->data);
		list = list -> next;
	}
	printf("done\n");
}