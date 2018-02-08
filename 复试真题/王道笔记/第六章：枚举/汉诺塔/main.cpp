#include <iostream>
#include <stdio.h>

using namespace std;

long long f(int num)
{
    if(num==1)
        return 2;
    else{
        return 3*f(num-1)+2;
    }
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",f(n));
    }
    return 0;
}
