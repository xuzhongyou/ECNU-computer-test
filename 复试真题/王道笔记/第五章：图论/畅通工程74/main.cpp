#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#define N 101
int Tree[N];
int findRoot(int x)
{
    if(Tree[x]==-1) return x;
    else{
        int temp=findRoot(Tree[x]);
        Tree[x]=temp;
        return temp;
    }
}
struct Edge{
    int a,b;
    int cost;
    bool operator <(const Edge &A) const{
    return cost<A.cost;
    }
}edge[6000];
int main()
{
    int n,m;
    while(scanf("%d%d",&m,&n)!=EOF&&n!=0&&m!=0)
    {
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        }
        for(int i=1;i<=n;i++)
            Tree[i]=-1;
        sort(edge+1,edge+1+m);
        int ans=0,cnt=0;
        for(int i=1;i<=m;i++)
        {
            int a=findRoot(edge[i].a);
            int b=findRoot(edge[i].b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=edge[i].cost;
            }
        }
        for(int i=1;i<=n;i++)
        {
                if(Tree[i]==-1)
                    cnt++;
                //printf("%d %d\n",i,Tree[i]);
        }
        if(cnt>1)
        {
            printf("?\n");
            continue;
        }
        printf("%d\n",ans);
    }
    return 0;
}
