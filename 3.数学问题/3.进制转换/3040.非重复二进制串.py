"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3040
@Website:http://acm.ecnu.edu.cn/problem/3040/
"""
"""
对于一个二进制串 b=bkbk-1…b1，如果对任意 i (1≤i≤k-1)，满足 bi≠bi+1，那么 b 称为非重复二进制串。给定一个正整数，输出其二进制表示中最长的非重复二进制串的长度。

Input
第 1 行：一个整数 T (1≤T≤10) 为问题数。

第 2~T+1 行，每行一个十进制表示的正整数 n，(031

)。
Output
对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等），在接下来一行中输出 n 的二进制表示中最长的非重复二进制串的长度（前置 0 不计算在内）。

Examples
    input
        3
        7
        10
        999
    output
        case #0:
        1
        case #1:
        4
        case #2:
        2
"""

if __name__ == "__main__":
    T = int(input())
    for j in range(T):
        n = int(input())
        maxn = 0
        cnt = 0
        temp = 2
        while n:
            if (n&1) != temp:
                cnt += 1
            else:
                cnt = 1
            if cnt > maxn:
                maxn = cnt
            temp = n&1
            n = n >> 1
        print("case #{}:".format(j))
        print(maxn, sep=',')
