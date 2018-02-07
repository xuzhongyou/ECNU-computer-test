#include <iostream>
using namespace std;

long long int p,n;
const int MaxP=9921299;
long long int ans;


//¼ÆËãa^b mod c
long long int deal(long long int a,long long int b,long long int c)
{
	if (a==0) return 0;
	if (a==1) return 1;
	if (b==1) return a % c;

	long long int temp;
	temp=deal(a,b/2,c);
	temp=temp*temp % c;

	if (b % 2==0) return temp;
	else return (temp*a) % c;
}

//extend_euclid(a,b)=a*x+b*y
long long int extended_euclid(long long int a,long long int b,long long int &x,long long int &y)
{
	if (b==0) {x=1,y=0;return a;} 
	else
	{
		long long int res=extended_euclid(b,a%b,x,y);
		long long int t=x;x=y;y=t-(a/b)*y;
		return res;
	}
}


int main()
{
	long long int rx,ry;
	long long int temp;

	while(cin>>p>>n)
	{
		if (p==0 && n==0) break;

		temp=2005*p/extended_euclid(p,2005,rx,ry);
		//cout<<temp<<endl;

		if (n % 2==0)
		{
			ans=deal(p-1,n,temp);
			ans=ans+p-1;
			//ans%=temp;
			ans/=p;
			//ans%=2005;

			cout<<ans<<endl;
		}
		else
		{
			ans=deal(p-1,n,temp);
			ans=ans-p+1;
			//ans%=temp;
			ans/=p;
			cout<<ans<<endl;
		}
	}

	//system("pause");
	return 0;
}
