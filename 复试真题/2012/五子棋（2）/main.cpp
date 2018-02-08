#include <iostream>
#include <stdio.h>
using namespace std;
#define N 5
char graph[N][N];
int go[4][2]={
    {1,0},
    //-1,0,
    {0,1},
    //0,-1,
    {1,1},
    //-1,-1,
    {1,-1}
    //-1,1
};
bool isBlack(int x,int y)
{
    return 0<=x&&x<N&&0<=y&&y<N&&graph[x][y]=='b';
}
bool checkLine(int x,int y,int line)
{
    graph[x][y]='b';
    int cnt=1,flag1=1,flag2=1;
    int dx=x,dy=y,ux=x,uy=y;
    while(cnt<=5)
    {
        if(flag1==1)
        {
            dx=dx+go[line][0];
            dy=dy+go[line][1];
        }
        if(flag2==1)
        {
            ux=ux-go[line][0];
            uy=uy-go[line][1];
        }
        if(isBlack(dx,dy))
            cnt++;
        else flag1=0;
        if(isBlack(ux,uy))
            cnt++;
        else flag2=0;

        if(!flag1&&!flag2)
            break;
    }
    graph[x][y]='.';
    if(cnt==5)
        return true;
    else return false;
}
int main()
{
    for(int i=0;i<N;i++)
        scanf("%s",graph[i]);
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
    {
        if(graph[i][j]=='.')
        {
            for(int k=0;k<4;k++)
            {
                //int flag=0;
                if(checkLine(i,j,k))
                {

                    printf("(%d,%d)\n",i,j);
                    break;
                }

            }
        }
    }
    //cout << "Hello world!" << endl;
    return 0;
}
