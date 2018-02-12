"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2965
@Website:http://acm.ecnu.edu.cn/problem/2965/
"""
"""
元旦快到了，校学生会让乐乐负责新年晚会的纪念品发放工作。为使得参加晚会的同学所获得 的纪念品价值相对均衡，他要把购来的纪念品根据价格进行分组，但每组最多只能包括两件纪念品， 并且每组纪念品的价格之和不能超过一个给定的整数。为了保证在尽量短的时间内发完所有纪念品，乐乐希望分组的数目最少。

你的任务是写一个程序，找出所有分组方案中分组数最少的一种，输出最少的分组数目。

【题目包含多组输入输出！】

Input
输入包含 n+2 行 :

第 1 行包括一个整数 w，为每组纪念品价格之和的上限， 第 2 行为一个整数 n，表示购来的纪念品的总件数

第 3-n+2 行每行包含一个正整数 Pi 表示所对应纪念品的价格。

1 <= n <= 30000， 80 <= W <= 200

Output
输出一行，包含一个整数，即最少的分组数目。
Examples
    input
        100
        9
        90
        20
        20
        30
        50
        60
        70
        80
        90
    output
        6
"""
while True:
    try:
        w = int(input())
        n = int(input())
        pi = []
        for _ in range(n):
            pi.append(int(input()))
        pi.sort()
        count = 0
        l , r = 0, n-1
        while l < r:
            if (pi[l] + pi[r]) <= w:
                count += 1
                l += 1
                r -= 1
            else:
                count += 1
                r -= 1
        if l == r:
            count += 1
        print(count)
    except EOFError:
        pass

# C implementation
"""
#include <stdio.h>
#include <stdlib.h>

int cmp(const void *i, const void *j)
{
    return *(int *)i - *(int *)j;
}
int main()
{
    int p;
    while(~scanf("%d", &p))
      {int m;
        scanf("%d", &m);
    int a[m];
    for (int i = 0; i < m; i++)
        scanf("%d",&a[i]);
    qsort(a, m, sizeof(int), cmp);
    int *p1 = a, *p2 = a + m - 1;
    int cnt = 0;
    for ( ; p1 < p2; )
    {
        if (!(*(p1) + *(p2) > p))
            {
                cnt++;
                p1++;
                p2--;
            }
        else
        {
            cnt++;
            p2--;
        }
    }
    if (p1 == p2)
        printf("%d\n", ++cnt);
    else
        printf("%d\n", cnt);
}
    return 0;
}
"""
