"""
@Time:2018/2/8 16:22
@Author:xuzhongyou
"""
# 有 n （1≤n≤100）个学生的成绩记录，其中包含学号和成绩两项。按照成绩从高到低顺序输出成绩及格（≥60）学生的学号和成绩。成绩相同时按照学号从小到大顺序输出。
#
# Input
# 第 1 行：输入一个整数 n，表示学生记录数。
#
# 第 2 行 ～ n+1 行：每行是学号（11 位数字）及成绩（0 到 100 之间的整数）。学号和成绩之间有一个空格。
#
# Output
# 每行输出成绩及格学生按要求排序后以一个空格分隔的学号及成绩。
# 5
# 10002130201 90
# 10002130230 80
# 10002130231 85
# 10002130148 48
# 10002130167 90
from operator import itemgetter
n = int(input())
temp = []
for i in range(n):
    str_ = input().split(' ')
    if int(str_[1])>=60:
        temp.append((str_[0],int(str_[1])))
        continue
result = sorted(temp,key=lambda item :item[0],reverse=False)
# print(result)
results = sorted(result,key=lambda item:item[1],reverse=True)
# results = sorted(temp,key=itemgetter(1,0),reverse=True)
# print(results)
for item in results:
    print(item[0],item[1])