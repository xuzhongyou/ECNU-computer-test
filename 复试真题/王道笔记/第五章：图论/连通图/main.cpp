#include <iostream>
#include <stdio.h>
using namespace std;
int tree[1001];
int findRoot(int x)
{
    if(tree[x]==-1)
        return x;
    else {
        int tmp=findRoot(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF&&n!=0&&m!=0)
    {
        for(int i=1;i<=n;i++)
            tree[i]=-1;
        while(m--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            a=findRoot(a);
            b=findRoot(b);
            if(a!=b) tree[a]=b;
        }
        int ans=0;
        for(int i=1;i<=n;i++)
            if(tree[i]==-1)
                ans++;
        if(ans==1)
            puts("YES");
        else puts("NO");
        }
    return 0;
}
