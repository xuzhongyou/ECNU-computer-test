#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int a,b;
    while(scanf("%d%d",&a,&b)==2&&(a!=0&&b!=0))
    {
        int ans=1;
        while(b!=0)
        {
            if(b%2==1)
            {
                ans*=a;
                ans%=1000;
            }
            b/=2;
            a*=a;
            a%=1000;
        }
        printf("%d\n",ans);

    }
    return 0;
}
