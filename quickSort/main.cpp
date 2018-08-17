#include <iostream>
#include "definition.h"
using namespace std;


void main()
{
	int a[] = {2,11,3,6,9,4,5, NULL};
	quickSort(a,0,6);
	for (int i=0; i<7; i++)
	{
		cout<<a[i]<<' ';
	}
	cout<<endl;
}