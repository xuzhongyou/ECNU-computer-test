#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char str[7];

void swap(char *a,char *b)
{
    char temp=*a;
    *a=*b;
    *b=temp;
}
void huisu(char *str,int start,int N)
{
    if(start==N)
        puts(str);
    else{
        for(int i=start;i<N;i++)
        {
            swap(str+start,str+i);
            huisu(str,start+1,N);
            swap(str+start,str+i);
        }
    }
}
int main()
{
    while(scanf("%s",str)!=EOF)
    {
        int len=strlen(str);
        huisu(str,0,len);
        printf("\n");
    }

    return 0;
}
