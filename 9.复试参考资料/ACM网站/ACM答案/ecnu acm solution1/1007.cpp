#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

double const pi=3.14159265358979;
double const e=2.718281828;

int F[2001];
int logdiv[11];

void deal()
{
	int i,j,k;
	double ans=0;

	F[0]=1;
	F[1]=1;

	for (k=2;k<=1000;++k)
	{
		ans+=log10((double)k);
		ans=ans-(int)ans;
		F[k]=(int)pow(10,ans);
	}
}

void init()
{
	int N;
	double ans;

	while (cin>>N)
	{
		if (N<=1000)
			cout<<F[N]<<endl;
		else
		{
			ans=0.5*log10((double)N*2.0*pi);
			ans+=(double)N*log10( (double)N/e );
			ans=ans-(int)ans;
			cout<<(int)pow(10,ans)<<endl;
		}
	}
}

int main()
{
	deal();

	init();

	return 0;
}