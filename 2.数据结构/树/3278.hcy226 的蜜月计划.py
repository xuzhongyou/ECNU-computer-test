"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3278
@Website:http://acm.ecnu.edu.cn/problem/3278/
"""
"""
hcy226 带着他的女朋友来到了法国美丽的普罗旺斯，顺着这美丽的薰衣草的花海，他们准备游览 N 个不同的城市。

这 N 个城市之间一共有 N−1 条道路。他们此时在最北边的一座城市，准备在玩一遍所有的城市之后，再回到最北边的那一座城市。数据保证每个城市都是可以到达的。（编号为 1 的城市为最北方的城市）

他们希望这一次的旅行不要浪费太多的时间在路上，所以请你帮他们算一算，游玩这么多城市在路上最少需要消耗多少时间。

Input
第一行一个整数 N (2≤N≤200 000)，表示城市的数量。

接下来一共 N−1 行。每行三个整数 s,t,l (1≤s,t≤N,1≤l≤1 000)，表示一条道路，s,t 分别为两座城市的编号，l 为这条道路的长度。
Output
一个整数，表示游览 N 座城市在路上花费的最少时间。

Examples:
    input:
        5
        1 2 5
        1 5 2
        1 3 4
        3 4 6
    output:
        34

"""
n = int(input())
res = 0
for i in range(n - 1):
	a, b, c = map(int, input().split())
	res += c
print(2 * res)
