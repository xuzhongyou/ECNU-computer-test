#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    unsigned long int a,b;
    int m;
    while(scanf("%d",&m)!=EOF)
    {
        if(m==0) break;
        scanf("%ld%ld",&a,&b);
        a=a+b;
        int ans[50],size=0;

        do{
            ans[size++]=a%m;
            a=a/m;
        }while(a!=0);
        for(int i=size-1;i>=0;i--)
        {
            printf("%d",ans[i]);
        }
        printf("\n");
    }
    return 0;
}
