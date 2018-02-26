"""
@Time:2018/2/26 10:26
@Author:xuzhongyou
"""
# 2005. 整数分解
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 许多整数都可以分解为两个整数的乘积，现在给你若干个数，请你将它们分解为两个整数的乘积。
#
# Input
# 多组测试数据，每组包含一个整数 n (4≤n≤11000)。
#
# Output
# 对于每组输入数据输出把 n 分解后的结果，以一个空格分开。每组输出占一行。为了让题目有点难度，分解后的两个数都不能为 −1 或者 1，对于所有的 n 至少有一组解。
#
# 你可以任意输出一组符合要求的解。比如 n 为 24，你可以输出 12 2，4 6，甚至 -3 -8，只要你的输出是整数且没有出现 1,−1 而且它们的乘积为 24。
#
# Examples
# input
# 4
# 30
# output
# 2 2
# -5 -6

while True:
    try:
        n = int(input())
        for i in range(2,n):
            if n%i == 0:
                print(i,int(n/i))
                break
    except EOFError:
        break