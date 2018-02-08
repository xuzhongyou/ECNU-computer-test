#include <iostream>
#include <stdio.h>
#include <algorithm>
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
        sort(a,a+n);
        int cnt=-1;
        for(int i=0;i<m;i++)
        {
            scanf("%d",&x);

            int top=n-1,base=0,ans=-1;
            while(top>=base)
            {
                int mid=(top+base)/2;
                if(a[mid]==x)
                {
                    ans=b[++cnt]=1;
                    break;
                }
                else if(a[mid]>x)
                    top=mid-1;
                else base=mid+1;
            }
            if(ans==-1)
            {
                b[++cnt]=0;
            }

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

