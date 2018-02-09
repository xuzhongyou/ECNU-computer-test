"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3026
@Website:http://acm.ecnu.edu.cn/problem/3026/
"""
"""
给定一行由英文单词、标点符号、数字和空格组成的字符串，对其进行排版输出，要求：

1、原文中由空格分开的连续非空字符串视为一个单词。单词不能分割或跨行输出，同一行的相邻单词由一个或多个空格分开，每行行首和行尾不能为空格，排版后行数尽可能少；

2、除最后一行外，每行长度为 M，长度不足 M 的由空格补足，空格在所有单词之间尽可能均匀分布，在满足上述条件下，空格尽可能置于靠右的位置；

3、最后一行长度不能超过 M，每两个单词之间由一个空格分开，根据实际长度输出，长度不足 M 的不用补足。

Input
第 1 行：一个整数 T (1≤T≤10) 为问题数。

接下来共有 2*T 行，每个问题包含 2 行数据，其中：

第 1 行是一个正整数 M （10≤M≤70）为排版后每行长度；

第 2 行是一个待排版字符串，字符串长度 L （1≤L≤2000），至少包含一个单词，每个单词长度 < M/2。

Output
对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）

然后在接下来的数行中，依次输出排版后的文本。
Examples
    input
        3
        10
        abc 123 de fg hi, jkl mn "o p" qq rs t uvwx yz.
        10
        a bb c d dddd e f ghhh ijkl m nop
        20
        abc

    output
        case #0:
        abc⌂123⌂de
        fg⌂hi,⌂jkl
        mn⌂⌂"o⌂⌂p"
        qq⌂⌂rs⌂⌂⌂t
        uvwx⌂yz.
        case #1:
        a⌂bb⌂⌂c⌂⌂d
        dddd⌂⌂e⌂⌂f
        ghhh⌂⌂ijkl
        m⌂nop
        case #2:
        abc
        （其中⌂表示输出的空格）
        Hints
        例如，在case #1输出的第一行中，共有5个空格，其在4个单词之间的分布为1 2 2，其中空格尽可能置于靠右的位置，其他分布如2 1 2，2 2 1都不符合要求。
"""

def add_blank(lst, total_len):
    blank_space_num = len(lst) - 1
    blank_insert_total_num = cut_len - total_len
    blank_space = [0] * blank_space_num
    if blank_space_num == 0:
        return
    else:
        while blank_insert_total_num >0:
            for i in range(blank_space_num-1, -1, -1):
                blank_space[i] += 1
                blank_insert_total_num -= 1
                if blank_insert_total_num == 0:
                    break
        for i, v in enumerate(blank_space):
            lst[i] += " " * v

if __name__ == '__main__':
    total = int(input())
    for k in range(total):
        print("case #" + str(k) + ':')
        cut_len = int(input())
        string = input().strip().split(' ')

        total_len = 0
        N         = 0
        temp      = []
        end       = False
        for i, str_ in enumerate(string):
            if (total_len + len(str_) + N) <= cut_len:
                temp.append(str_)
                N += 1
                total_len += len(str_)
            else:
                add_blank(temp, total_len)
                print(''.join(temp))
                N = 1
                total_len = len(str_)
                temp = [str_]
            if i == len(string) - 1:
                print(' '.join(temp))
