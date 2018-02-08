"""
@Time:2018/2/8 16:26
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2945
@Website:http://acm.ecnu.edu.cn/problem/2945/
"""
"""
有 N 个 Web 页面，给每个 Web 页面分配一个相关系数 Vi （Vi 为正整数），输出具有最大相关系数的页面，如果具有最大相关系数的页面有多个，那么将这些页面全部输出。

Input:
第 1 行：一个正整数 N(20≥N>0)
第 2 行 ∽ N+1 行：每行包含一个字符串和一个整数 Vi，两者之间用一个空格分隔。字符串表示 Web 页面的 URL （字符串长度不超过 100 个字符 , 不含有空格）, 整数 Vi(100≥Vi≥1) 为页面的相关系数。

Output:
输出具有最大相关系数的页面的 URL，如果具有最大相关系数的页面有多个，则按照输入的顺序依次将它们都输出。每行的最后有一个换行符。

Examples:
input
    10
    www.youtube.com 1
    www.google.com 13
    www.google.com.hk 3
    www.alibaba.com 13
    www.taobao.com 5
    www.bad.com 10
    www.good.com 7
    www.baidu.com 8
    www.university.edu.cn 9
    www.ecnu.edu.cn 13
output
    www.google.com
    www.alibaba.com
    www.ecnu.edu.cn
"""
from collections import OrderedDict

web = OrderedDict()
if __name__ == '__main__':
    n = int(input())
    for i in range(0, n):
        raw = (input()).split(' ')
        web[raw[0]] = int(raw[1])
    web_max = [key for key,val in web.items() if val == max(web.values())]
    print(*web_max, sep='\n')
