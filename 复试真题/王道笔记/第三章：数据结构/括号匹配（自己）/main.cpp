#include <iostream>
#include <stdio.h>
#include <stack>
using namespace std;
stack<int> S;
char str[110];
char ans[110];
//mine!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
int main()
{
    while (scanf("%s",str)!=EOF)
    {
        int i;
        for(i=0;str[i]!=0;i++)
        {
            if(str[i]=='(')
            {
                S.push(i);
                ans[i]=' ';
            }
            else if(str[i]==')')
            {
                if(S.empty()==false)
                {
                    ans[i]=' ';
                    S.pop();
                }
                else ans[i]='?';
            }
            else ans[i]=' ';
        }
        while(!S.empty())
        {
            ans[S.top()]='$';
            S.pop();
        }
        ans[i]=0;
        puts(str);
        puts(ans);
    }
    return 0;
}
