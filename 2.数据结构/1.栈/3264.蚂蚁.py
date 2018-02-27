"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3264
@Website:http://acm.ecnu.edu.cn/problem/3264/
"""
"""
水平线上有 N 只蚂蚁，每只蚂蚁的位置及大小均不同。他们沿着 X 轴爬行，有的向左，有的向右，爬行的速度是一样的，两只蚂蚁相遇大一点的会吃掉小的。

现在从左到右给出每只蚂蚁的大小和爬行的方向（0 表示向左，1 表示向右）。问足够长的时间之后，能剩下多少只蚂蚁？
Input
第 1 行：一个整数 N，表示蚂蚁的数量 (1≤N≤105)。

第 2 到 N+1 行：每行两个数 Ai,Bi (1≤Ai≤109，Bi∈{0,1})，中间用空格分隔，分别表示蚂蚁的大小及爬
行的方向，Bi=0 表示向左，Bi=1 表示向右。

对于 3/8 的数据，存在 x 满足：所有坐标比 x 小的蚂蚁向左爬、坐标比 x 大的蚂蚁向右爬；或者所有坐标比 x 小的蚂蚁向右爬、坐标比 x 大的蚂蚁向左爬。
Output
输出最终剩下的蚂蚁的数量。

Examples:
    input:
        5
        4 0
        3 1
        2 0
        1 0
        5 0

    output:
        2

"""
"""
算法思想:
将两个方向的蚂蚁分成两部分，每次将1号蚂蚁压栈，
遇到0号蚂蚁时，将栈顶小于它的1号蚂蚁出栈，同时记录被吃掉的数量，
若随后栈不为空，该0号蚂蚁也要被吃掉。
"""
if __name__ == "__main__":
    N = int(input())
    stack = []
    result = N
    for _ in range(N):
        A, B = list(map(int, input().split(' ')))
        if B == 1:
            stack.append(A)
        else:
            if len(stack) > 0:
                while stack[-1] < A:
                    stack.pop()
                    result -= 1
                    if len(stack) == 0:
                        break
                if len(stack) > 0:
                    result -= 1
    print(result)
