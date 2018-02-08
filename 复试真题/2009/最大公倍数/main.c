#include <stdio.h>
#include <stdlib.h>
int abc(int a,int b)
{
    int c;
    if(a<b)
    {
        c=a;
        a=b;
        b=c;
    }
    while(a%b)
    {
        c=a%b;
        a=b;
        b=c;
       return abc(a,b);
    }
    return b;
}
int main()
{
    int n;
    int a,b;
    int GCD,LCM;
    while(scanf("%d",&n))
    {
        int i=0;
        for(;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            GCD=abc(a,b);
            LCM=a*b/GCD;
            printf("GCD=%d LCM=%d\n",GCD,LCM);
        }
    }
    return 0;
}
