"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3038
@Website:http://acm.ecnu.edu.cn/problem/3038/
"""
"""
给定长度为 N 的字符串 S，要构造一个长度为 N 的字符串 T。起初，T 是一个空串，随后反复执行下列两个操作中的任意一个，最终 目标是构造字典序尽可能小的字符串 T。

操作一：从 S 的头部取一个字符，加到 T 的尾部。

操作二：从 S 的尾部取一个字符，加到 T 的尾部。

例如：输入 N=6，S=“ACDBCB”；构造的 T=“ABCBCD”

Input
    第 1 行：整数 T(1≤T≤10) 为问题数。

    第 2 行：第一个 问题中的 N(1≤N≤500)，表示字符串 S 的长度。

    第 3 行：输入一个字符串 S，只包含大小写英文字母。

    第 4 ∽2*T+1 行：后面问题的数据 ，格式与第 1 个问题相同。

Output
    对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等），然后 输出由 S 字符串构造出来的 字典序尽可能小的字符串 T。
Examples
    input
        3
        2
        ba
        5
        SORTS
        10
        Sarumanarm

    output
        case #0:
        ab
        case #1:
        SORST
        case #2:
        Samranamru

"""
if __name__ == "__main__":
    T = int(input())
    for _ in range(T):
        N = int(input())
        S = list(input())
        l , r = 0, -1
        out = []
        for i in range(N):
            if S[l] > S[r]:
                out.append(S[r])
                r -= 1
            elif S[l] < S[r]:
                out.append(S[l])
                l += 1
            else:
                l2, r2 = l+1, r-1
                while l2 < N + r2:
                    if S[l2] != S[r2]:
                        break
                    else:
                        l2 += 1
                        r2 -= 1
                if l2 >= N + r2:
                    out.append(S[r])
                    r -= 1

                elif S[l2] > S[r2]:
                    out.append(S[r])
                    r -= 1
                else:
                    out.append(S[l])
                    l += 1
        print('case #{n}:'.format(n=_))
        print(*out, sep='')
