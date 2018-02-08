#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>//abs在这里
using namespace std;

int dx[]={-1,0,1,0};//上右下左
int dy[]={0,1,0,-1};

int N,M,T;
int word;
int di,dj;
int si,sj;
bool is;
char map[10][10];
void dfs(int si,int sj,int t)
{
    if(si<1||sj<1||si>N||sj>M||t>T||is)
        return;
    if(si==di&&sj==dj&&t==T)
    {
        is=true;
        return;
    }
        if ((abs(di-si)+abs(dj-sj))%2!=(T-t)%2) return ;//必须剪枝 当走的步数与T奇偶性不同的时候，也必定不可逃脱，此时可以退出深搜；
    for(int i=0;i<4;i++)
    {
        if(map[si+dx[i]][sj+dy[i]]!='X')
        {
            map[si+dx[i]][sj+dy[i]]='X';
            dfs(si+dx[i],sj+dy[i],t+1);
            map[si+dx[i]][sj+dy[i]]='.';
        }
    }
    return;

}
int main()
{
    int i,j;
    while(~scanf("%d%d%d",&N,&M,&T)&&N!=0)
    {
        word=0;
        getchar();
        for(i=1;i<=N;i++)
        {
            for(j=1;j<=M;j++)
            {
                scanf("%c",&map[i][j]);
                if(map[i][j]=='S')
                {
                    si=i;sj=j;
                }
                if(map[i][j]=='D')
                {
                    di=i;dj=j;
                }
                if(map[i][j]=='X')
                {
                    word++;
                }
            }
            getchar();
        }
        is=false;
        if(N*M-word<T)
            is=false;
        else{
            map[si][sj]='X';
            dfs(si,sj,0);

        }
        if(is)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
