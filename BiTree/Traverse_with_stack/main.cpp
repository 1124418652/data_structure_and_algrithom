#include <stdio.h>
#include <stdlib.h>
#include "BiTree.h"
#include "Stack.h"

void main()
{
	TElemType data_array[] = {2,5,3,4,7,1,9,6,8,10,13,11,0,12};
	int i=0;
	BiTree tree=NULL;

	while(i<14)
	{
		InsertTree(tree, data_array[i]);
		i++;
		printf("%d\n", data_array[i-1]);
	}
	printf("inorder traverse:\n");
	InOrderTraverse(tree, Visit);
	printf("use stack:\n");
	PreShow(tree, Visit);
	printf("Post order use stack:\n");
	PostShow(tree, Visit);
	printf("preorder traverse:\n");
	PreOrderTraverse(tree, Visit);
//	printf("postorder traverse:\n");
//	PostOrderTraverse(tree, Visit);

	system("pause");
}