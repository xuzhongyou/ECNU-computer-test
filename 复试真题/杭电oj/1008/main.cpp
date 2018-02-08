#include <iostream>
#include <stdio.h>
using namespace std;
int a[101];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {
        int i;
        a[0]=0;
        int time=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            if(a[i-1]<a[i])
            {
                time+=6*(a[i]-a[i-1])+5;
            }
            else {
                time+=4*(a[i-1]-a[i])+5;
            }
        }
        printf("%d\n",time);
    }
    return 0;
}
