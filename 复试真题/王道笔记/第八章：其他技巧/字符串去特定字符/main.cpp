#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    char str[1000001];
    while(gets(str))
    {
        string str1=str;
        char c=getchar();
        int t=str1.find(c,0);
        while(t!=-1)
        {
            str1.erase(t,1);
            t=str1.find(c,0);
        }
        printf("%s\n",str1.c_str());
        getchar();
        //puts(str1.c_str());
        //cin.ignore();
    }
    return 0;
}
