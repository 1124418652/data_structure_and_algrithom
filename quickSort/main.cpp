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

	int b[] = {2,11,3,6,9,4,5, NULL};
	quickSort_with_pointExchange(b,0,6);
	for (i=0; i<7; i++)
	{
		cout<<b[i]<<' ';
	}
	cout<<endl;
	int d = 2, c=2;
	int e = c^d^c;
	cout<<e<<endl;
}