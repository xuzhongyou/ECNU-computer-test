#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAX_N=1001;
vector <int> G[MAX_N],topOrder;

int vertex,edge,inDegree[MAX_N]={0};
int num;

bool topologicalsort(){
    num=0;
    priority_queue<int,vector<int>,greater<int> > q;
    for(int i=0;i<vertex;i++)
    {
        if(inDegree==0)
            q.push(i);
    }
    while(!q.empty())
    {
        int u=q.top();
        topOrder.push_back(u);
        q.pop();
        for(int i=0;i<G[u].size();i++)
        {
            int v=G[u][i];
            inDegree[v]--;
            if(inDegree[v]==0)
                q.push(v);
        }
        num++;
    }
    if(num==vertex) return true;
    else return false;
}
int main()
{
    while(scanf("%d%d",&vertex,&edge)!=EOF)
    {
        if(vertex==0&&edge==0)
            break;
        for(int i=0;i<edge;i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            inDegree[v]++;
            G[u].push_back(v);

        }
        if(topologicalsort()){
            printf("YES\n");
            for(int i=0;i<vertex;i++)
            {
                cout<<topOrder[i];
                if(i<vertex-1)
                    cout<<" ";
                else printf("\n");
            }
        }
        else {printf("NO\n");
        printf("%d\n",vertex-num);}
    }
    return 0;
}
