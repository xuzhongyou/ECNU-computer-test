"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2973
@Website:http://acm.ecnu.edu.cn/problem/2973/
"""
"""
有一种称为 21 点的游戏，在一堆扑克牌中任选 3 张，使 3 张牌的点数的和尽可能大，但不能超过 21 点，否则就 “ 爆 ” 了。

现在这个游戏有了新玩法：扑克牌变成了标有数字的卡片，共有 N 张，从中选取 3 张，使得这 3 张卡片上的数字的和在不超过 M 的情况下尽可能大。

请你编写一个程序，选取 3 张卡片使得它们的和最大。

例如：有 5 张卡片，数字分别为 5、6、7、8、9，M 为 21 时选择 6、7、8，则不超 M 的最大和为 21。又如：有 10 张卡片，数字分别为 93、181、245、214、315、36、185、138、216、295，M 为 500 时选择 245、36、216，则不超 M 的最大和为 497。

Input
第 1 行：整数 $T$ ($1 \le T \le 10$) 为问题数

第 2 行：第一个问题中的 N(3≤N≤100) 和 M(10≤M≤30000)。

第 3 行：第一个问题中的 N 个数 (小于 100000 的正整数)。

第 4 ∽ 2*T+1 行：每两行是每一个问题的输入，格式与第一个问题相同。

Output
对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等），然后在一行中输出最大和。

Examples
    input
        2
        5 21
        5 6 7 8 9
        10 500
        93 181 245 214 315 36 185 138 216 295

    output
        case #0:
        21
        case #1:
        497
"""
"""
算法思想:
枚举两个数，二分查找第三个数
"""

def binary_search(cards, first, second, remain):
    l = second + 1
    r = N - 1
    temp = 0
    while(l<=r):
        mid = (l + r) // 2
        if cards[mid] == remain:
            return M
        elif cards[mid] < remain:
            temp = max(temp, cards[mid] + cards[first] + cards[second])
            l = mid + 1
        else:
            r = mid - 1
    return temp

def max_sum():
    global N, M
    N, M = map(int, input().split(' '))
    cards_lst = list(map(int, input().split(' ')))
    cards_lst.sort()
    total = 0
    for i in range(N-2):
        for j in range(i+1, N-1):
            remain = M - cards_lst[i] - cards_lst[j]
            if ((cards_lst[i] + cards_lst[j]) < M) and (remain >= cards_lst[j]):
                result = binary_search(cards_lst, i, j, remain)
                if result == M:
                    return M
                else:
                    total = max(total, binary_search(cards_lst, i, j, remain))
    return total

if __name__ == "__main__":
    T = int(input())
    for k in range(T):
        total = 0
        total = max_sum()
        print("case #", k, ":", sep='')
        print(total)
