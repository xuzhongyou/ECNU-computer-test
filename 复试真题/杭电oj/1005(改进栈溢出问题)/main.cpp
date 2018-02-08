#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a[50];
    int A,B,n;
    a[1]=1;a[2]=1;
    while(scanf("%d%d%d",&A,&B,&n)!=EOF&&(A&&B&&n))
    {
        for(int i=3;i<=49;i++)
        {
            a[i]=(A*a[(i-1)]+B*a[(i-2)])%7;
        }
        printf("%d\n",a[n%49]);
    }
    return 0;
}
