#include <iostream>
#include <stdio.h>
using namespace std;

bool fun(int x)
{
    int a[5],cnt=0;
    while(x>=1)
    {
        a[cnt++]=x%10;
        x/=10;
    }
    for(int i=0;i<(cnt/2);i++)
    {
        if(a[i]==a[cnt-i-1])
            continue;
        else { return false;}
    }
    return true;
}
int main()
{
    for(int i=0;i<256;i++)
    {
        if(fun(i*i))
            printf("%d\n",i);
    }
    return 0;
}
