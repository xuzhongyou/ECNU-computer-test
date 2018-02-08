#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long LL;
const int maxn=10000010;
int n;
LL A[maxn];
int main()
{
    LL sum=0,sum1=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lld",&A[i]);
        sum+=A[i];
    }
    nth_element(A,A+n/2,A+n);
    for(int i=0;i<n/2;i++)
    {
         sum1+=A[i];
    }

    printf("%d %lld\n",n%2,sum-sum1-sum1);
    return 0;
}
