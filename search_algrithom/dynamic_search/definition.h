#include <iostream>
#include <cmath>
#define EQ(a, b) ((a)==(b))
#define LT(a, b) ((a)<(b))
#define LQ(a, b) ((a)<=(b))

using namespace std;

enum status {TRUE, FALSE};

template<class T> class DynamicSearchTable;
template<class T>
class BinarySortTree
{
public:
	BinarySortTree();
	BinarySortTree(T e);
	~BinarySortTree(){cout<<"de"<<endl;};
	friend class DynamicSearchTable<T>;
private:
	T data;
	BinarySortTree<T> *lchild;
	BinarySortTree<T> *rchild;
};

template<class T>
BinarySortTree<T>::BinarySortTree()
{
	data = NULL;
	lchild = NULL;
	rchild = NULL;
}

template<class T>
BinarySortTree<T>::BinarySortTree(T e):data(e)
{
	lchild = NULL;
	rchild = NULL;
}

template<class T>
class DynamicSearchTable
{
public:
	DynamicSearchTable();
	~DynamicSearchTable();
	BinarySortTree<T>* getNode();
	status InsertDSTable(T key){};
	status SearchDSTable(BinarySortTree<T> *tree, T key);
	status DeleteDSTable(T key){};
	void midOrder(BinarySortTree<T> *tree);
private:
	BinarySortTree<T> *tree;
};

template<class T>
DynamicSearchTable<T>::DynamicSearchTable()
{
	tree = new BinarySortTree<T>;
}

template<class T>
DynamicSearchTable<T>::~DynamicSearchTable()
{
	if (tree)
	{
		delete tree;
	}
	cout<<"deconstructor"<<endl;
}

template<class T>
BinarySortTree<T>* DynamicSearchTable<T>::getNode()
{
	return tree;
}

template<class T>
status DynamicSearchTable<T>::SearchDSTable(BinarySortTree<T> *tree, T key)
{
	if (LT(key, tree->data))
	{
		if (!(tree->lchild))
		{
			BinarySortTree<T> *p = new BinarySortTree<T>(key);
			tree->lchild = p;
			return FALSE;
		}
		SearchDSTable(tree->lchild, key);
	}
	else if (LT(tree->data, key))
	{
		if (!(tree->rchild))
		{
			BinarySortTree<T> *p = new BinarySortTree<T>(key);
			tree->rchild = p;
			return FALSE;
		}
		SearchDSTable(tree->rchild, key);
	}
	else
	{
		cout<<tree->data<<endl;
		return TRUE;
	}
}

template<class T>
void DynamicSearchTable<T>::midOrder(BinarySortTree<T> *tree)
{
	if (tree)
	{
		midOrder(tree->lchild);
		cout<<tree->data<<endl;
		midOrder(tree->rchild);
	}
}