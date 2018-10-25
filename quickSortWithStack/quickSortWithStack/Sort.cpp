#include "stdafx.h"
#include "SqList.h"
#include "stack.h"
#include "Sort.h"

int partition(SqList<int>& list, int low, int high)
{
	int pivotKey = list.get(low);

	while (low < high)
	{
		while (low < high && list.get(high) >= pivotKey)
			high--;
		
		list.set(list.get(high), low);

		while (low < high && list.get(low) <= pivotKey)
			low++;

		list.set(list.get(low), high);
	}

	list.set(pivotKey, low);
	return low;
}

void quickSort(SqList<int> &list, int low, int high)
{
	int pivotloc;
	if (low < high)
	{
		pivotloc = partition(list, low, high);
		quickSort(list, low, pivotloc - 1);
		quickSort(list, pivotloc + 1, high);
	}
}