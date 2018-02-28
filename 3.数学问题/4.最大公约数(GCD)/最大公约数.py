"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:1055
@Website:http://acm.ecnu.edu.cn/problem/1055/
"""
"""
求两个数的最大公约数
Examples
    input
        16 24
    output
        8
"""
def gcd(a,b):
    while True:
        if a == 0:
            print(b)
            break
        elif b == 0:
            print(a)
            break
        else:
            if a>b:
                a = a%b
            else:
                b = b%a

while True:
    try:
        a, b = map(int, input().split(' '))
        gcd(a, b)
    except EOFError:
        pass
