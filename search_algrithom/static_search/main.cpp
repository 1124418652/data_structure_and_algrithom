#include <iostream>
#include "definition.h"
using namespace std;

void main()
{
	int a[17] = {1,2,3,4,5,6,7,8,9,10,12,14,15,24,123,563,908};

	StaticSearch<int> ss, ss1(a, 17);
	ss1.show();
	ss.show();
	cout<<ss1.linearSearch(-4)<<endl;
	cout<<ss1.halfSearch(123)<<endl;
}