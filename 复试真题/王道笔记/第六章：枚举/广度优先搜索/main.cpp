#include <iostream>
#include <queue>
#include <stdio.h>

using namespace std;

bool mark[50][50][50];
int maze[50][50][50];
struct N{
    int x,y,z;
    int t;
};
queue<N> Q;
int go[6][3]={
    {1,0,0},
    {-1,0,0},
    {0,1,0},
    {0,-1,0},
    {0,0,1},
    {0,0,-1}
};

int BFS(int a,int b,int c)
{
    while(Q.empty()==false){
        N now=Q.front();
        Q.pop();
        for(int i=0;i<6;i++)
        {
            int nx=go[i][0]+now.x;
            int ny=go[i][1]+now.y;
            int nz=go[i][2]+now.z;
            if(nx<0||nx>=a||ny<0||ny>=b||nz<0||nz>=c)
                continue;
            if(maze[nx][ny][nz]==1)
                continue;
            if(mark[nx][ny][nz]==true)
                continue;
            N temp;
            temp.x=nx;
            temp.y=ny;
            temp.z=nz;
            temp.t=now.t+1;
            Q.push(temp);
            mark[nx][ny][nz]=true;
            if(nx==a-1&&ny==b-1&&nz==c-1)
                return temp.t;
        }
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a,b,c,t;
        scanf("%d%d%d%d",&a,&b,&c,&t);
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                for(int k=0;k<c;k++)
                {
                    scanf("%d",&maze[i][j][k]);
                    mark[i][j][k]=false;
                }
            }
        }
        while(Q.empty()==false) Q.pop();
        mark[0][0][0]=true;
        N tmp;
        tmp.x=tmp.t=tmp.y=tmp.z=0;
        Q.push(tmp);
        int rec=BFS(a,b,c);
        if(rec<=t) printf("%d\n",rec);
        else printf("-1\n");
    }
    return 0;
}
