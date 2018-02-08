#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
    char line[100];
    while(gets(line))
    {
        sort(line,line+strlen(line));
        int c=0,m=0,y=0,len=strlen(line);
        puts(line);
        for(int i=0;i<len;i++)
        {
            if(line[i]=='C')
                c++;
            else if(line[i]=='M')
                m++;
            else {
                y++;
            }
        }
        printf("C=%d\n",c);
        printf("M=%d\n",m);
        printf("Y=%d\n",y);
    }
    cout << "Hello world!" << endl;
    return 0;
}
