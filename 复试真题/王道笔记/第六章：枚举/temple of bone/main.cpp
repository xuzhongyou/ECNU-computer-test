#include <iostream>
#include <stdio.h>
using namespace std;
char maze[8][8];
bool success;
int n,m,t;
int go[4][2]={
    {1,0},
    {-1,0},
    {0,1},
    {0,-1}
};
void dfs(int x,int y,int time)
{
    for(int i=0;i<4;i++)
    {
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(nx>n||nx<1||ny>m||ny<1)
            continue;
        if(maze[nx][ny]=='X')
            continue;
        if(maze[nx][ny]=='D')
        {
            if(time+1==t)
            {
                success=true;
                return;
            }
            else continue;
        }
        maze[nx][ny]='X';
        dfs(nx,ny,time+1);
        maze[nx][ny]='.';
        if(success)
            return ;
    }
}
int main()
{
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        if(n==0&&m==0&&t==0)
            break;
        for(int i=1;i<=n;i++)
            scanf("%s",maze[i]+1);
        success=false;
        int sx,sy;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            if(maze[i][j]=='D')
        {
            sx=i;
            sy=j;
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            if(maze[i][j]=='S'&&(i+j)%2==(t%2+(sx+sy)%2)%2)
        {
            maze[i][j]='X';
            dfs(i,j,0);
        }
        puts(success==true?"YES":"NO");
    }
    return 0;
}
