#include <iostream>

using namespace std;
#include <stdio.h>
struct E{
    int weight;
    int value;
}list[2001];
int dp[101];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int s,n;
        scanf("%d%d",&s,&n);
        int cnt=0;
        for(int i=1;i<=n;i++)
        {
            int v,w,k;
            scanf("%d%d%d",&w,&v,&k);
            int c=1;
            while(k-c>0)
            {
                k-=c;
                list[++cnt].weight=c*w;
                list[cnt].value=c*v;
                c*=2;
            }
            list[++cnt].weight=w*k;
            list[cnt].value=v*k;
        }
        for(int i=1;i<=s;i++)
            dp[i]=0;
        for(int i=1;i<=cnt;i++)
            for(int j=s;j>=list[i].weight;j--)
        {
            dp[j]=max(dp[j],dp[j-list[i].weight]+list[i].value);
        }
        printf("%d\n",dp[s]);
    }
    return 0;
}
