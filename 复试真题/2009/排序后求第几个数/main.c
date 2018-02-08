#include <stdio.h>
#include <stdlib.h>
void swapAB(int *a,int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main()
{
    int n,num,a[100];
    while(scanf("%d",&n)!=EOF)
    {
        int i,j;
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
                swapAB(&a[i],&a[j]);
        }
        for(i=0;i<n;i++)
            printf(" %d ",a[i]);
        break;
    }
    while(scanf("%d",&num)!=EOF)
    {
        int i,N;
        for(i=0;i<num;i++)
        {
            scanf("%d",&N);
            printf("%d\n",a[N-1]);
        }

    }
    return 0;
}
