#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[100],m,b[100]={0},x;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        scanf("%d",&m);
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);
            for(int j=0;j<n;j++)
                if(x==a[j])
                    b[i]=1;
        }
        for(int i=0;i<m;i++)
        {
            if(b[i]==1)
                puts("YES");
            else puts("NO");
        }

    }
    return 0;
}
