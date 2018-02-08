#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&(n!=0))
    {
        while(n/10)
        {
            int x=0;
            if(n/10)
            {
                x+=n%10;
                n/=10;
            }
            x+=n;
            n=x;
        }
        printf("%d\n",n);
    }
    return 0;
}
