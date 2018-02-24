"""
@Time:2018/2/24 15:36
@Author:xuzhongyou
"""
# 1007. N!的最高位
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 求 N 的阶乘的最高位数。
#
# 例如：
#
# 5!=120, 所以最高位为 1
#
# 10!=3628800，所以最高位为 3
#
# Input
# 每个数据包含一行，每行有一个整数 N(0<=N<=10000000)
#
# Output
# 对于每个测试数据，输出 N! 的最高位数字
#
# Examples
# input
# 5
# 10
# output
# 1
# 3

def cal(n):
    res =1
    for i  in range(2,n+1):
        temp = str(i)[:3]
        res= str(res*int(temp))[:3]
        print('res',res)
        res = int(res)
    print(res)
cal(10000000)