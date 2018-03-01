"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3037
@Website:http://acm.ecnu.edu.cn/problem/3037/
"""
"""
请编写程序实现两个十六进制整数的加法。

例如：十六进制整数 3762 和 05C3，3762+05C3 =3D25

十六进制整数 CB9 和 957，CB9+957=1610

Input
第 1 行：一个整数 T (1≤T≤10) 为问题数。

接下来 T 行，每行输入两个十六进制整数 n 和 m （n，m 为不超过 200 位的十六进制整数），A~F 全部为大写字母。 两个整数之间用一个空格分隔。

Output
对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）。然后对应每个问题在一行中输出两个十六进制整数相加的结果，字母全部用大写字母。

Examples
    input
        3
        3762 05C3
        CB9 957
        F 1

    output
        case #0:
        3D25
        case #1:
        1610
        case #2:
        10

"""

if __name__ == "__main__":
    T = int(input())
    for j in range(T):
        A, B = map(lambda n:int(n, 16), input().split(' '))
        print("case #{}:".format(j))
        print(hex(A+B)[2:].upper())
