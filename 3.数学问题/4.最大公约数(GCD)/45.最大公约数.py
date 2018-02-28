"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:45
@Website:http://acm.ecnu.edu.cn/problem/45/
"""
"""
定义函数 arrayGCD 计算一个数组中 n 个整数的最大公约数。
Examples
    input
        8
        2 3 5 7 11 13 17 19
    output
        1
    input
        4
        16 64 16 32
    output
        16
"""
import queue

PriorityQueue = queue.PriorityQueue()
n = int(input())
num = list(map(int, input().split(' ')))
for _ in num:
    PriorityQueue.put(_)

max_GCD = 0
zero = 0
while True:
    temp = []
    min_num = PriorityQueue.get()
    for i in range(n-zero-1):
        remain = PriorityQueue.get() % min_num
        if remain == 0:
            zero += 1
        else:
            temp.append(remain)
    if zero == (n-1):
        print(min_num)
        break
    else:
        temp.append(min_num)
        for item in temp:
            PriorityQueue.put(item)
