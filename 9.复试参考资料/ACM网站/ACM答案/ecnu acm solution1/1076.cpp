#include <iostream>
using namespace std;

int N;
int times[100002];
int a,b;


void deal()
{
	memset(times,0,sizeof(times));
	int now;
	int i;

	for (i=1;i<=N;++i)
	{
		scanf("%d%d",&a,&b);
		times[a]++;
		times[b+1]--;
	}

	now=0;
	for (i=1;i<=N-1;++i)
	{
		now+=times[i];
		printf("%d ",now);
	}
	now+=times[N];
	printf("%d\n",now);
}



int main()
{
	while (scanf("%d",&N)!=EOF)
	{
		if (N==0) break;
		deal();
	}

	return 0;
}
