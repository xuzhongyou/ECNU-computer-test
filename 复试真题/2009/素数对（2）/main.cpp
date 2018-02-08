#include <iostream>
#include <stdio.h>
using namespace std;
#include <math.h>
bool judge(int x)
{
    if(x<=1) return false;
    int bound=(int)sqrt(x)+1;
    for(int i=2;i<bound;i++)
        if(x%i==0)
        return false;
    return true;
}
int main()
{
    int num;
    while(scanf("%d",&num)!=EOF)
    {
        while(num--)
        {
            int n;
            scanf("%d",&n);
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(judge(i)&&judge(n-i+1))
                {
                    cnt++;
                    //printf("%d %d\n",i,n-i+1);
                }

            }
            printf("%d\n",cnt);
        }

    }
    //cout << "Hello world!" << endl;
    return 0;
}
