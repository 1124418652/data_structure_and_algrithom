typedef int TElemType;
typedef struct BiNode
{
	TElemType data;
	struct BiNode *lchild;
	struct BiNode *rchild;
}BiNode, *BiTree, *SElemType;

void Visit(BiTree T);
void CreateTree(void);
void InsertTree(BiTree &T, TElemType e);
void PreOrderTraverse(BiTree T, void (* Visit)(BiTree T));
void InOrderTraverse(BiTree T, void (* Visit)(BiTree T));
void InOrderTraverse(BiTree T);
void PostOrderTraverse(BiTree T, void (* Visit)(BiTree T));
void PreShow(BiTree T, void (* Visit)(BiTree T));
void PostShow(BiTree T, void (* Visit)(BiTree T));



#define INITLEN 100
#define INCREMENT 10

typedef BiTree SElemType;
typedef struct SqStack
{
	SElemType *base;
	SElemType *top;
	int size;
}SqStack, *StackList;

void InitStack(SqStack &S);
void Push(SqStack &S, SElemType e);
void Pop(SqStack &S, SElemType &e);
void GetTop(SqStack S, SElemType &e);
bool isEmpty(SqStack S);