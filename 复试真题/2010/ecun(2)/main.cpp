#include <iostream>
#include <stdio.h>
using namespace std;
#include <string.h>
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            char str[100];
            scanf("%s",str);
            if(strcmp(str,"E")==0)
                puts("Excellent");
            else if(strcmp(str,"C")==0)
                puts("Cheer");
            else if(strcmp(str,"N")==0)
                puts("Nice");
            else if(strcmp(str,"U")==0)
                puts("Ultimate");
            else if(strcmp(str,"Impossible")==0)
                printf("I'm possible\n");
            else if(strcmp(str,"ACM")==0)
                printf("Accept More\n");
        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
