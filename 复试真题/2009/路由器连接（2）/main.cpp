#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;
#define N 1001
int Tree[N];
int findRoot(int x)
{
    if(Tree[x]==-1)
        return x;
    else {
        int tmp=findRoot(Tree[x]);
        Tree[x]=tmp;
        return tmp;
    }
}

struct Edge{
    int a,b;
    int cost;
    bool operator < (const Edge &A) const
    {
        return cost<A.cost;
    }
}edge[15001];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(!n&&!m)
            break;
        for(int i=1;i<=m;i++)
            scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].cost);
        sort(edge+1,edge+m+1);
        for(int i=1;i<=n;i++)
            Tree[i]=-1;
        int ans=0;
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
        printf("%d\n",ans);
}
    cout << "Hello world!" << endl;
    return 0;
}
