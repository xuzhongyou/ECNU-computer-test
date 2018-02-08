#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edge[1000001];
priority_queue<int,vector<int>,greater<int> > Q;//ø…“‘ac
struct E{
    int a1,b1;
    bool operator < (const E &A) const
    {
        if(a1==A.a1)
            return b1<A.b1;
        else return a1<A.a1;
    }
}e[1000001];
int a[1001];
int main()
{
    int inDegree[1001];
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        for(int i=0;i<n;i++)
        {
            inDegree[i]=0;
            edge[i].clear();
        }
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&e[i].a1,&e[i].b1);
        }
        sort(e,e+m);
        for(int i=0;i<m;i++)
        {
            int a,b;
            a=e[i].a1;
            b=e[i].b1;
            inDegree[b]++;
            edge[a].push_back(b);
        }
        while(Q.empty()==false) Q.pop();
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0)
                Q.push(i);
        }
        int cnt=0;//count
        while(Q.empty()==false)
        {
            int nowP=Q.top();
            Q.pop();
            a[cnt]=nowP;
            cnt++;
            for(int i=0;i<edge[nowP].size();i++)
            {
                inDegree[edge[nowP][i]]--;
                if(inDegree[edge[nowP][i]]==0)
                {
                    Q.push(edge[nowP][i]);
                }

            }
        }
        if(cnt==n)
        {
            puts("YES");
            for(int i=0;i<n-1;i++)
                printf("%d ",a[i]);
            printf("%d\n",a[n-1]);
        }

        else
        {
            puts("NO");
            printf("%d\n",n-cnt);
        }
    }
    return 0;
}
