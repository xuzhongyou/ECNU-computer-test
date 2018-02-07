#include <iostream>
#include <fstream>
#include <string>
using namespace std;

//ifstream fin("1.in");

struct Num
{
	int num[1000];
	int len;

	void reset(string & x)
	{
		len=x.length();
		memset(num,0,sizeof(num));
		int i;
		for (i=0;i<len;++i) num[i]=x[len-1-i]-'0';
	}

	Num operator+(Num & x)
	{
		Num temp;
		memset(temp.num,0,sizeof(temp.num));
		if (this->len>x.len) temp.len=len; else temp.len=x.len;

		int i,j=0,k;
		for (i=0;i<temp.len;++i)
		{
			temp.num[i]=num[i]+x.num[i]+j;
			j=temp.num[i] / 10;
			temp.num[i] %=10;
		}

		if (j>0) 
		{
			temp.num[temp.len]=j;
			temp.len++;
		}

		return temp;
	}

	void operator=(const Num & x)
	{
		memset(num,0,sizeof(num));
		len=x.len;
		int i;
		for (i=0;i<len;++i) num[i]=x.num[i];
	}

	void print()
	{
		int i;
		for (i=len-1;i>=0;--i) cout<<num[i];
		cout<<endl;
	}

}A,B,C;


string a,b;

void init()
{
	while(cin>>a>>b)
	{
		A.reset(a);
		B.reset(b);

		C=A+B;
		C.print();
	}

}

int main()
{	
	init();

	//system("pause");
	return 0;
}
