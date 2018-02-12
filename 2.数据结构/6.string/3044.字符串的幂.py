"""
@Time:2018/2/11 9:39
@Author:xuzhongyou
"""
# 3044. 字符串的幂
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 给定一个字符串 s(长度范围为 1-80) 和一个整数 n(值范围为 0 - 10)，输出 s 的幂。
#
# 所谓字符串 s 的 n 次幂是指 n 个字符串 s 连接后的结果。0 次幂指的是一个空串。
#
# Input
# 第 1 行：一个整数 T (1≤T≤10) 为问题数。
#
# 接下来共 T 行，每行一个字符串和一个整数，中间由一个空格分隔。
#
# Output
# 对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）。
#
# 然后对应每个问题在一行中输出字符串的幂表示的字符串。
#
# Examples
# input
# 3
# 1 1
# Abc 3
# X 10
# output
# case #0:
# 1
# case #1:
# AbcAbcAbc
# case #2:
# XXXXXXXXXX

if __name__=='__main__':
    T =int(input())
    for i in range(T):
        result = []
        inputs = input().split(' ')
        result.append(inputs[0])
        result = result*int(inputs[1])
        print('case #%d:'%(i))
        print(''.join(result))