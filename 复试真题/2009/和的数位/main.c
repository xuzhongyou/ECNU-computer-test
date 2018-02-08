#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,a,b,sum;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int num=0;
            scanf("%d %d",&a,&b);
            sum=a+b;
            while(sum>=1)
            {
                sum=sum/10;
                num++;
            }
            printf("%d\n",num);
        }
        return 0;
    }
return 0;

}
