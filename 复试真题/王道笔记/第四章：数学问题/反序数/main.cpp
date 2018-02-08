#include <iostream>
#include <stdio.h>
using namespace std;
int fun(int x)
{
    int ans=0;
    int t=1000;
    int k=1;
    for(int i=0;i<4;i++)
    {
        ans+=k*(x/t);
        x=x%t;
        t/=10;
        k*=10;
    }
    return ans;
}
int main()
{
    for(int x=1000;x<10000;x++)
    {
        if(fun(x)==x*9)
        {
            printf("%d\n",x);
        }
    }
    return 0;
}
