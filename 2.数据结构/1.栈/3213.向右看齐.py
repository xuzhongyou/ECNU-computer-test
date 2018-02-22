"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3213
@Website:http://acm.ecnu.edu.cn/problem/3213/
"""
"""
N  头奶牛被紧急动员起来了，它们排成了一条长列。从左向右看，排在第 i 个位置的奶牛身高为 Hi。约翰一声令下，所有奶牛向右看齐。假设每头奶牛只能看到比自己高的牛。请问它们各自看到的最近的一头奶牛分别是谁呢？

Input
    第一行：单个整数 N，1≤N≤106

    第二行到 N+1 行：第 i+1 行有一个整数 Hi，1≤Hi≤106

Output
    第一行到第 N 行：第 i 行有一个整数 Ci，表示第 i 头奶牛向右看到的最近的一头奶牛编号，如果看不到任何奶牛，Ci 为 0
Examples
    input
        6
        3
        2
        6
        1
        1
        2
    output
        3
        3
        0
        6
        6
        0
"""
# 算法思想：
# 利用单调栈
N = int(input())
H = [0]
monoStack = []
result = [0] * (N+1)
for i in range(N):
    H.append(int(input()))
for i in range(1, N+1):
    while len(monoStack) > 0 and H[monoStack[-1]] < H[i]:
        result[monoStack[-1]] = i
        monoStack.pop()
    monoStack.append(i)
del result[0]
print(*result, sep='\n')
