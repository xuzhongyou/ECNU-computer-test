#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char str[20];
    int N;
    while(scanf("%d",&N)!=EOF)
    {
        while(N--)
        {
            gets(str);
            if(strcmp(str,"E")==0)
                printf("Excellent\n");
            else if(strcmp(str,"C")==0)
                printf("Cheer\n");
            else if(strcmp(str,"N")==0)
                printf("Nice\n");
            else if(strcmp(str,"U")==0)
                printf("Ultimate\n");
            else if(strcmp(str,"Impossible")==0)
                printf("I'm possible\n");
            else if(strcmp(str,"ACM")==0)
                printf("Accept More\n");
        }
    }
    printf("Hello world!\n");
    return 0;
}
