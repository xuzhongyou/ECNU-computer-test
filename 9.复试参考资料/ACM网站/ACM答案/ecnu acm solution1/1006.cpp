

#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

int prime[10000];
int psquare[10000];
int ps;
int a,b;

int num[20];

void dealp();
bool IsPrime(int);

int ans[1000001];


//生成质数表
void dealp()
{
	ps=0;
	bool ok[20000];
	memset(ok,true,sizeof(ok));

	ok[1]=false;
	int i,j,k;
	i=1;
	while (i<=2000)
	{
		while (!ok[i]) i++;
		j=i+i;
		while (j<=2000)
		{
			ok[j]=false;
			j+=i;
		}
		i++;
		if (i>=2000) break;
	}

	for (i=2;i<=2000;++i) if (ok[i]) prime[ps++]=i;
	for (i=0;i<ps;++i) psquare[i]=prime[i]*prime[i];
}

//判断一个数是不是质数
bool IsPrime(int x)
{
	int i,j;
	for (i=0;i<ps;++i)
	{
		if (psquare[i]>x) break;
		if (x % prime[i] ==0) return false;
	}
	return true;
}

void deal()
{
	ans[0]=0;
	ans[1]=0;
	ans[2]=1;

	int i;
	for (i=3;i<=1000000;++i)
	{
		if (IsPrime(i)) ans[i]=ans[i-1]+1;
		else ans[i]=ans[i-1];
	}
}



int main()
{
	dealp();
	deal();

	int a,b;
	while (cin>>a>>b)
	{
		cout<<ans[b]-ans[a-1]<<endl;
	}

	system("pause");
	return 0;
}
