#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <string.h>
using namespace std;
#define num 100
vector<int> conflict[num];//冲突组
int tree[num];
int dp[num];
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

struct E{
    int cnum;
    int ci;
    int pi;
}className[100];

void groupConflict(int tree[],int n,int &group)//分组
{
    for(int i=1;i<=n;i++)
    {
        int x=className[i].cnum;
        if(tree[x]==-1)
        {
            int flag=0;
            for(int j=1;j<=group;j++)
                if(conflict[j].front()==x)
                    flag=1;
            if(flag==0)
            {
                group++;
                conflict[group].push_back(x);
            }

        }
        else
        {
            int a=findRoot(x),flag=0;
            for(int j=1;j<=group;j++)
            {
                if(conflict[j].front()==a)
                {
                    flag=1;
                    conflict[j].push_back(x);
                    //printf("group:%d+%d\n",group,x);
                }
            }
            if(flag==0)
            {
                group++;
                conflict[group].push_back(a);
                conflict[group].push_back(x);
                //printf("group:%d+%d %d\n",group,a,x);
            }
        }
    }
}

void groupPack(int dp[],int n,int group,int money)
{
    for(int i=1;i<=group;i++)
        for(int j=money;j>=0;j--)
            for(int k=0;k<conflict[i].size();k++)
            {
                int newp=conflict[i][k];
                int nowPi=className[newp].pi,nowCi=className[newp].ci;
                if(j-nowPi>=0)//必须加上！
                    dp[j]=max(dp[j],dp[j-nowPi]+nowCi);
            }
    printf("dp[%d]=%d\n",money,dp[money]);
}
int main()
{
    int T;
    while(scanf("%d",&T)!=EOF)
    {
        while(T--)
        {
            for(int i=1;i<100;i++)
                conflict[i].clear();
            int n,money,group=0;
            scanf("%d%d",&n,&money);
            printf("依次课程号，冲突课，CI,PI(冲突写0 为不冲突)\n");

            memset(tree,-1,sizeof(tree));
            memset(dp,0,sizeof(dp));
            for(int i=1;i<=n;i++)
            {
                int a,b,aCi,aPi;
                scanf("%d%d%d%d",&a,&b,&aCi,&aPi);
                className[i].cnum=a;
                className[i].ci=aCi;
                className[i].pi=aPi;
                a=findRoot(a);
                if(b==0)//b=0 表示没有冲突 这门课
                    continue;
                b=findRoot(b);
                if(a!=b)
                {
                    tree[a]=b;
                }
            }

            for(int i=1;i<=n;i++)
            {
                int sp=className[i].cnum;
                printf("(%d %d) ",sp,findRoot(sp));
            }

            groupConflict(tree,n,group);
            printf("group=%d\n",group);

            groupPack(dp,n,group,money);
        }
    }
   // cout << "Hello world!" << endl;
    return 0;
}
