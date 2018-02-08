#include <iostream>
#include <stdio.h>
using namespace std;
//重点的一个思想是：如果a[i]是负数那么它不可能代表最有序列的起点，因为任何包含a[i]的作为起点的子序列都可以通过用a[i+1]作为起点来改进。类似的有，任何的负的子序列不可能是最优子序列的前缀。例如说，循环中我们检测到从a[i]到a[j]的子序列是负数，那么我们就可以推进i。关键的结论是我们不仅可以把i推进到i+1，而且我们实际可以把它一直推进到j+1。
//
 //   举例来说，令p是i+1到j之间的任何一个下标，由于前面假设了a[i]+…+a[j]是负数，则开始于下标p的任意子序列都不会大于在下标i并且包含从a[i]到a[p-1]的子序列对应的子序列（j是使得从下标i开始成为负数的第一个下标）。因此，把i推进到j+1是安全的，不会错过最优解。注意的是：虽然，如果有以a[j]结尾的某序列和是负数就表明了这个序列中的任何一个数不可能是与a[j]后面的数形成的最大子序列的开头，但是并不表明a[j]前面的某个序列就不是最大序列，也就是说不能确定最大子序列在a[j]前还是a[j]后，即最大子序列位置不能求出。但是能确保maxSum的值是当前最大的子序列和。这个算法还有一个有点就是，它只对数据进行一次扫描，一旦a[j]被读入处理就不需要再记忆。它是一个联机算法。


int main()
{
    int t,_case=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,dp=0,maxSubSequence=1<<31,begin=1,end=1,tmp=1;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            int num;
            scanf("%d",&num);
            dp+=num;
            if(dp>maxSubSequence)
            {
                begin=tmp;
                end=i;
                maxSubSequence=dp;
            }
            if(dp<0)
            {
                dp=0;
                tmp=i+1;
            }

        } printf("Case %d:\n%d %d %d\n", _case++, maxSubSequence, begin, end);
            if(t) printf("\n");
    }
    return 0;
}
