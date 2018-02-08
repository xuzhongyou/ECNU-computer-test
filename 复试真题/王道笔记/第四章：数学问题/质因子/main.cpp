
#include<stdio.h>
#include<math.h>
int main()
{
    int i,m,n;
    while(m=0,scanf("%d",&n)!=EOF)
    {
        for(i=2;i<=sqrt(0.+n);)
          if(n%i==0)
          {
              n=n/i;
                m++;
                i=2;
          }
          else i++;
        printf("%d\n",m+1);
    }
}
