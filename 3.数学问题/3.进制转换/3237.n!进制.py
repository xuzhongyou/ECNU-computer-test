"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3237
@Website:http://acm.ecnu.edu.cn/problem/3237/
"""
"""
n!  进制是指从数的最低位开始，第 i 位的权值是 (i+1)!，第 i 位取值范围为 0~i+1，i 从 0 开始。

例如：
n! 进制的 21 对应10进制的 5， 计算方法为：2×2!+1×1!=5。
n! 进制的 120 对应10进制的 10，1×3!+2×2!+0×1!=10。

给你一个10进制数，求其 n! 进制的值。

Input
    第 1 行为一个整数 T (1≤T≤10)，表示问题数。

    接下来 T 行，每行一个10进制的整数 n，0≤n≤3628799 (10!−1)。

Output
    对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等），然后在一行中输出十进制数的对应的 n! 进制数的值。

Examples
    input
        5
        0
        1
        10
        100
        3628799

    output
        case #0:
        0
        case #1:
        1
        case #2:
        120
        case #3:
        4020
        case #4:
        987654321
"""
t = int(input())
for j in range(t):
    n = int(input())
    i = 2
    result = ''
    while True:
        remain = n % i
        n   = n // i
        result = str(remain) + result

        if n == 0:
            break
        else:
            i += 1
    print("case #{0}:".format(j))
    print(result)
