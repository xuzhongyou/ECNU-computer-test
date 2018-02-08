#include <stdio.h>
#include <stdlib.h>
struct connect
{
    int a,b;
    int cost;
}E[15001];
int Tree[1000];
int FindRoot(int x)
{
    if(Tree[x]==-1)
        return x;
    else
        {
            int tmp=FindRoot(Tree[x]);
            Tree[x]=tmp;
            return tmp;
        }
}
void swapAB(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int main()
{
    int n,m,i,j;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&m);
        for(i=1;i<=m;i++)
            scanf("%d%d%d",&E[i].a,&E[i].b,&E[i].cost);
        for(i=1;i<=m;i++)
            for(j=i+1;j<=m;j++)
        {
            if(E[i].cost>E[j].cost)
               {
                   swapAB(&E[i].cost,&E[j].cost);
                   swapAB(&E[i].a,&E[j].a);
                   swapAB(&E[i].b,&E[j].b);
               }
        }
        int ans=0;
        printf("由小到大：\n");
        for(i=1;i<=m;i++)
        {
            printf("%d %d %d\n",E[i].a,E[i].b,E[i].cost);
        }
        for(i=1;i<=n;i++)
            Tree[i]=-1;
        for(i=1;i<=m;i++)
        {
            int a=FindRoot(E[i].a);
            int b=FindRoot(E[i].b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=E[i].cost;
                printf("第%d根 ",i);

            }
        }
    printf("%d",ans);
}return 0;
}
