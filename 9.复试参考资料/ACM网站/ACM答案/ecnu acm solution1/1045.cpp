#include <iostream>
#include <algorithm>
using namespace std;

int N,L;
int num[100001];

void init()
{
	int i;
	for (i=0;i<N;++i) scanf("%d",&num[i]);

	int ans=N;
	sort(num,num+N);

	int head=0,tail=N-1;
	while (head<tail)
	{
		if (num[head]+num[tail]<=L)
		{
			head++;
			tail--;
			ans--;
		}
		else
			tail--;
	}
	cout<<ans<<endl;
}

int main()
{
	while (scanf("%d%d",&N,&L)!=EOF) init();
	return 0;
}

