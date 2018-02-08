#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

bool judge(int x)
{
    if(x<=1) return false;
    int bound=(int)sqrt(x)+1;
    for(int i=2;i<bound;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}
int main()
{
    int x;
    while(scanf("%d",&x)!=EOF)
    {
        if(judge(x)==0)
            puts("no");
        else puts("yes");
    }
    return 0;
}
