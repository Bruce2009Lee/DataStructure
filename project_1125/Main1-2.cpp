#include "C.h"
#include "AList.h"
#include "LNode.h"
#include "LinkList.h"

typedef int T;

void visit(T *e)
{
	cout<<*e<<" ";
}

void main()
{
	LinkList<int> mylinklist;
	for(int i=0;i<5;i++)
		mylinklist.ListInsert(1,i+10);
	mylinklist.ListTraverse(visit);
}