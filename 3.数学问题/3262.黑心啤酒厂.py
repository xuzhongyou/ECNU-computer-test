"""
@Time:2018/2/23 16:08
@Author:xuzhongyou
"""
# 3262. 黑心啤酒厂
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 黑心啤酒厂为了让大家买啤酒，会把一瓶酒设计成恰好能倒七杯。由于聚会时经常会有大家一起干杯这样的事情，干杯之前又要给每个人都倒满，
# 所以来两个人的时候，干完三轮，恰好多一杯；三个人的时候，干完两轮，恰好多一杯；四个人的时候会多三杯。在上述情况下，为了践行不浪费的原则，就会多买一瓶啤酒，再干一轮。
# 当然多买的啤酒可能又有多了……然后循环往复，喝了好多好多。直到啤酒刚刚好喝完为止。
#
# 现在啤酒厂把酒瓶设计成刚好能倒 x 杯，请依次求出有 2 人、3 人，一直到 n 人参加聚会时，啤酒厂各能卖出多少瓶啤酒。
#
# Input
# 输入只有一行，两个整数 x,n (1≤x≤109,2≤n≤105)。
#
# Output
# 输出 n−1 行，分别表示 2,3,…,n 人参加聚会时，能卖出的啤酒瓶数。
#
# Examples
# input
# 7 5
# output
# 2
# 3
# 4
# 5

#法一：只能对几个case,思路不能整除就添加，显然不能采取这样思想
# def  process(n,m):
#     r = n%m
#     count=1
#     while r!=0:
#         temp = r+n
#         r = temp%m
#         count += 1
#     print(count)
# if __name__ == '__main__':
#     inputs = [int(item) for item in input().split(' ')]
#     for i in range(2,inputs[1]+1):
#         process(inputs[0],i)
#法二：最小公倍数的方法
import math
def process(n,m):
    t = math.gcd(n,m)
    temp = m*n / t
    print(int(temp / n))

if __name__ == '__main__':
    inputs = [int(item) for item in input().split(' ')]
    for i in range(2,inputs[1]+1):
        process(inputs[0],i)



