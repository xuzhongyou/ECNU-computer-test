#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<iomanip>
#include<algorithm>
#include<cmath>
using namespace std;
long long dp[2500][1500],weight[2500];
void Init(int n,int k)
{
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=1;j<=k;j++)
            dp[i][j]=0x7fffffff;
    }
    for(i=0;i<=n;i++)
        dp[i][0]=0;
}
int main()
{
    int n,k,i,j;
    while( scanf("%d%d",&n,&k)==2)
    {

        for(i=1; i<=n; i++)
        scanf("%lld",&weight[i]);
        Init(n,k);
        sort(weight+1,weight+n+1);
        for(i=2; i<=n; i++)
        {
            for(j=1; j*2<=i; j++)
                dp[i][j]=min(dp[i-1][j],dp[i-2][j-1] + (weight[i]-weight[i-1])*(weight[i]-weight[i-1]));

        }
        printf("%lld\n",dp[n][k]);
    }
    return 0;
}
