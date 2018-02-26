"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2853
@Website:http://acm.ecnu.edu.cn/problem/2853/
"""
"""
计算集合 A 和集合 B 的交集 C=A∩B、并集 D=A∪B 和差集 E=A−B。

集合的元素值均为整数，集合 A 和集合 B 的元素个数均不大于 1000。集合 A 和集合 B 可能是空集。

Input
第 1 行由两个用一个空格分隔的整数组成，分别是集合 A 和集合 B 的元素个数。

第 2 行由用一个空格分隔的若干整数组成（空集时为空行），表示集合 A 的每个元素值。

第 3 行由用一个空格分隔的若干整数组成（空集时为空行），表示集合 B 的每个元素值。

Output
共有 3 行，分别表示集合 C、集合 D 和集合 E。

一个集合的输出以左花括号开头，右花括号结束。中间显示的集合元素按升序排列，元素之间包含一个逗号。空集时输出为 {}。
然后在接下来的数行中，依次输出排版后的文本。
Examples
    input
        5 6
        1 2 3 4 5
        15 14 13 12 11 10

    output
        {}
        {1,2,3,4,5,10,11,12,13,14,15}
        {1,2,3,4,5}
"""


num = input()
A = set(map(int,input().split()))
B = set(map(int,input().split()))
C = A & B
D = A | B
E = A - B
listC = sorted(list(C))
listD = sorted(list(D))
listE = sorted(list(E))
print("{%s}"%(','.join(map(str,listC))))
print("{%s}"%(','.join(map(str,listD))))
print("{%s}"%(','.join(map(str,listE))))
