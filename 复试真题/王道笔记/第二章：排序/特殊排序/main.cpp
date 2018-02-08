#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    int a[1001];
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        printf("%d\n",a[n-1]);
        if(n==1)
        {
            printf("-1\n");
        }
        else{
                    for(int i=0;i<n-2;i++)
            printf("%d ",a[i]);
        printf("%d\n",a[n-2]);
        }

    }
    return 0;
}
