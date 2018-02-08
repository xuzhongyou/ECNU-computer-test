"""
@Time:2018/1/25 16:48
@Author:xuzhongyou
"""
#题目：10000000个小朋友，他们之中有N对好朋友，且好朋友之间有传递性，在给出N对朋友关系后，要求找出一个最大的集合。

#构造并查集
result = [-1]*10000001
sum_ =   [1] *10000001

#result[i]存的是i的父节点
def findroot(i):
    if result[i] == -1:
        return i
    else:
        return findroot(result[i])
n= int(input())
for i in range(n):
    inputs = input().split(" ")
    index1 = int(inputs[0])
    index2 = int(inputs[1])
    a = findroot(index1)
    b = findroot(index2)
    if a!=b:
        result[b] = a
        sum_[a] += sum_[b]
print(max(sum_))





