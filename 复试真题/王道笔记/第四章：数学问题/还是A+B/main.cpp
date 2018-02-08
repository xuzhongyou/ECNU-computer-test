#include <iostream>
#include <stdio.h>
using namespace std;

int pow(int k)
{
    int t=1;
    for(int i=0;i<k;i++)
        t*=10;
    return t;
}
int main()
{
    int a,b,k;
    while(scanf("%d%d%d",&a,&b,&k)!=EOF&&a!=0&&b!=0)
    {
        int aY=a%pow(k);
        int bY=b%pow(k);
        if(aY==bY)
            printf("-1\n");
        else printf("%d\n",a+b);
    }
    return 0;
}
