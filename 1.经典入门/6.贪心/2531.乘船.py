"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2531
@Website:http://acm.ecnu.edu.cn/problem/2531/
"""
"""
春暖花开，实验室集体去长风公园泛舟。

实验室有 n(1<=N<=2000) 个人，每个人重量为 ci. 长风公园的每艘船的载重量为 K, 每次最多乘两人。假设每个人只能坐一次船，那么至少需要多少艘船才能让实验室全体都泛舟一次 ?

Input
输入第一行 T (1<=T<=30) 表示测试数据组数。

接下来有 T 组测试数据。

对于每组测试数据。

第一行有两个整数 N,K. N 表示实验室总人数 (3<=N<=2000)，K(1<=K<=1000) 表示每艘船的最大载重量

第二行有 n 个整数 ci(1<=ci<=K )

Output
对于每组测试数据输出一行，每行只有一个数字，即为最少的泛舟次数。
Examples
    input
        2
        10 8
        7 1 4 2 5 3 1 5 4 4
        3 10
        1 3 5
    output
        5
        2
"""
for _ in range(int(input())):
    n, k = map(int, input().split())
    ci = list(map(int, input().split()))
    ci.sort()
    count = 0
    l , r = 0, n-1
    while l < r:
        if (ci[l] + ci[r]) <= k:
            count += 1
            l += 1
            r -= 1
        else:
            count += 1
            r -= 1
    if l == r:
        count += 1
    print(count)
