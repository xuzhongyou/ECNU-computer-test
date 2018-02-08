#include <iostream>

#include <stdio.h>
#include <algorithm>
using namespace std;

bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n;
    int buff[10000]; int i;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
            scanf("%d",&buff[i]);
        sort(buff,buff+n,cmp);
            for(i=0;i<n;i++)
        printf("%d ",buff[i]);
    }
    return 0;
}
