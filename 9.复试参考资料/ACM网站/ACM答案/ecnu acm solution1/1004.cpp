#include <iostream>
using namespace std;

int N;
int num[60000];
int sum[60000];
int F[4][60000];
bool marked[4][50001];
int W;

int deal(int K,int Now)
{
	if (K*W>=Now) return sum[Now];
	if (K<=0 || Now<=0) return 0;
	if (marked[K][Now]) return F[K][Now];

	F[K][Now]=max(deal(K,Now-1),deal(K-1,Now-W)+sum[Now]-sum[Now-W]);
	marked[K][Now]=true;
	return F[K][Now];
}

void init()
{
	scanf("%d",&N);
	int i;
	sum[0]=0;
	for (i=1;i<=N;++i)
	{
		scanf("%d",&num[i]);
		sum[i]=sum[i-1]+num[i];
	}
	scanf("%d",&W);
	memset(marked,false,sizeof(marked));
	cout<<deal(3,N)<<endl;
}


int main()
{
	int t,i;
	cin>>t;

	for (i=1;i<=t;++i) init();
	return 0;
}
