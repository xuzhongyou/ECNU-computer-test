#include <iostream>
#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int a[100001];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            int max1=1<<31;
            int t;
            scanf("%d",&t);
            for(int j=1;j<=t;j++)
                scanf("%d",&a[j]);
            printf("Case %d:\n",i);
            int point1=1,point2=1;
            int sum;
            for(int j=1;j<=t;j++)
            {
                 sum=0;
                 for(int k=j;k<=t;k++)
                 {
                     sum+=a[k];
                     if(sum>max1)
                    {
                        max1=sum;
                        point1=j;
                        point2=k;
                    }

                 }

            }
            if(i!=(n))
                printf("%d %d %d\n\n",max1,point1,point2);
            else printf("%d %d %d\n",max1,point1,point2);
        }
    }
    return 0;
}
