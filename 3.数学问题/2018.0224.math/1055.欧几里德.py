"""
@Time:2018/2/24 14:24
@Author:xuzhongyou
"""
# 1055. 欧几里德
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 实现欧几里德算法（也即辗转相除法）。
#
# Input
# 测试含多组测试数据。
#
# 每组测试数据只含一行，这一行包含两个整数 a,b (0<a,b≤231).
#
# Output
# 对于每组测试数据，输出一行，包含一整数 c，表示 a 和 b 的最大公约数。
#
# Examples
# input
# 16 24
# output
# 8

import math
while True:
    try:
        n,m = map(int,input().split(' '))
        print(math.gcd(n,m))
    except EOFError:
        break