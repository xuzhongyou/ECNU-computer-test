#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int n,m;
struct Matrix{
    int d[2][2];
}ans,ori;

Matrix muti(Matrix a,Matrix b)
{
    Matrix c;
    memset(c.d,0,sizeof(c.d));
    c.d[0][0]=(a.d[0][0]*b.d[0][0]+a.d[0][1]*b.d[1][0])%m;
    c.d[0][1]=(a.d[0][0]*b.d[0][1]+a.d[0][1]*b.d[1][1])%m;
    c.d[1][0]=(a.d[1][0]*b.d[0][0]+a.d[1][1]*b.d[1][0])%m;
    c.d[1][1]=(a.d[1][0]*b.d[0][1]+a.d[1][1]*b.d[1][1])%m;
    return c;
}

void solve()
{
    int k=n*2;
    while(k)
    {
        if(k&1)
            ans=muti(ori,ans);
        k>>=1;
        ori=muti(ori,ori);
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        ans.d[0][1]=ans.d[1][0]=0;
        ans.d[1][1]=ans.d[0][0]=1;
        ori.d[0][0]=ori.d[0][1]=ori.d[1][0]=1;
        ori.d[1][1]=0;
        solve();
        //printf("%d %d\n",ans.d[0][0],ans.d[0][1]);
        //printf("%d %d\n",ans.d[1][0],ans.d[1][1]);
        printf("%d\n",ans.d[0][1]);
    }
    return 0;
}
