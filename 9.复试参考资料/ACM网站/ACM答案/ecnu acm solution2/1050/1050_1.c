#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <float.h>
#include <string.h>
#include <time.h>



int main()
{
    int m,n,x,p,q,y;
    int a[100][100],b[100][100];
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d",&m);
        int c[100][100]={{0}};
        for(x=0;x<m;x++)
            for(y=0;y<m;y++)
        {
            scanf("%d",&a[x][y]);
        }
        for(x=0;x<m;x++)
            for(y=0;y<m;y++)
        {
            scanf("%d",&b[x][y]);
        }
        for(x=0;x<m;x++)
            for(y=0;y<m;y++)
        {
            for(p=0;p<m;p++) c[x][y]+=a[x][p]*b[p][y];
        }
        for(x=0;x<m;x++)
            for(y=0;y<m;y++)
        {
            printf("%d%c",c[x][y],y==m-1?'\n':' ');
        }

    }
    return 0;
}
