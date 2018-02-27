"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2995
@Website:http://acm.ecnu.edu.cn/problem/2995/
"""
"""
任给一个十进制正数 M>0 (M 可能为整数或小数，且最多包含 200 位数字)。写一个程序将其转换成科学计数法表示，形式为 aFb。其中 1≤a<10 且不含前置 0，a 的长度为给定精度 p （p 包括 a 中整数及小数部分但不包含小数点）。a 的值由四舍五入方法确定，M 中有效数字长度小于 p 时，后面填充 0 补足。b 为指数，b=0 时，省略指数部分。

Input
第 1 行：一个整数 T（1≤T≤10）为问题数。

每组测试数据为一行，包含两个数字，之间由一个空格分开。第一个数字是待转换数字 M，第二个数字是要求的输出精度 p （1<p≤30）。

Output
对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）。

然后接下来一行中输出给定数字的科学计数法表示。

Examples
    input
        3
        123456789 8
        0.0045678 3
        1.8 4

    output
        case #0:
        1.2345679F8
        case #1:
        4.57F-3
        case #2:
        1.800
"""
"""
Note:
Using Decimal to handle large float number
"""
from decimal import Decimal

if __name__=='__main__':
    T = int(input())
    for i in range(T):
        temp = input().split()
        M = Decimal(temp[0])
        P = int(temp[1])
        S = '{{:.{0}e}}'.format(P-1).format(M).split('e')
        print("case #{0}:".format(i))
        if int(S[1]) == 0:
            print(S[0])
        else:
            print(S[0] + 'F' + str(int(S[1])))
