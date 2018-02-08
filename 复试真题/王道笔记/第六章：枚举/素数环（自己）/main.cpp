#include <iostream>
#include <stdio.h>

using namespace std;

int ans[22];
bool hash[22];
int n;
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41};
bool judge(int x)
{
    for(int i=0;i<=12;i++)
    {
        if(x==prime[i])
            return true;
    }
    return false;
}
void check()
{
    if(judge(ans[n]+ans[1])==false)
        return;
    for(int i=1;i<=n;i++)
    {
        if(i!=1)
            printf(" ");
        printf("%d",ans[i]);
    }
    printf("\n");
}

void dfs(int num)
{
    if(num>1)
        if(judge(ans[num]+ans[num-1])==false)
            return;
    if(num==n)
    {
        check();
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(hash[i]==false)
        {
            hash[i]=true;
            ans[num+1]=i;
            dfs(num+1);
            hash[i]=false;
        }
    }
}
int main()
{
    int cas=0;
    while(scanf("%d",&n)!=EOF)
    {
        cas++;
        ans[1]=1;
        hash[1]=true;
        for(int i=2;i<22;i++)
            hash[i]=false;
        printf("Case %d:\n",cas);
        dfs(1);
        printf("\n");
    }
    return 0;
}
