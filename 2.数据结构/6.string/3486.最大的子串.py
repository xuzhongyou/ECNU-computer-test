"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3486
@Website:http://acm.ecnu.edu.cn/problem/3486/
"""
"""
字符串的大，不在于长，而在于妙。

现在给出由数字组成的字符串 s，求出字符串的所有的非空连续子串中，最妙的那个子串。

一个字符串的妙是这样定义的：将这个子串所表示的整数（有可能带前导 0），除以 10L（其中 L 为字符串的长度）。比如说 123456789 的子串 456 的妙为 456103=0.456。

Input
给出一行一个字符串 s (1≤|s|≤20 000)。

Output
输出最妙的那个子串。如果有多个，输出最短的那个。如果最短的最妙的子串也有多个，输出字典序最小的那个。

Examples
    input
    123456789
    321

    output
    9
    321
"""
while True:
    try:
        S = input().rstrip('0')
        result = ''
        MAX = ''
        if S:
            for _ in S:
                if _ > MAX:
                    MAX = _
            for i in range(len(S)):
                if S[i] == MAX:
                    if result < S[i:]:
                        result = S[i:]
            print(result)
        else:
            print(0)
    except EOFError:
        break
