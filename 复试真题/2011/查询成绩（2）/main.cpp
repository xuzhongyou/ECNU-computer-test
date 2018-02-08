#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct E{
    char name[6];
    int score;
    bool operator < (const E &A)const
    {
        if(score==A.score)
        {
            int tmp=strcmp(name,A.name);
            return tmp<0;
        }
        else return score<A.score;
    }
}student[5001];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(n--)
        {
            int m;
            scanf("%d",&m);
            for(int i=0;i<m;i++)
                scanf("%s%d",student[i].name,&student[i].score);
            sort(student,student+m);
            int num;
            scanf("%d",&num);
            while(num--)
            {
                int s;
                scanf("%d",&s);
                int i=0;
                for(;i<m;i++)
                {
                    if(s<student[i].score)
                    {
                        puts(student[i].name);
                        break;
                    }
                }
                if(i==m)
                    puts("Impossible");
            }
        }


    }
    cout << "Hello world!" << endl;
    return 0;
}
