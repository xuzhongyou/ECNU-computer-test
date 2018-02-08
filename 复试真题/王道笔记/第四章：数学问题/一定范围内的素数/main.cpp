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
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        bool isOutput=false;
        for(int i=2;i<n;i++)
        {
            if(i%10==1)
            {
                if(isOutput==false&&judge(i))
                {
                    printf("%d",i);
                       isOutput=true;
                }
                else if(judge(i))
                   {
                       printf(" %d",i);
                   }
            }


        }
        if(isOutput==false)
            printf("-1\n");
        else printf("\n");
    }
    return 0;
}
