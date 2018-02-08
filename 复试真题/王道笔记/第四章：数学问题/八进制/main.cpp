#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[100],cnt=0;
        while(n>=8)
        {
            a[cnt++]=n%8;
            n/=8;
        }
        a[cnt]=n;
        for(int i=cnt;i>=0;i--)
            printf("%d",a[i]);
        printf("\n");
    }
    return 0;
}
