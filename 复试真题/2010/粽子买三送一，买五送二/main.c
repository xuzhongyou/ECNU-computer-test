#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int money,one;
    int numOf;
    int songde=0;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            scanf("%d%d",&money,&one);
            numOf=money/one;
            if((numOf/5)>0)
            {
                songde=numOf/5;
                songde*=2;
            }
            if((numOf-songde*5)/3>0)
            {
                songde+=(numOf-songde*5)/3;
            }
            numOf+=songde;
            printf("All=%d",numOf);
        }
    }
    return 0;
}
