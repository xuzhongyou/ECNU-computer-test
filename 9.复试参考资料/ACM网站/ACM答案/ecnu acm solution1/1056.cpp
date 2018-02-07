#include <iostream>
using namespace std;

int extended_euclid(int a,int b,int & x,int & y)
{
	if (b==0) {x=1,y=0;return a;}
	else
	{
		int res=extended_euclid(b,a%b,x,y);
		int t=x;x=y;y=t-(a/b)*y;
		return res;
	}
}

int a,b,m;

int main()
{
	int i,j,k;
	int d;
	int x,y;

	while (cin>>a>>b>>m)
	{
		d=extended_euclid(a,m,x,y);
		if (b % d==0)
		{
			cout<<x<<endl;
		}
		else
			cout<<"No Answer."<<endl;
	}
	return 0;
}
