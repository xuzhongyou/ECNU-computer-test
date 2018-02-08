#include <iostream>
#include <stdio.h>
#define INF 0x7fffffff
using namespace std;
int min(int a,int b){return a<b?a:b;}
struct E{
    int weight;
    int value;
}list[501];
int dp[10001];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s,tmp;
        scanf("%d%d",&tmp,&s);
        s-=tmp;
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&list[i].value,&list[i].weight);
        }
        for(int i=0;i<=s;i++)
        {
            dp[i]=INF;
        }
        dp[0]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=list[i].weight;j<=s;j++)
            {
                if(dp[j-list[i].weight]!=INF)
                    dp[j]=min(dp[j],dp[j-list[i].weight]+list[i].value);
            }
        }
        if(dp[s]!=INF)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[s]);
        else
            puts("This is impossible.");
    }
    return 0;
}
