"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3210
@Website:http://acm.ecnu.edu.cn/problem/3210/
"""
"""
You have an empty sequence, and you will be given N queries. Each query is one of these three types:

1 x  -Push the element x into the stack.
2    -Delete the element present at the top of the stack.
3    -Print the maximum element in the stack.
Input
The first line of input contains an integer, N. The next N lines each contain an above mentioned query. (It is guaranteed that each query is valid.)
1≤N≤105
1≤x≤109
1≤type≤3

Output
For each type 3 query, print the maximum element in the stack on a new line.

Output
对于每组测试数据输出一行，每行只有一个数字，即为最少的泛舟次数。
Examples
    input
        10
        1 97
        2
        1 20
        2
        1 26
        1 20
        2
        3
        1 91
        3

    output
        26
        91
"""
# 算法思想：再开一个 stack 用于存放最大元素

class element:
    def __init__(self, index, value):
        self.index = index
        self.value = value

if __name__ == "__main__":
    T = int(input())
    stack = []
    stack_max = []
    index = 0
    for _ in range(T):
        raw = list(map(int, input().split(' ')))
        if raw[0] == 1: # 将数据推入栈内。同时，如果该元素是最大元素，也将它推入最大元素栈中
            index += 1
            stack.append(element(index, raw[1]))
            if len(stack_max) == 0 or stack_max[-1].value <= raw[1]:
                stack_max.append(element(index, raw[1]))
        elif raw[0] == 2: # 如果推出的元素是最大元素，则最大元素栈也推出
            temp = stack.pop()
            if temp.index == stack_max[-1].index and temp.value == stack_max[-1].value:
                stack_max.pop()
        else: # 打印最大栈元素
            print(stack_max[-1].value)
