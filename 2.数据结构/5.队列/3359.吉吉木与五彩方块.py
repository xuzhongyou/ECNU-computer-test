"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3359
@Website:http://acm.ecnu.edu.cn/problem/3359/
"""
"""
吉吉林有 n 个方块，她把它们排成一列，这些方块五彩缤纷，非常好看。

但是有一件事情会让吉吉林非常难受，就是相邻的两个方块颜色一样。所以吉吉林想调整一下这些方块的顺序，使得不存在两个连续的颜色相同的方块。

这能做到吗？怎么做到？

Input
第一行一个整数 n (1≤n≤50 000)。

第二行 n 个整数，a1,a2,…,an (1≤ai≤n)，分别表示这 n 个方块的颜色。

Output
输出 a1,a2,…,an 的一个排列 b1,b2,…,bn，使得 ∀1≤i≤n−1,bi≠bi+1。

如果无解，输出 −1。
Examples
    input
        6
        2 3 1 4 2 2

    output
        2 1 2 3 2 4
"""
"""
算法思想:
这个想法是先把最高频率的字符（贪婪的方法）进行排列。
使用一个优先级队列（或二进制最大堆）并放置所有字符并按其频率排序（最高频率字符为根）。
一个接一个地从堆中取出最高频率的字符并添加结果。
添加后，我们降低角色的频率，并暂时将此角色移出优先级队列，以便下次不会选取
然后继续从优先队列里面挑选频率最高的，并放入结果中。
将之前暂时移除的优先队列放入队列中
如此循环往复
"""
import queue


if __name__ == '__main__':
    N = int(input())
    cube = input().split(' ')

    raw = [[str(i), 0] for i in range(10)]
    for i in cube:
        raw[int(i)][1] -= 1

    # 为了在优先队列里面，频率高得得到优先，将list逆置
    result = [[freq, key] for key, freq in raw]

    # 建立一个优先队列，并将结果移入优先队列中
    que = queue.PriorityQueue()
    for val in result:
        if val[0] <0:
            que.put(val)

    # 按照前述算法思想，进行元素重排
    out = ''
    pre = [0, '']
    while(que.empty() == False):
        temp = que.get()
        out += temp[1]
        if pre[0] < 0:
            que.put(pre)

        temp[0] += 1
        pre = temp

    if len(out) == sum(1 for x in cube):
        print(*out, sep=' ')
    else:
        print('-1')
