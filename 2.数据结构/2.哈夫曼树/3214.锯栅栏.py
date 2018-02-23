"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3214
@Website:http://acm.ecnu.edu.cn/problem/3214/
"""
"""
约翰正在修复农场的一段围栏。进过丈量，他需要 N 块木板，第 i 块木板的长度应该是 Li。他订购了一根很长的木料，长度就是这 N 块木板的总长度，由于约翰没有锯子，所以他找到了老唐，想让他帮忙锯开木料。

老唐是个生意精，他乐意代劳，但劳动不是无偿的。每开动一次锯子，可以把木料锯成两段，锯出 N 块木板就需要开动 N−1 次机器。
老唐说，每次开机都要收加工费，加工费用正比于需要锯开的木料长度。
比如要把一段长 20 米的木料锯开，就要收 20 元。
约翰不得不接受了老唐的要求，但他发现不同的切割次序会产生不同的费用。请帮约翰设计一个锯开木料的方案，使得约翰付出的加工费之和最小。

Input
    第一行：单个整数 N，1≤N≤20000

    第二行到第 N+1 行：第 i+1 行有一个整数 Li，1≤Li≤50000

Output
    单个整数：表示约翰付出的最小费用
Examples
    input
        3
        8
        5
        8

    output
        34
"""
# 算法思想：
# 利用优先队列，生成哈夫曼树
from queue import PriorityQueue


if __name__ == "__main__":
    N = int(input())
    L = PriorityQueue()
    for _ in range(N):
        L.put(int(input()))
    result = 0
    while L.qsize() != 1:
        temp = 0
        temp += L.get()
        temp += L.get()
        L.put(temp)
        result += temp
    print(result)
