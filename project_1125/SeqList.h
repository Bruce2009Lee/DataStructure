#ifndef _SEQLIST_H_
#define _SEQLIST_H_
#include"AList.h"

template<typename T>
class SeqList:public AList<T>
{
private:
	T *elem;
	int length;
	int listsize;
public:
	SeqList(int k=3)
	{
		elem=new T[k];
		assert(elem != NULL);
		length=0;
		listsize=k;
	}
	~SeqList()
	{
		delete []elem;
	}
	void ClearList()
	{
		length=0;
		delete []elem;
	}
	bool ListEmpty()const
	{
		return length==0;
	}
	int LocateElem(T e,bool (*eq)(T e1,T e2))const
	{
		for(int i=0;i<length;i++)
			if(eq(e,elem[i]))
				return i+1;
		return 0;
	}
	bool PriorElem(T e,bool (*eq)(T e1,T e2),T& pre_e)const
	{
		int i;
		i=LocateElem(e,eq);
		if(i==1||i==0)
		{
			return false;
			pre_e=0;
		}
		else 	
		{
			pre_e=elem[i-2];
			return true;
		}
		
	}
	bool NextElem(T e,bool (*eq)(T e1,T e2),T &next_e)const
	{
		int i;
		i=LocateElem(e,eq);
		if(i>=length||i==0)
			return false;
		next_e=elem[i];
		return true;
	}
	bool ListDelete(int i,T &e)
	{
		
		if(i<1||i>length)
			return false;
		e=elem[i-1];
		for(int j=i-1;j<length-1;j++)
			elem[j]=elem[j+1];
		length--;
	}
	bool ListInsert(int i,T e)
	{
		T *p,*q,*newbase;
		if(i<1||i>length)
			return false;
		if(length==listsize-1)
		{
			newbase=new T[listsize*2];
			assert(newbase!=NULL);
			for(int i=0;i<length;i++)
				newbase[i]=elem[i];
			delete []elem;
			elem=newbase;
			listsize*=2;
		}
		p=elem+i;
		q=elem+length;
		for(;q>=p;q--)
			*(q+1)=*q;
		*p=e;
		length++;
		return true;
	}
	bool GetElem(int i,T &e)const
	{
		if(i<1||i>length)
			return false;
		e=elem[i-1];
		return true;
	}
	int ListLength()const
	{
		return length;
	}
	void CreateFromTerminal()
	{
		int num=0;
		T e,*newbase;
		cout<<"input the number:";
		cin>>num;
		do		
		{
			cout<<"input the data:";
			cin>>e;
			elem[length]=e;
			num--;
			length++;
			if(length==listsize)
			{
				newbase=new T[listsize*2];
				assert(newbase!=NULL);
				for(int i=0;i<length;i++)
					newbase[i]=elem[i];
				delete []elem;
				elem=newbase;
				listsize*=2;
			}
		}while( num>0 );
		
	}
	void ListTraverse(void (*visit)(T *))const
	{
		for(int i=0;i<length;i++)
			visit(elem+i);
		cout<<endl;
	}
};
#endif