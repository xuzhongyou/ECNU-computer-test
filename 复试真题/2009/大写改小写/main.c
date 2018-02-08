#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[1000];

    while(gets(str))
    {
        int len=strlen(str);
        int i=0;
        for(;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
                printf("%c",str[i]-32);
            else printf("%c",str[i]);
        }
        printf("\n");
    }
    return 0;
}
