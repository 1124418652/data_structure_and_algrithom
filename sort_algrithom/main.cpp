#include "defination.h"
#include <time.h>

template<typename T1>
T1 *randcreate(T1 min, T1 max, int num);

void main(int argc, char *argv[])
{
	clock_t start, finish;
	
	int *x = randcreate(2,100000, 20000);

	int a[] = {2,5,3,9,6,32,13,33,10,8};
	Sort<int> sortList(x, 20000);

	delete []x;

	start = clock();
	sortList.binary_insert_sort();
	finish = clock();
	cout<<(double)(finish-start)/CLOCKS_PER_SEC<<'s'<<endl;

	cout<<sortList<<endl;
}

template<typename T1>
T1 *randcreate(T1 min, T1 max, int num)
{
	srand((int)time(NULL));
	static T1 *tmp = new T1[num];
	for (int i=0; i<num; i++)
	{
		tmp[i] = rand()%(max-min)+min;
	}
	return tmp;
}