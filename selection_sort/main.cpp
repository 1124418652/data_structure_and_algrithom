#include <iostream>
#include "definition.h"
using namespace std;

void main()
{
	int a[] = {2,3,1,8,4, NULL};
	selectSort(a);
	for (int i=0; a[i]!=NULL; i++)
	{
		cout<<a[i]<<' ';
	}
}