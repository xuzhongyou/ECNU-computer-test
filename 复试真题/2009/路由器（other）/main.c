#include <stdio.h>
#include <stdlib.h>
struct connect
{
    int a,b;
    int cost;
}E[15001];
int Tree[1010];
int findRoot(int x)
{
    if(Tree[x]==-1)
        return x;
    else
    {
        int tmp=findRoot(Tree[x]);
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
        for(i=1;i<=m;i++)
            Tree[i]=-1;
        int ans=0;
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=m;j++)
                printf("原来： %d \n",Tree[j]);
            printf("%d %d",E[i].a,E[i].b);
            int a =findRoot(E[i].a);
            int b =findRoot(E[i].b);
            printf("a=%d b=%d\n",a,b);
            if(a!=b)
            {
                Tree[a]=b;
                ans+=E[i].cost;
            }
            for(j=1;j<=m;j++)
                printf("现在： %d ",Tree[j]);
            printf("\n");
        }
        printf("%d\n",ans);
    }
    return 0;
}
