"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2981
@Website:http://acm.ecnu.edu.cn/problem/2981/
"""
"""
康夫的好朋友机器猫是个很喜欢零食的人，经常会买很多很多的零食放着，每次康夫饿了都会问他要，可是机器猫只会把价格最低的零食分给康夫吃。由于机器猫的零食实在太多，每次找价格最低的零食非常麻烦。希望你编写一个程序帮助他。

Input
第 1 行：整数 T (1≤T≤10) 为问题数

第 2 行开始的数据：每个问题的第一行是一个整数 n (1≤n≤100 000)，表示后面有多少个操作，接下来每行一个操作。操作共有两种形式：

B p 表示机器猫买了一种价格为 p 的零食，其中 p 为整数 (0≤p≤10000)
G 表示机器猫给了康夫一种零食
Output
对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等），然后在一行中输出每次机器猫给出零食的价格。

Examples
    input
        2
        10
        B 212
        B 842
        G
        G
        B 213
        B 583
        B 841
        B 109
        B 442
        G
        8
        B 20
        B 10
        G
        B 9
        G
        B 100
        B 25
        G

    output
        case #0:
        212
        842
        109
        case #1:
        10
        9
        20
"""
import heapq

t = int(input())
for ti in range(t):
    print('case #%d:' % ti)
    n = int(input())
    heap = []
    for i in range(n):
        s = input()
        if s.startswith('B'):
            heapq.heappush(heap, int(s[2:]))
        else:
            print(heapq.heappop(heap))
