"""
@Time:2018/2/8 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3368
@Website:http://acm.ecnu.edu.cn/problem/3368/
"""
"""
kblack 吃鸡成瘾。为此他决定逃课吃鸡！

但是学校有规定，旷课到一定次数，是不给予期末考的资格的。

因此 kblack 决定每门课最多逃两次。

现在告诉你，一个学期有 n 节课程，第 i 节课的科目是 si，时间为 ti。

你需要告诉 kblack 这个学期他逃课吃鸡的最大时间是多少。

Input
    第一行给出一个整数 n (1≤n≤10 000)，为该学期课程节数。

    接下来 n 行，第 i+1 行 给出第 i 节课的科目 si 和时间 ti，中间用空格隔开。si 由小写字母组成，1≤|si|≤10，1≤ti≤10 000。若 si=sj，则认为第 i 节课和第 j 节课是同一门课。

Output
    输出 kblack 该学期逃课吃鸡的最大时间。

Examples
    input
        7
        english 2
        english 1
        math 3
        english 3
        cook 5
        eatchicken 10
        cook 5
    output
        28
"""
if __name__ == '__main__':
    total = 0
    result = {}
    num = int(input())
    for i in range(0, num):
        raw = (input()).split(' ')
        key = raw[0]
        value = int(raw[1])
        try:
            result[key]
            result[key].append(value)
        except KeyError:
            result[key] = [value]

    for key in result.keys():
        value_lst = result[key]
        value_lst.sort(reverse=True)
        if len(value_lst) == 1:
            total += value_lst[0]
        else:
            total += sum([value_lst[0], value_lst[1]])
    print(total)
