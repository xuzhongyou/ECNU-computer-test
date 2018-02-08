#include <iostream>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
    int n;
    int l=0,r=0;
    while(scanf("%d",&n)!=EOF)
    {
    for(int i=0;i<n;i++)
    {
        getchar();
        char str;
        int k;
        scanf("%c%d",&str,&k);
        if((str=='L'||str=='l')&&k>=0)
            l+=k;
        if((str=='R'||str=='r')&&k>=0)
          r+=k;
    }
    printf("Total left is:%d\n",l);
    printf("Total right is:%d\n",r);
    }

    return 0;
}
