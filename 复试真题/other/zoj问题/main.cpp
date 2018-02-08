#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char str[100];
int main()
{
    while(scanf("%s",str)!=EOF&&str[0]!='E')
    {
        int z=0,o=0,j=0,i=0;
        while(str[i]!=0)
        {
            if(str[i]=='Z')
            {z++;i++;}
        if(str[i]=='O')
           {
               o++;i++;
           }
        if(str[i]=='J')
            {j++;i++;}
        }
        while(z||o||j)
        {
            if(z!=0)
               {
                   printf("Z");z--;
               }
            if(o!=0)
               {
                   printf("O");o--;
               }
            if(j!=0)
                {
                    printf("J");j--;
                }

        }
        printf("\n");


    }

    return 0;
}
