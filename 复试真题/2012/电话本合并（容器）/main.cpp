#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
#include <string.h>
using namespace std;

struct E{
    char name[100];
    char num[100];

};
bool operator ==(E a,E b)
{
    return strcmp(a.name,b.name)==0&&strcmp(a.num,b.num)==0;
}

bool operator <(E a,E b)
{
    return strcmp(a.name,b.name)<0;
}
int main()
{
    vector<E> vector1;
    vector<E>::iterator new_end;
    int sizeA,sizeB;
    scanf("%d",&sizeA);
    for(int i=0;i<sizeA;i++)
    {
        E tmp;
        scanf("%s%s",tmp.name,tmp.num);
        vector1.push_back(tmp);
    }
    scanf("%d",&sizeB);
    for(int i=0;i<sizeB;i++)
    {
        E tmp;
        scanf("%s%s",tmp.name,tmp.num);
        vector1.push_back(tmp);
    }
    sort(vector1.begin(),vector1.end());
    new_end=unique(vector1.begin(),vector1.end());
    vector1.erase(new_end,vector1.end());
   // new_end=vector1.begin();
    for(int i=0;i<vector1.size();i++)
    {
        E tmp=vector1[i];
        printf("%s %s\n",tmp.name,tmp.num);
    }
   // cout << "Hello world!" << endl;
    return 0;
}
