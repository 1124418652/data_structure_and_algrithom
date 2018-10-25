#include <iostream>
using namespace std;

int **createArray();

void main()
{
	int **b = createArray();
	for (int i=0; i<5; i++)
	{
	//	for (int j=0; j<5; j++)
			//cout<<b[i][j]<<endl;
	}
	string a="adfagargha";
	cout<<a.length()<<int(1.2)<<endl;

}

int **createArray()
{
	int **a;
	a = new int*[5];
	for (int i=0; i<5; i++)
	{
		a[i] = new int[5];
	}
	for (i=0; i<5; i++)
	{
		for (int j=0; j<5; j++)
			a[i][j] = i+j;
	}
	return a;
}
