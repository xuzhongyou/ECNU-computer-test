#include <iostream>
#include <stdio.h>
using namespace std;
char maze[101][19];
bool mark[101][19];
int n,m;
int go[4][2]={
{0,1},
{0,-1},
{1,0},
{-1,0}
};
void dfs(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(nx<1||nx>m||ny<1||ny>m)
            continue;
        if(maze[nx][ny]=='N')
            continue;
        if(mark[nx][ny]==true)
            continue;
        mark[nx][ny]=true;
        dfs(nx,ny);
    }
    return ;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d",&m);
            for(int i=1;i<=m;i++)
                scanf("%s",maze[i]+1);
            for(int i=1;i<=m;i++)
                for(int j=1;j<=m;j++)
            {
                mark[i][j]=false;
            }
            int ans=0;
            for(int i=1;i<=m;i++)
                for(int j=1;j<=m;j++)
            {
                if(mark[i][j]==true) continue;
                if(maze[i][j]=='N') continue;
                dfs(i,j);
                ans++;
            }
            printf("%d\n",ans);
        }

    }
    return 0;
}
