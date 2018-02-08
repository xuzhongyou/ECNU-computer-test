#include <iostream>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <stdio.h>
using namespace std;
int compare(const void *a,const void *b)
{
     return *(int*)b-*(int*)a;
}
int main()
{
    string str="civsdas";
    string s(str.rbegin(),str.rend());
    cout << s << endl;

    int a[20]={2,4,1,23,5,76,0,43,24,65},i;
     for(i=0;i<10;i++)
        printf(" %d",a[i]);
    printf("\n");
     qsort((void *)a,10,sizeof(int),compare);
     for(i=0;i<10;i++)
        printf(" %d",a[i]);
        printf("\n");
    return 0;
}
