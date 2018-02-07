#include <iostream>
using namespace std;\

const int MaxN=150;
int num[MaxN][MaxN];

void init()
{
	int now=0;
	int i,j;
	for (i=1;i<=105;++i)
	{
		for (j=1;j<=i;++j) 
		{
			now++;
			num[i+1-j][j]=now;
		}
	}
}


int main()
{
	init();

	int cases=0;
	int n;
	int i,j;

	while (cin>>n)
	{
		if (n<=0) break;
		cases++;

		printf("Case %d:\n",cases);

		for (i=1;i<=n;++i)
		{
			for (j=1;j<=n-i;++j) printf("%d ",num[i][j]);
			printf("%d\n",num[i][n-i+1]);
		}
		printf("\n");
	}

	return 0;
}

