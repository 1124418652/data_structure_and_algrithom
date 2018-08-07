/************************************************************************/
/* author: xhj                                                          */
/* email: 1124418652@qq.com                                             */
/************************************************************************/

#include <iostream>
#include <cmath>

#define EQ(a, b) ((a)==(b))
#define LT(a, b) ((a)<(b))
#define LQ(a, b) ((a)<=(b))

using namespace std;

template<class T>
class StaticSearch;

template<class T>
class ElemType
{
public:
	ElemType();
	ElemType(T *elem1, int len);
	~ElemType();
	T getElem(int i);
	void showData();
	friend class StaticSearch<T>;
private:
	T *elem;
	int length;
};

template<class T>
class StaticSearch
{
public:
	StaticSearch(T *elem, int len);
	StaticSearch(){data=NULL;};
	~StaticSearch();
	void show();
	int linearSearch(T elem);
	int halfSearch(T elem);
	int indexSearch(T elem);
private:
	ElemType<T> *data;
};

/* The definition of functions in class ElemType */
template<class T>
ElemType<T>::ElemType()
{
	elem = NULL;
	length = 0;
	cout<<"default constructor of ElemType..."<<endl;
}

template<class T>
ElemType<T>::ElemType(T *elem1, int len)
{
	elem = new T[len];
	for (int i=0; i<len; i++)
	{
		elem[i] = elem1[i];
	}
	length = len;
	cout<<"Have construct the class ElemType..."<<endl;
}

template<class T>
ElemType<T>::~ElemType()
{
	if (elem)
		delete []elem;
	cout<<"Deconstructor of class ElemType..."<<endl;
}

template<class T>
T ElemType<T>::getElem(int i)
{
	if (i<0 || i>length)
	{
		cout<<"Can't find the data of: "<<i<<endl;
		return -1;
	}
	return elem[i];
}

template<class T>
void ElemType<T>::showData()
{
	if (elem && length)
	{
		for (int i=0; i<length; i++)
			cout<<elem[i]<<' ';
		cout<<endl;
	}
	else
		cout<<"The data is empty!"<<endl;
}

/* The definition of functions in class StaticSearch */
template<class T>
StaticSearch<T>::StaticSearch(T *elem, int len)
{
	if (!(data = new ElemType<T>(elem, len)))
	{
		cout<<"Don't have enough memory!"<<endl;
		exit(0);
	}
}

template<class T>
StaticSearch<T>::~StaticSearch()
{
	if (data)
		delete data;
	cout<<"Deconstructor of StaticSearch..."<<endl;
}

template<class T>
void StaticSearch<T>::show()
{
	if(data)
		data->showData();
	else
		cout<<"The data is empty!"<<endl;
}

template<class T>
int StaticSearch<T>::linearSearch(T elem)
{
	for (int i=0; i<data->length; i++)
	{
		if (EQ(data->elem[i], elem))
			return i;
	}
	cout<<"Can't find the elem "<<elem<<" in the set!"<<endl;
	return -1;
}

template<class T>
int StaticSearch<T>::halfSearch(T elem)
{
	int mid;
	int low = 0, high = data->length-1;
	while (LQ(low, high))
	{
		mid = (int)((high+low)/2);
		if (EQ(data->elem[mid], elem))
		{
			return mid;
		}
		else if(LT(mid, elem))
			low = mid + 1;
		else
			high = mid - 1;
	}
	cout<<"Can't find the elem "<<elem<<" in the set!"<<endl;
	return -1;
}












