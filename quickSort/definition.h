#include <iostream>
using namespace std;

#define LT(a, b) ((a)<(b))
#define EQ(a, b) ((a)==(b))
#define LQ(a, b) ((a)<=(b))

void quickSort(int *list, int min, int max)
{
	if (min<max)
	{
		int pivotkey = list[min];
		int left = min;
		int right = max;
		while (left<right)
		{
			while (list[right]>=pivotkey && left<right)
			{
				right--;
			}
			list[left] = list[right];
			while (list[left]<=pivotkey && left<right)
			{
				left++;
			}
			list[right] = list[left];
		}
		list[left] = pivotkey;
		quickSort(list, min, left-1);
		quickSort(list, left+1, max);
	}
}

void quickSort_with_pointExchange(int *list, int min, int max)
{
	if (min<max)
	{
		int pivotkey = list[min];
		int left = min;
		int right = max;
		int tmp;
		while (left<right)
		{
			while (list[right]>pivotkey && left<right)
			{
				right--;
			}
			while (list[left]<pivotkey && left<right)
			{
				left++;
			}
			
			list[left] = list[left]^list[right];
			list[right] = list[left]^list[right];
			list[left] = list[right]^list[left];
			
		}
		list[left] = pivotkey;
		quickSort_with_pointExchange(list, min, left-1);
		quickSort_with_pointExchange(list, left+1, max);
	}
}
