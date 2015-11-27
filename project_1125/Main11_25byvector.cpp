#include "C.h"
void out(int a)
{
	cout<<a<<" ";
}

void main()
{
	vector<int> a;
	vector<int>::iterator ip;
	vector<int>::const_iterator cip;
	for(int i=0;i<5;i++)
		a.push_back(i);
	for_each(a.begin(),a.end(),out);
	cout<<endl;

	ip=a.begin()+2;
	a.insert(ip,9);
	for(cip=a.begin();cip!=a.end();cip++)
		cout<<*cip<<" ";
	cout<<endl;
	a.erase(a.begin()+4);
	for_each(a.begin(),a.end(),out);
	cout<<endl;
	cout<<a.front()<<endl;
	cout<<a.back()<<endl;
	sort(a.begin(),a.end());
	for_each(a.begin(),a.end(),out);
	cout<<endl;
	reverse(a.begin(),a.end());
	for_each(a.begin(),a.end(),out);
	cout<<endl;
}