#include "C.h"
#include "LinkList.h"

typedef int T;

void visit(T *e)
{
	cout<<*e<<" ";
}

int main()
{
	LinkList<T> mylinklist;
	for(int i=0;i<5;i++)
		mylinklist.ListInsert(1,i);
	mylinklist.ListTraverse(visit);
	return 0;
}