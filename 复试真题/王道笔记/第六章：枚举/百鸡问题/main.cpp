#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        n=3*n;
        int x,y,z;
        for(x=0;x<=100;x++)
            for(y=0;y<=100-x;y++)
            {
                z=100-x-y;
                if(z<0)
                    continue;
                if(z+y*9+15*x<=n)
                    printf("x=%d,y=%d,z=%d\n",x,y,z);
            }
    }
    return 0;
}
