#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n%2)
        {
            printf("-%d\n",n/2+1);
        }
        else printf("%d\n",n/2);
    }

    return 0;
}
