#include <iostream>

#define LT(a,b) ((a)<(b))
#define LQ(a,b) ((a)<=(b))
#define EQ(a,b) ((a)==(b))

using namespace std;

int selectMin(int *list, int i)
{
	int min = list[i];
	int min_pos = i;
	for (int j = i; list[j]!=NULL; j++)
	{
		if (LT(list[j], min))
		{
			min = list[j];
			min_pos = j;
		}
	}
	return min_pos;
}


void selectSort(int *list)
{
	for (int i=0; list[i]!=NULL; i++)
	{
		int j = selectMin(list, i);
		if (!EQ(i, j))
		{
			list[i] = list[i]^list[j];
			list[j] = list[i]^list[j];
			list[i] = list[j]^list[i];
		}
	}
}

