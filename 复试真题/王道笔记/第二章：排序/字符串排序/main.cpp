#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;
char str[201];
bool cmp(char a,char b)
{
    return a<b;
}
int main()
{
    while(gets(str))
    {
    int len=strlen(str);
    sort(str,str+len);
    puts(str);
    }

    return 0;
}
