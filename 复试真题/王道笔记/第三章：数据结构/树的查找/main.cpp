#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[1001];
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int k=1,start=0,end=0;
        int deep;
        scanf("%d",&deep);
        for(int i=1;i<deep;i++)
        {
            k*=2;
        }
        start=k;
        if(start>n)
        {
            printf("EMPTY\n");
        }
        else
        {
                    if(k*2>n)
            end=n;
        else end=k*2-1;
        printf("%d %d\n",start,end);
        for(int i=start;i<end;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[end]);
        }

    }
    return 0;
}
