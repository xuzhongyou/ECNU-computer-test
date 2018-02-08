#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1001];
int main()
{
    int n;
    long int s1=0,s2=0;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a,a+n);
        if(n%2)
        {
            for(int i=0;i<n/2;i++)
                s1+=a[i];
            for(int i=n/2;i<n;i++)
                s2+=a[i];
            printf("1 %ld\n",s2-s1);
        }
        else{
            for(int i=0;i<n/2;i++)
                s1+=a[i];
            for(int i=n/2;i<n;i++)
                s2+=a[i];
            printf("0 %ld\n",s2-s1);
        }
    }
    return 0;
}
