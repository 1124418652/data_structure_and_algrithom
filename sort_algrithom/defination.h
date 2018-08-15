#include <iostream>

#define SIZE 10
#define EQ(a,b) ((a)==(b))
#define LT(a,b) ((a)<(b))

using namespace std;

template<class T>
class Sort
{
	T *sqlist;
	int length;
public:
	Sort();
	Sort(T *list, int len);
	~Sort();
	friend ostream& operator<<(ostream &output, const Sort<T> &sort)
	{
		for (int i=1; i<sort.length; i++)
		{
			output<<sort.sqlist[i]<<' ';
		}
		output<<endl;
		return output;
	}
	void straight_insert_sort();
	void binary_insert_sort();
};

template<class T>
Sort<T>::Sort(){
	sqlist = NULL;
	length = 0;
}

template<class T>
Sort<T>::Sort(T *list, int len)
{
	sqlist = new T[len+1];
	length = len+1;
	for (int i=1; i<=len; i++)
	{
		sqlist[i] = list[i-1];
	}
}

template<class T>
Sort<T>::~Sort()
{
	if (sqlist)
	{
		delete []sqlist;
	}
	cout<<"deconstruct"<<endl;
}

/*
template<class T>
friend ostream& operator<<(ostream output, const Sort<T> &sort)
{
	for (int i=1; i<length; i++)
	{
		output<<sort[i]<<' ';
	}
	output<<endl;
	return output;
}
*/

template<class T>
void Sort<T>::straight_insert_sort()
{
	for (int i=2; i<length; i++)
	{
		if (LT(sqlist[i], sqlist[i-1]))
		{
			sqlist[0] = sqlist[i];
			sqlist[i] = sqlist[i-1];
			//sqlist[i-1] = sqlist[0];
	
			for (int j=i-1; LT(sqlist[0], sqlist[j-1]); j--)
			{
				sqlist[j] = sqlist[j-1];
			}
			sqlist[j] = sqlist[0];
		}
	}
}

template<class T>
void Sort<T>::binary_insert_sort()
{
	for (int i=2; i<length; i++)
	{
		if (LT(sqlist[i], sqlist[i-1]))
		{
			sqlist[0] = sqlist[i];
			int low = 1;
			int high = i-1;
			int mid;
			while (low<=high)
			{
				mid = (low+high)/2;
				if (LT(sqlist[0], sqlist[mid]))
					high = mid - 1;
				else if (LT(sqlist[mid], sqlist[0]))
					low = mid + 1;
				else
					break;
			}
			for (int j=i-1; j>=high+1; j--)
			{
				sqlist[j+1] = sqlist[j];
			}
			sqlist[high+1] = sqlist[0];
		}
	}
}