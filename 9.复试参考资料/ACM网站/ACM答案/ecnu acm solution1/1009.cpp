#include <iostream>
using namespace std;

const int MaxN=100;
long long int F[MaxN+1][MaxN+1];
long long int ans[MaxN+1];
int N;


//F[i][j] 表示将整数I拆分成最大数为J的方案个数
void init()
{
	int i,j,k;
	memset(F,0,sizeof(F));

	for (i=0;i<=MaxN;++i) F[0][i]=1;

	for (i=1;i<=MaxN;++i)
		for (j=1;j<=MaxN;++j)
			for (k=1;k<=j;++k)
				if (i-k>=0) F[i][j]+=F[i-k][k];

}

int main()
{
	init();

	while (scanf("%d",&N)!=EOF)
	{
		printf("%d\n",F[N][N]);
	}

	return 0;
}
