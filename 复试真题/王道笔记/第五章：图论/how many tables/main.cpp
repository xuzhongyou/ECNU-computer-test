#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int tree[1001];
int findRoot(int x)
{
    if(tree[x]==-1) return x;
    else {
        int tmp=findRoot(tree[x]);
        tree[x]=tmp;
        return tmp;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            for(int i=1;i<=a;i++)
            {
                tree[i]=-1;
            }

            while(b--)
            {
                int x,y;
                scanf("%d%d",&x,&y);
                x=findRoot(x);
                y=findRoot(y);
                if(x!=y)
                {
                    tree[x]=y;
                }
            }
            int ans=0;
            for(int i=1;i<=a;i++)
                if(tree[i]==-1)
                    ans++;
            printf("%d\n",ans);
        }
    }
    return 0;
}
