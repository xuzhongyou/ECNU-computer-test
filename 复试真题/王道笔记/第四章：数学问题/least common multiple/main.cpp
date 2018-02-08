#include <iostream>
#include <stdio.h>
using namespace std;
int gcd(int a,int b)
{
    return b!=0? gcd(b,a%b):a;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        int num;
        while(scanf("%d",&num)!=EOF)
        {
            long int a[100];
            a[0]=1;
            for(int i=1;i<=num;i++)
            {
                scanf("%ld",&a[i]);
                a[i]=a[i]*a[i-1]/gcd(a[i-1],a[i]);
            }
            printf("%ld\n",a[num]);
        }


    }
    return 0;
}
