#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
#define N 100
struct E{
    int x,y;
}edge[100];
int tree[N];
int findRoot(int x)
{
    if(tree[x]==-1) return x;
    else {
        int tmp=findRoot(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}

int distance1(int i,int j)
{
    int dis=(edge[i].x-edge[j].x)*(edge[i].x-edge[j].x)+(edge[i].y-edge[j].y)*(edge[i].y-edge[j].y);
    return dis;
}

int main()
{
    int n,r;
    while(scanf("%d%d",&n,&r)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            tree[i]=-1;
            scanf("%d%d",&edge[i].x,&edge[i].y);
        }
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                //printf("(%d,%d)=%d\n",i,j,distance1(i,j));
                if(distance1(i,j)<=r*r)
                {
                    int a=findRoot(i),b=findRoot(j);
                    if(a!=b)
                        tree[a]=b;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(tree[i]==-1)
                ans++;
        printf("%d\n",ans);
    }
    cout << "Hello world!" << endl;
    return 0;
}
