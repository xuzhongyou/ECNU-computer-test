#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[10000000];
int b[6666666]={0};
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
     for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]++;
    }
    long long s1=0,s2=0;
     if(n%2)
     {
         for(int i=1,k1=0,k2=0;i<6666666;i++)
         {
             if(b[i]==0)
                continue;
             else if(k1<n/2){
                s1+=i*b[i];
                k1+=b[i];
             }
             else
             {
                 s2+=i*b[i];
                 k2+=b[i];
             }
         }
         printf("1 %lldd\n",s2-s1);
     }
     else {
        for(int i=1,k1=0,k2=0;i<6666666;i++)
         {
             if(b[i]==0)
                continue;
             else if(k1<n/2){
                s1+=i*b[i];
                k1+=b[i];
             }
             else
             {
                 s2+=i*b[i];
                 k2+=b[i];
             }
         }
        printf("0 %lld\n",s2-s1);
     }
    }
    return 0;
}
