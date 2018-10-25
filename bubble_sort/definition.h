#include <iostream>
#include <time.h>

#define EQ(a, b) ((a)==(b))
#define LT(a, b) ((a)<(b))

using namespace std;

template<class T>
class Sort
{
	T *sqlist;
	int length;
public:
	Sort(){sqlist = NULL;};
	Sort(T *list, int len);
	~Sort();
	void bubbleSort();

	friend ostream& operator<<(ostream &output, const Sort<T> &sort)
	{
		for (int i=0; i<sort.length; i++)
		{
			output<<sort.sqlist[i]<<' ';
		}
		output<<endl;
		return output;
	}
};

template<class T>
Sort<T>::Sort(T *list, int len)
{
	sqlist = new T[len];
	length = len;
	for (int i=0; i<len; i++)
	{
		sqlist[i] = list[i];
	}
	cout<<"constructor"<<endl;
}

template<class T>
Sort<T>::~Sort()
{
	if (sqlist)
	{
		delete []sqlist;
	}
	cout<<"deconstructor"<<endl;
}

template<class T>
void Sort<T>::bubbleSort()
{
	if (!sqlist)
	{
		cout<<"the list is empty"<<endl;
	}
	T tmp;
	for (int i=length-1; i>=1; i--)
	{
		for (int j=0; j<i; j++)
		{
			if (LT(sqlist[j+1], sqlist[j]))
			{
				tmp = sqlist[j+1];
				sqlist[j+1] = sqlist[j];
				sqlist[j] = tmp;
			}
		}
	}
}

