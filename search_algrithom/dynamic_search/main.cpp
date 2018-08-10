#include <iostream>
#include "definition.h"
using namespace std;

void main(int argc, char *argv)
{
	DynamicSearchTable<int> tree;
	tree.SearchDSTable(tree.getNode(), 1);
	tree.SearchDSTable(tree.getNode(), 23);
	tree.SearchDSTable(tree.getNode(), 2);
	tree.midOrder(tree.getNode());
}	