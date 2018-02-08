#include <iostream>
#include <stdio.h>
#include <stack>
#include <stdlib.h>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        stack <int> S;
        char x[2];
        while(n--)
        {
            scanf("%s",x);
            if(x[0]=='A')
            {
                if(S.empty()==false)
                {
                    int tmp=S.top();
                    printf("%d\n",tmp);
                }
                else printf("E\n");
            }
            else if(x[0]=='P')
            {
                int tmp;
                scanf("%d",&tmp);
                S.push(tmp);
            }
            else if(x[0]=='O')
            {
                if(S.empty()==false)
                    S.pop();
            }
        }
        printf("\n");
    }
    return 0;
}
