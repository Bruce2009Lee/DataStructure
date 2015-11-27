#include "C.h"
#include "SeqList.h"

struct Student
{
	string name;
	int score;
};


typedef int T;

#include "Func1-1.cpp"

void main()
{
	int pos;
	int retval=0;
	SeqList<T> mylist;
	mylist.CreateFromTerminal();
	mylist.ListTraverse(visit);
	pos=mylist.LocateElem(5,equal);
	if(pos==0)
		cout<<"not found"<<endl;
	else
		cout<<"locate:"<<pos<<endl;
	if(mylist.PriorElem(1,equal,retval))
		cout<<"pre val"<<retval<<endl;
	if(mylist.NextElem(6,equal,retval))
		cout<<"nex val:"<<retval<<endl;
	if(mylist.ListDelete(3,retval))
		cout<<"delete val:"<<retval<<endl;
	mylist.ListTraverse(visit);
	if(mylist.ListInsert(6,10))
	{
		cout<<"Insert done"<<endl;
		mylist.ListTraverse(visit);
	}
	else 
		cout<<"bad operation"<<endl;

}