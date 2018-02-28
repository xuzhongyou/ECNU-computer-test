"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2536
@Website:http://acm.ecnu.edu.cn/problem/2536/
"""
"""
Fibonacci 数列大家已经熟悉 F[1]=1 F[2]=1 F[n] = F[n-1]+F[n-2] (n>2)

有一分数序列：

2/1,3/2,5/3,8/5,13/8,21/13,....

该分数序列的通项为 A[n] = F[n+2] / F[n+1]

求出这个数列的前 n 项之和。n <= 13

Input
    输入数据量 t 表示下面有 t 组数据
    每组数据有一个正整数 n

Output
    对于每组数据输出序列总和，格式见 sample
    要求化成最简形式 即分母分子最大公约数为 1

Examples
    Input
        2
        1
        2
    Output
        2/1
        7/2

"""
from fractions import Fraction
fib = [None, 1,1,2,3,5,8,13,21,34,55,89,144,233,377,610]
t = int(input())
for _ in range(t):
    result = 0
    n = int(input())
    for i in range(1, n+1):
        result += Fraction(fib[i+2], fib[i+1])
    print("{0}/{1}".format(result.numerator, result.denominator))
