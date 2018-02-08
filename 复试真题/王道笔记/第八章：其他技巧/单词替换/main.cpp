#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    char str[201];
    while(gets(str))
    {
        char a[101];
        char b[101];
        gets(a);
        gets(b);
        string stra=a,strb=b,str1=str;
        int t=str1.find(stra,0);
        while(t!=-1)
        {
            if(t==0)
            {
                str1.erase(t,stra.size());
                str1.insert(t,strb);
            }
            else if(str1[t-1]==' '&&(str1[t+stra.size()]==' '||str1[t+stra.size()]=='\0'))
            {
                str1.erase(t,stra.size());
                str1.insert(t,strb);
            }
            t++;
            t=str1.find(stra,t);
        }
        puts(str1.c_str());
    }
    return 0;
}
