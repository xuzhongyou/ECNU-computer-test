#include <iostream>
#include <stdio.h>
using namespace std;
int max(int a,int b)
{
    return a>b?a:b;
}
int list[101];
int dp1[101];
int dp2[101];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d",&list[i]);
        for(int i=1;i<=n;i++)
        {
            int tmax=1;
            for(int j=1;j<i;j++)
            {
                if(list[j]<list[i])
                    tmax=max(tmax,dp1[j]+1);
            }
            dp1[i]=tmax;
        }
        for(int i=n;i>=1;i--)
        {
            int tmax=1;
            for(int j=n;j>i;j--)
            {
                if(list[j]<list[i])
                    tmax=max(tmax,dp2[j]+1);
            }
            dp2[i]=tmax;
        }
        int tmax=1;
        for(int i=1;i<=n;i++)
        {
            tmax=max(tmax,dp1[i]+dp2[i]);
        }
        printf("%d\n",n-tmax+1);

    }

    return 0;
}
