"""
@Time:2018/1/3 18:28
@Author:xuzhongyou
@Source:ECNU Online Judge
@Problem:1852
@Website:http://acm.ecnu.edu.cn/problem/1852/
"""
# Consider the set of all reduced fractions between 0 and 1 inclusive with denominators less than or equal to N.
# Here is the set when N=5:
# 0/1 1/5 1/4 1/3 2/5 1/2 3/5 2/3 3/4 4/5 1/1
# Write a program that, given an integer N between 1 and 160 inclusive, prints the fractions in order of increasing magnitude.
# Input
# One line with a single integer N.
# Output
# One fraction per line, sorted in order of magnitude.

num = int(input())
dict_ = {}
dict_['0/1'] = 0
for i in range(1,num):
    for j in range(1,num+1):
        str_ = '%s/%s'%(i,j)
        if i == 1 :
            dict_[str_] = i/j
        else:
            if i<j and j%i !=0:
                dict_[str_] = i/j

result = sorted(dict_.items(),key = lambda item:item[1])
for rest in result:
    print(rest[0])

# Qing's solution
from fractions import Fraction
from  math import gcd

num = int(input())
result = []
for i in range(1, num+1):
    for j in range(0, i+1):
        if gcd(i, j) == 1:
            result.append(Fraction(j/i))

result = [str(a.limit_denominator()) for a in sorted(result)]
for i in result:
    if i == '0':
        print('0/1')
    elif i == '1':
        print('1/1')
    else:
        print(i)
