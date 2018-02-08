#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int a[100],maxhigh=0,b[100];
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[n-1-i]=a[i];
            if(a[i]>maxhigh)
                maxhigh=a[i];
        }
        int startA,startB;
        for(int i=0;i<n;i++)
        {
            if(a[i]>maxhigh/2)
            {
                startA=i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(b[i]>maxhigh/2)
            {
                startB=i;
                break;
            }
        }
        int ans=0;
        for(int i=startA,j=startB;2*a[i]>=maxhigh&&i<n;i++,j++)
        {
            ans+=abs(a[i]-b[j]);
        }
        ans/=2;
        for(int i=0;i<n;i++)
        {
            if(a[i]>maxhigh/2)
                continue;
            else ans+=a[i];
        }
        printf("%d\n",ans);
    }
    //cout << "Hello world!" << endl;
    return 0;
}
