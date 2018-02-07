#include <iostream>
using namespace std;

long long int f[2000];

int two(int n)
{
	return 1+(1+n)*n/2;
}


void deal()
{
	f[0]=1;
	f[1]=2;
	f[2]=4;
	int i;

	for (i=3;i<=1000;++i) f[i]=f[i-1]+two(i-1);

}

int main()
{
	deal();

	int N;
	while (cin>>N) 
	{
		if (N==0) break;
		cout<<f[N]<<endl;
	}

	return 0;
}
