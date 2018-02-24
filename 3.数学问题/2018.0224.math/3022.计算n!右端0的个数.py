"""
@Time:2018/2/24 15:13
@Author:xuzhongyou
"""
# 3022. 计算n!右端0的个数(II)
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 给定一个整数 N (1≤N≤1000)，输出 N 阶乘右端 0 的个数。
#
# Input
# 第 1 行：一个整数 T (1≤T≤10) 为问题数。
#
# 接下来共 T 行，每行一个整数，表示 N (1≤N≤1000)。
#
# Output
# 对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）。
#
# 然后对应每个问题在一行中输出 N 阶乘右端 0 的个数。
#
# Examples
# input
# 3
# 1
# 20
# 1000
# output
# case #0:
# 0
# case #1:
# 4
# case #2:
# 249
# Note
# 1! 等于 1，右端0的个数 0 个
# 20! 等于 2432902008176640000，右端0的个数 4 个
# 1000! 等于 402387260077093773543702433923003985719…，右端0的个数 249 个
def cal(n):
    res =1
    for i in range(2,n+1):
        res*=i
    return res

T = int(input())
for  i in range(T):
    n = int(input())
    str_ = str(cal(n))
    count=0
    lens = len(str_)
    while True:
        if str_[lens-1]=='0':
            count+=1
            lens -=1
        else:
            break
    print('case #%d:'%(i))
    print(count)
