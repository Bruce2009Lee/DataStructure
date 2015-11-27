#include <iostream>
using namespace std;
void f1(void);
void f2(void);

const float pi=3.14f;
float f;
float f1(float r)
{
	f=r*r*pi;
	return f;
}

float& f2(float r)
{
	f=r*r*pi;
	return f;
}

int main()
{
	float f1(float=5);
	float &f2(float=5);
	float& b=f2();

	char* str2="AAA";
	str2[0]='B';
	char str3[]={'H','e','l','l','o'}; 

	cout<<str2<<endl;
	cout<<str3<<endl;

	cout<<"b="<<b<<endl;
	cout<<"main exit...\n";
}

void f1()
{
	cout<<"calling f1()...\n";
}

void f2()
{
	cout<<"calling f2()...\n";
}