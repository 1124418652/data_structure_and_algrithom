#define INITLENGTH 100
#define INCREMENT 10

typedef char ElemType;
typedef struct SqStack
{
	ElemType *base;
	ElemType *top;
	int stacklength;
}SqStack;

void InitStack(SqStack &S);             //initial the stack
void PushElem(SqStack &S, ElemType e);  //push the element into the stack
bool GetTopElem(SqStack S, ElemType &e);  //get the top element of the stack
bool Pop(SqStack &S);
void ClearStack(SqStack &S);
void DestroyStack(SqStack &S);
bool isEmpty(SqStack S);
SqStack ReverseStack(SqStack &S);          //reverse the stack