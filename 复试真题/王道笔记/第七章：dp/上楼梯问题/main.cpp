#include <iostream>
#include <stdio.h>
long long f[91];
using namespace std;

int main()
{
    f[1]=1;
    f[2]=2;
    for(int i=3;i<91;i++)
        f[i]=f[i-1]+f[i-2];
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",f[n]);
    }
    return 0;
}
