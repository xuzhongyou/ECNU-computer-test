"""
@Time:2018/2/8 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3368
@Website:http://acm.ecnu.edu.cn/problem/3368/
"""
"""
林吉吉非常想要读PhD，为此他必须要阅读各种各样的论文。就在前几天，BOSS给林吉吉指定了 n 篇论文，并给出了第 i 篇论文的难度系数 di，BOSS要求林吉吉阅读其中的 k 篇论文并在完成之后向他汇报。

林吉吉是一个有理想有目标的人，随便选择其中 k 篇文章敷衍是他所不能接受的，林吉吉想要的是阅读其中最难的 k 篇论文。请按论文编号升序输出难度系数最高的 k 篇论文。

Input
第一行为数据组数 T

每组数据的第一行为 n,k 分别代表论文的总数和BOSS想要林吉吉阅读的论文数目，接下来一行 n 个数，第 i 个数表示第 i 道题的难度系数

数据约束：T≤1001≤k≤n≤1031≤ai≤103，保证不存在两篇难度系数相同的论文

Output
每组数据输出一行 k 个数，按论文编号升序输出难度系数最高的 k 篇论文的编号，用空格分开

Examples
    input
        2
        3 2
        3 2 1
        3 2
        2 3 4

    output
        1 2
        2 3
"""
from collections import OrderedDict

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n, k = map(int, input().split(' '))
        paper = map(int, input().split(' '))
        data = {k+1:v for k, v in enumerate(paper)}
        paper2read = OrderedDict(sorted(data.items(), key=lambda x: x[1], reverse=True))
        result = sorted([v for v in list(paper2read.keys())[:k]])
        print(*result, sep=' ')
