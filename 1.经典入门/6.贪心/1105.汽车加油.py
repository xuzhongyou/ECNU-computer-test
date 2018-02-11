"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:1105
@Website:http://acm.ecnu.edu.cn/problem/1105/
"""
"""
一辆汽车加满油后可行驶 n 公里。旅途中有若干个加油站。设计一个有效算法，指出应

在哪些加油站停靠加油，使沿途加油次数最少。对于给定的 n(n <= 5000) 和 k(k <= 1024) 个加油站位置，编程计算最少加油次数。

Input
第一行有 2 个正整数 n 和 k，表示汽车加满油后可行驶 n 公里，且旅途中有 k 个加油站。接下来的 1 行中，有 k+1 个整数，依次表示第 i 个加油站与第 i-1 个加油站之间的距离。且第 1 整数表示第一个加油站与起点的距离，起点时汽车已加满油。第 k+1 个整数表示目的地与最后一个加油站的距离。

Output
输出编程计算出的最少加油次数。如果无法到达目的地，则输出 “No Solution!”.
Examples
    input
        7 7
        1 2 3 4 5 1 6 6

    output
        4
"""

if __name__ == "__main__":
    n, k = map(int, input().split(' '))
    gas_station = list(map(int, input().strip().split(' ')))
    t = 0
    gas = n
    end = False
    for i in range(k):
        if gas < gas_station[i]:
            print("No Solution")
            end = True
            break
        else:
            # 需要加油
            if (gas - gas_station[i]) < gas_station[i+1]:
                gas = n
                t += 1
            else:
                gas -= gas_station[i]
    if end == False:
        print(t)
