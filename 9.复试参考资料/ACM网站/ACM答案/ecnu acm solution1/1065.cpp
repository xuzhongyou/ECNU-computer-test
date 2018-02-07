#include <iostream>
using namespace std;

int sum[1200][1200];
int a[1200][1200];

int n,m;
int Left[1200];
int Right[1200];
int high[1200];
int Leftmost,Rightmost;

int Getsum(int l,int r,int i,int height)
{
	return (sum[i][r]+sum[i-height][l-1]-sum[i][l-1]-sum[i-height][r]);
}

void deal()
{
	int i,j,k;
	memset(high,0,sizeof(high));
	for (i=1;i<=m;++i) 
	{
		Left[i]=1;
		Right[i]=m;
	}
	int ans=0;
	
	for (i=1;i<=n;++i)
	{
		Leftmost=1;
		Rightmost=m;

		for (j=1;j<=m;++j)
		{
			if (a[i][j]==0)
			{
				high[j]=0;
				Left[j]=1;
				Right[j]=m;
				Leftmost=j+1;
			}
			else
			{
				high[j]++;
				if (Left[j]<Leftmost) Left[j]=Leftmost;
			}
		}

		for (j=m;j>=1;--j)
		{
			if (a[i][j]==0)
			{
				Rightmost=j-1;
			}
			else
			{
				if (Right[j]>Rightmost) Right[j]=Rightmost;
				if (Getsum(Left[j],Right[j],i,high[j])>ans) ans=Getsum(Left[j],Right[j],i,high[j]);

			}
		}
	}
	
	cout<<ans<<endl;
}



void init()
{
	int i,j,k;


	memset(sum[0],0,sizeof(sum[0]));
	int nowsum;
	for (i=1;i<=n;++i)
	{
		nowsum=0;
		for (j=1;j<=m;++j)
		{
			scanf("%d",&a[i][j]);
			nowsum+=a[i][j];
			sum[i][j]=sum[i-1][j]+nowsum;
		}
	}

/*
	for (i=1;i<=n;++i)
	{
		for (j=1;j<=m;++j) cout<<a[i][j]<<" ";
		cout<<endl;
	}

	cout<<endl;

	for (i=1;i<=n;++i)
	{
		for (j=1;j<=m;++j) cout<<sum[i][j]<<" ";
		cout<<endl;
	}
*/
	deal();

}

int main()
{
	while (scanf("%d%d",&n,&m)!=EOF)
		init();

	return 0;
}


