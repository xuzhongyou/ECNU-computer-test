#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

priority_queue<int, vector<int>, greater<int> > Q;//Ð¡¶¥¶Ñ
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        while(Q.empty()==false)
            Q.pop();
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            Q.push(x);
        }
        int ans=0;
        while(Q.size()>1)
        {
            int a=Q.top();
            Q.pop();
            int b=Q.top();
            Q.pop();
            ans+=a+b;
            Q.push(a+b);
        }
        printf("%d\n",ans);
    }
    cout << "Hello world!" << endl;
    return 0;
}
