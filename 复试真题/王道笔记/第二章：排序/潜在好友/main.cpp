#include <iostream>
#include <stdio.h>
using namespace std;
int hash[201]={0};
int a[201];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=0;i<201;i++)
        {
            hash[i]=0;
        }

        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            hash[a[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(hash[a[i]]!=1)
                printf("%d\n",hash[a[i]]-1);
            else puts("BeiJu");
        }
    }
    return 0;
}
