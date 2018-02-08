#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int L,M;
    while(scanf("%d%d",&L,&M)!=EOF)
    {
        int hash[10001]={0};
        for(int i=0;i<=L;i++)
            hash[i]++;
        while(M--)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            if(a>b)
            {
                int tmp=a;
                a=b;
                b=tmp;
            }
            for(int i=a;i<=b;i++)
            {
                if(hash[i]==1)
                    hash[i]--;
            }
        }
        int cnt=0;
        for(int i=0;i<=L;i++)
            if(hash[i]==1)
                cnt++;
        printf("%d\n",cnt);
    }
    return 0;
}
