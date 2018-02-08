#include <iostream>
#include <stdio.h>
#define INF 0x7fffffff
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
struct E{
    int weight;
    int value;
}list[101];
int dp[1001];
int main()
{
    int s,n;
    while(scanf("%d%d",&s,&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&list[i].weight,&list[i].value);
        for(int i=1;i<=s;i++)
            dp[i]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=s;j>=list[i].weight;j--)
                dp[j]=max(dp[j],dp[j-list[i].weight]+list[i].value);
        }
        printf("%d\n",dp[s]);
    }
    return 0;
}
