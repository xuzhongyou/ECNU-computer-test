#include <stdio.h>
#include <stdlib.h>

int main()
{
    int e,f,c;
    int emptyB,eatB=0,eatAll=0;
    while(scanf("%d%d%d",&e,&f,&c)!=EOF)
    {
        emptyB=e+f;
        eatAll=0;
        while(emptyB>=c)
        {
            eatAll+=emptyB/c;
            eatB=emptyB/c;
            emptyB=emptyB%c;
            emptyB=emptyB+eatB;
            printf("eatB=%d emptyB=%d eatALl=%d\n",eatB,emptyB,eatAll);
        }
        printf("All=%d",eatAll);
    }
    return 0;
}
