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
    long int len;
    while(scanf("%ld%d",&len,&n)!=EOF)
    {
        int a[601];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n,cmp);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(len<=0)
                break;
            else {
                len-=a[i];
                cnt++;
            }
        }
        if(len>0)
            puts("impossible");
        else printf("%d\n",cnt);
    }
    return 0;
}
