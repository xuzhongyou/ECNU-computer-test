#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char a[10000][1000];
int main()
{
    int i=-1;
    do{i++;scanf("%s",a[i]);}
    while(a[i]!='\n');
    int j=0;
    for(;j<i-1;j++)
        printf("%s\n",a[j]);
    printf("%s",a[j]);
}
