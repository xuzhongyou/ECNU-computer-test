"""
@Time:2018/2/23 17:46
@Author:xuzhongyou
"""
# 2613. Gamma 函数
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# Pollux 最近在复习概率论与数理统计，他发现里面有很多有意思的积分，今天 Pollux 碰到了一个 Gamma 函数，定义如下：
#
# τ(n)=∫∞0xn−1e−xdx
# 。
#
# 给出 n，求 τ(n)mod1999。
#
# Input
# 第一行为一个整数 T, 表示测数数据的组数。
#
# 接下去 T 行，每行一个整数 n (1≤n≤1000)。
#
# Output
# 每组测试数据输出一行，对于每个 n， 输出 τ(n)mod1999
#
# Examples
# input
# 3
# 1
# 2
# 10
# output
# 1
# 1
# 1061
#
# 思路：(a+b)%m=(a%m+b%m)%m
# （a*b）%m=(a%m*b%m)%m

def process(n):
    res = 1
    for i in range(1,n):
        res = (res*i)%1999
    print(res)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        process(n)