#include <iostream>
#include <stdio.h>
using namespace std;

int go[4][2]={
    {0,1},
    {1,0},
    {0,-1},
    {-1,0}
};

int main()
{
    int T;

    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            int a[100][100]={0};
            int n,x=1,y=1,cnt=0;
            scanf("%d",&n);
            for(int i=1;i<=n*n;i++)
            {
                a[x][y]=i;
                int nx=x,ny=y;
                nx+=go[cnt][0];
                ny+=go[cnt][1];
                if(nx<1||nx>n||ny<1||ny>n||a[nx][ny]!=0)
                {
                    cnt++;
                    cnt=cnt%4;
                    nx=x;
                    ny=y;
                    nx+=go[cnt][0];
                    ny+=go[cnt][1];
                }
                x=nx;
                y=ny;
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                {
                    printf("%d",a[i][j]);
                }
                printf("\n");
            }
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
