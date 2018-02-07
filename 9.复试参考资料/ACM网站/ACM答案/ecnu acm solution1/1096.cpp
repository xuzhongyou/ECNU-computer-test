#include <iostream>
#include <cmath>

using namespace std;


int sum[10][10];
int a[10][10];
int K;
int f[20][9][9][9][9];
bool used[20][9][9][9][9];

int area(int x1,int y1,int x2,int y2)
{	
	if (x1>x2 || y1>y2) return 0;

	int ans=sum[x2][y2];
	ans=ans-sum[x1-1][y2];
	ans=ans-sum[x2][y1-1];
	ans=ans+sum[x1-1][y1-1];
	return ans*ans;
}

int d(int k,int x1,int y1,int x2,int y2)
{
	int ans=999999999;
	int temp=999999999;

	if (k==0) return area(x1,y1,x2,y2);
	if (used[k][x1][y1][x2][y2]) return f[k][x1][y1][x2][y2];
	
	int a,b;
	for (a=x1;a<x2;++a)
		for (b=y1;b<y2;++b)
		{
			temp=d(k-1,x1,y1,a,y2)+area(a+1,y1,x2,y2);
			if (temp<ans) ans=temp;

			temp=d(k-1,a+1,y1,x2,y2)+area(x1,y1,a,y2);
			if (temp<ans) ans=temp;

			temp=d(k-1,x1,y1,x2,b)+area(x1,b+1,x2,y2);
			if (temp<ans) ans=temp;

			temp=d(k-1,x1,b+1,x2,y2)+area(x1,y1,x2,b);
			if (temp<ans) ans=temp;
		}

	used[k][x1][y1][x2][y2]=true;
	f[k][x1][y1][x2][y2]=ans;
	return ans;
}


void init()
{
	int i,j,k;
	memset(used,false,sizeof(used));

	for (i=1;i<=8;++i) for (j=1;j<=8;++j) cin>>a[i][j];
	
	memset(sum,0,sizeof(sum));
	sum[1][1]=a[1][1];
	for (j=2;j<=8;++j) sum[1][j]=sum[1][j-1]+a[1][j];
	
	int hangsum=0;
	for (i=2;i<=8;++i)
	{
		hangsum=0;
		for (j=1;j<=8;++j)
		{
			hangsum+=a[i][j];
			sum[i][j]=sum[i-1][j]+hangsum;
		}
	}

	/*	
	for (i=1;i<=8;++i)
	{
		for (j=1;j<=8;++j) cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;

	for (i=1;i<=8;++i)
	{
		for (j=1;j<=8;++j) cout<<sum[i][j]<<" ";
		cout<<endl;
	}
	*/
	
	double avex=(double)sum[8][8]/(double)K;

	double ans=(double)d(K-1,1,1,8,8)/(double)K- avex*avex;
	ans=sqrt(ans);

	printf("%.3lf\n",ans);
}



int main()
{
	while (cin>>K)
	init();

	//system("pause");
	return 0;
}
