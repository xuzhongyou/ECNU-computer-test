#include <iostream>
#include <stdio.h>
using namespace std;
#include <string.h>
int main()
{
    char str[1000];
    while(gets(str))
    {
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            if(str[i]>='a'&&str[i]<='z')
                str[i]-=32;
        }
        puts(str);
    }
    cout << "Hello world!" << endl;
    return 0;
}
