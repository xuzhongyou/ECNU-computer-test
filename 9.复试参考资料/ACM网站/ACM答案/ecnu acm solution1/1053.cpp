#include <iostream>
using namespace std;

int N;
int X;
int F[1000000];
int sum;
int num[200];

void deal()
{
	int i,j,k;
	scanf("%d%d",&N,&X);
	sum=0;
	for (i=1;i<=N;++i)
	{
		scanf("%d",&num[i]);
		sum+=num[i];
	}

	F[0]=1;
	for(i=1;i<=X;++i) F[i]=0;

	for (k=1;k<=N;++k)
		for (j=X;j>=num[k];j--)
			F[j]+=F[j-num[k]];

	printf("%d\n",F[X]);
}

int main()
{
	int t,i;
	scanf("%d",&t);

	for (i=1;i<=t;++i) deal();

	return 0;
}

