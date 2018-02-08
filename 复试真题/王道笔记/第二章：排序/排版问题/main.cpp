#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;

int main()
{
    int h;
    while(scanf("%d",&h)!=EOF)
    {
        int maxLine=h+(h-1)*2;
        int i;
        int j;
        for(i=1;i<=h;i++)
        {
            for(j=1;j<=maxLine;j++)
            {
                if(j<maxLine-h-(i-1)*2+1)
                    printf(" ");
                else printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}
