#include <iostream>
#include <ctime>
using namespace std;
#include <stdio.h>
#include <string.h>
int F[2100001];
bool cal[2100001];


int deal(long long int x)
{
	if (x>1000000)
	{
		if ((x & 1) ==0) return deal(x>>1)+1; // 偶数
		else return deal(3*x+1)+1;  //奇数
	}
	else
	{
		if (cal[x]) return F[x];
		int ans;
		if ((x & 1)==0) ans=deal(x>>1)+1;
		else ans=deal(3*x+1)+1;

		cal[x]=true;
		F[x]=ans;
		return ans;
	}
}

void init()
{
	F[1]=1;
	memset(cal,false,sizeof(cal));
	cal[1]=true;

 	int i;
	for (i=2;i<=1000000;++i)
	{
		if ((i & 1)==0) F[i]=F[i>>1]+1; //偶数
		else F[i]=deal(i);  //奇数
	}
}


int a,b;
int start,stop;


int main()
{
	init();

	int max=0;
	int i;
	while (scanf("%d%d",&a,&b)!=EOF)
	{
		if (a>b) {start=b;stop=a;}
		else {start=a;stop=b;}

		max=0;
		for (i=start;i<=stop;++i) if (F[i]>max) max=F[i];
		printf("%d %d %d\n",a,b,max);
	}

	return 0;
}


