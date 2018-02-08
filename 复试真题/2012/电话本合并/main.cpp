#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct E{
    char name[100];
    char num[100];

}list[100];
bool operator ==(E a,E b)
{
    return strcmp(a.name,b.name)==0&&strcmp(a.num,b.num)==0;
}
bool compare(E a,E b)
{
    return strcmp(a.name,b.name)<0;
}

int main()
{
    int sizeA,sizeB,sizeAB,i;
    scanf("%d",&sizeA);
    for(i=0;i<sizeA;i++)
        scanf("%s%s",list[i].name,list[i].num);
    scanf("%d",&sizeB);
    for(i=0;i<sizeB;i++)
        scanf("%s%s",list[i+sizeA].name,list[i+sizeA].num);
    sort(list,list+sizeA+sizeB,compare);
    sizeAB=unique(list,list+sizeA+sizeB)-list;
    printf("\n");
    for(int i=0;i<sizeAB;i++)
        printf("%s %s\n",list[i].name,list[i].num);

   // cout << "Hello world!" << endl;
    return 0;
}
