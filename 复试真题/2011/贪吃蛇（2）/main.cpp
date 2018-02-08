#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int F(int n)
{
    if(n==0) return 0;
    else if(n==1) return 1;
    else {
        return F(n-1)+F(n-2);
    }
}

int go[][2]={
    {-1,0},
    {0,1},
    {1,0},
    {0,-1}
};
int main()
{
    int n,m,t;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        char a[101][101];
        for(int i=0;i<n;i++)
            scanf("%s",a[i]);
        int ans=0,nx=0,ny=0,cnt=0;
        for(int i=0;i<=t;i++)
        {
            //printf("%d %d %d\n",i,nx,ny);
            if(a[nx][ny]!='.')
            {
                int tmp=a[nx][ny]-'0';
                ans+=tmp;
                //printf("%c ",a[nx][ny]);
            }
            int x=nx+go[F(cnt)%4][0],y=ny+go[F(cnt)%4][1];
            while(x<0||x>=n||y<0||y>=m)
            {
                cnt++;
                x=nx+go[F(cnt)%4][0];
                y=ny+go[F(cnt)%4][1];
            }
            nx=x;
            ny=y;
           // printf("%d %d %d\n",cnt,nx,ny);
        }
        printf("%d\n",ans);

    }
    return 0;
}
