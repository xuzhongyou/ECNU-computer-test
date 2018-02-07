#include <iostream>
using namespace std;

int T,W;
int a[2000];
int F[2000][40][3];


void deal()
{
	int i,j,k;

	cin>>T>>W;
	for (i=1;i<=T;++i) cin>>a[i];

	int ans=0;int temp;
	memset(F,0,sizeof(F));
	if (a[1]==1)
	{
		F[1][0][1]=1;
		ans=1;
	}
	else
	{
		F[1][1][2]=1;
		if (W>=1) ans=1;
	}

	for (i=2;i<=T;++i)
	{
		for (k=0;k<=W;++k)
			for (j=1;j<=2;++j)
			{
				if (j==a[i])
				{
					temp=F[i-1][k][j]+1;
					if (k>=1) if (F[i-1][k-1][3-j]+1>temp) temp=F[i-1][k-1][3-j]+1;
				}
				else
				{
					temp=F[i-1][k][j];
				}
				F[i][k][j]=temp;
				if (temp>ans) ans=temp;
			}
	}

	for (k=0;k<=W;++k)
		for (j=1;j<=2;++j) if (F[T][k][j]>ans) ans=F[T][k][j];

	cout<<ans<<endl;
}

int main()
{
	while (!cin.eof())
	deal();

	return 0;
}

