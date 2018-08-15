#include "definition.h"

template<typename T>
T* createRandom(T min, T max, int num);

void main(int argc, char *argv[])
{
	clock_t start, end;
	int list[] = {1,3,2,5,32,6,4,7};
	int *list1 = createRandom(10, 10000, 10000);
	Sort<int> sort(list1, 10000);

	start = clock();
	sort.bubbleSort();
	end = clock();
	cout<<sort<<endl;
	cout<<"time used: "<<(float)(end-start)/1000<<'s'<<endl;
}

template<typename T>
T* createRandom(T min, T max, int num)
{
	srand((int)time(NULL));
	T *list = new T[num];
	for (int i=0; i<num; i++)
	{
		list[i] = rand()%(max-min)+min;
	}
	return list;
}