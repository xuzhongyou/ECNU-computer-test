#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        long t=n;
        while(n--)
            t+=n;
        printf("%ld\n\n",t);
    }
    return 0;
}
