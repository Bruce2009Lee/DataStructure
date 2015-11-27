#ifndef _LINKLIST_H_
#define _LINKLIST_H_

#include "LNode.h"
#include "AList.h"
template<typename T>
class LinkList:public AList<T>
{
protected:
	LNode<T>* Head;
public:
	LinkList()
	{
		Head=new LNode<T>;
		assert(Head!=NULL);
		Head->next=NULL;
	}
	~LinkList()
	{
		ClearList();
		delete Head;
	}
	void ClearList()const
	{
		LNode<T> *p,*q;
		p=Head->next;
		while(p!=NULL)
		{
			q=p->next;
			delete p;
			p=q;
		}
	}
	bool ListEmpty()const
	{
		return Head->next==NULL;
	}
	int ListLength()const
	{
		int i=0;
		LNode<T> *p=Head->next;
		while(p!=NULL)
		{
			p++;
			i++;
		}
		return i;
	}
	bool ListInsert(int i,T e)
	{
		int j=0;
		LNode<T> *p=Head,*s;
		while(p!=NULL&&j<i-1)
		{
			p=p->next;
			j++;
		}
		if(p==NULL||j>i-1)
			return false;
		s=new LNode<T>;
		assert(s!=NULL);
		s->data=e;
		s->next=p->next;
		p->next=s;
		return true;
	}
	void ListTraverse(void (*visit)(T*))const
	{
		LNode<T>* p=Head->next;
		while(p!=NULL)
		{
			visit(&p->data);
			p=p->next;
		}
		cout<<endl;

	}
};
#endif