#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
#define OFFSET 500000
using namespace std;
int Hash[1000001]={0};
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int i,x;
        for(i=0;i<n;i++)
        {
            scanf("%d",&x);
            Hash[x+OFFSET]++;
        }
        for(i=1000000;i>=0;i--)
        {
            if(Hash[i]>0)
            {
                printf("%d",i-OFFSET);
                Hash[i]--;
                m--;
                if(m!=0)
                    printf(" ");
                else {
                        printf("\n");
                        break;
                    }

                }
                if(m==0)
                    printf("djslf;a");
            }
        }

    return 0;
}
