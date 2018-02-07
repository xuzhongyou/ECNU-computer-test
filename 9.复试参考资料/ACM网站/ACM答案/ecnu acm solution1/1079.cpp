#include <iostream>
using namespace std;

int c[50][50];
int N;

void init()
{
	int i,j,k;
	c[1][1]=1;
	c[1][0]=0;

	for (i=2;i<=30;++i)
	{
		c[i][1]=1;
		c[i][i]=1;
		for (j=2;j<i;++j) c[i][j]=c[i-1][j]+c[i-1][j-1];
	}
}

int main()
{
	init();
	int i,j;
	while (cin>>N)
	{
		if (N==0) break;
		for (i=1;i<=N;++i)
		{
			for (j=1;j<=i-1;++j) printf("%d ",c[i][j]);
			printf("%d\n",c[i][i]);
		}
		printf("\n");
	}

	return 0;
}
