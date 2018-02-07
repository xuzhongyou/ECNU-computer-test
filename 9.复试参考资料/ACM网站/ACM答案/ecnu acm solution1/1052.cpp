#include <iostream>
using namespace std;

int w[100];
int p[100];
int N,W;
int f[2000000];

void deal()
{
	scanf("%d%d",&N,&W);
	int i,j,k;

	for (i=1;i<=N;++i) scanf("%d%d",&w[i],&p[i]);

	int ans=0;
	for (i=0;i<=W;++i) f[i]=-1;
	f[0]=0;

	for (k=1;k<=N;++k)
		for (i=W;i-w[k]>=0;--i)
			if ( f[i-w[k]]>=0 ) if ( f[i-w[k]]+p[k]>f[i] ) f[i]=f[i-w[k]]+p[k];

	for (i=0;i<=W;++i) if (f[i]>ans) ans=f[i];

	printf("%d\n",ans);
}

int main()
{
	int t,i;
	scanf("%d",&t);
	for (i=1;i<=t;++i) deal();

	return 0;
}
