"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3298
@Website:http://acm.ecnu.edu.cn/problem/3298/
"""
"""
远岛子五月二十号去食堂买夜宵，她发现了令人悲戚的一幕，食堂门口排满了人，而更让人悲戚的是每当有一个人排到队伍的末尾，
如果他/她前面是异性，他们就马上牵手走人了。
给定一个序列，从前往后排入队伍的学生的性别，女生用 0 表示，男生用 1 表示，
远岛子想要知道最终队伍的长度（假设不碰到异性不会有人离开）。
Input
第一行为数据的组数 T(T≤100)

每组数据有一行字符串 S，为排队的序列，|S| 为 S 的长度，保证 1≤|S|≤103

Output
一行数字，最终队伍的长度。

Examples:
    input:
        2
        10
        110

    output:
        0
        1

"""

T=int(input())
for i in range(T):
    S=list(map(int,list(input())))
    stack = []
    for j in range(len(S)):
        stack.append(S[j])
        if len(stack) ==1:
            continue
        else:
            if stack[-1] != stack[-2]:
                stack.pop()
                stack.pop()
    print(len(stack))
