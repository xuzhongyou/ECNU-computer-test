#include <iostream>
#include <stdio.h>

using namespace std;
int fun(int A,int B,int n)
{
    if(n==1||n==2)
        return 1;
    else{
        return (A*fun(A,B,n-1)+B*fun(A,B,n-2))%7;
    }
}
int main()
{
    int A,B,n;
    while(scanf("%d%d%d",&A,&B,&n)==3)
    {
        if(A==0&&B==0&&n==0)
            break;
        int test=fun(A,B,n);
        printf("%d\n",test);
    }
    return 0;
}
