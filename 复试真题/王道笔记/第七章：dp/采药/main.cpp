#include <iostream>
#include <stdio.h>
#define INF 0x7fffffff
int max(int x,int y){return x>y?x:y;}
using namespace std;
struct E{
    int weight;
    int value;
}list[101];
int dp[101][1001];
int main()
{
    int s,n;
    while(scanf("%d%d",&s,&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&list[i].weight,&list[i].value);
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=s;j>=list[i].weight;j--)
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-list[i].weight]+list[i].value);
            for(int j=list[i].weight-1;j>=0;j--)
                dp[i][j]=dp[i-1][j];
        }
        printf("%d\n",dp[n][s]);

    }
    return 0;
}
