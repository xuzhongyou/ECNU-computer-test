#include <iostream>
#include <stdio.h>
#define INF 0x7ffffff
#include <string.h>
#include <algorithm>

using namespace std;
struct E{
    char a[500];
    int len;
    bool operator < (const E &A) const
    {
        return len<A.len;
    }
}str[5];
int main()
{
    for(int i=0;i<5;i++)
    {
        scanf("%s",str[i].a);
        str[i].len=strlen(str[i].a);
    }
    sort(str,str+5);
   // for(int i=0;i<5;i++)
     //   puts(str[i].a);
    for(int i=0;i<5;i++)
    {
        puts(str[i].a);
        if(str[i].len==str[i+1].len&&(i+1)<5)
            continue;
        else break;
    }
    for(int i=4;i>-1;i--)
    {
        puts(str[i].a);
        if(str[i].len==str[i-1].len&&(i-1)>=0)
            continue;
        else break;
    }
    return 0;
}
