"""
@Time:2018/2/24 14:31
@Author:xuzhongyou
"""
# 3363. 吉吉木和木木吉
# Time limit per test: 1.0 seconds
#
# Memory limit: 256 megabytes
#
# 吉吉木和木木吉在玩一个骰子游戏。他们各自带了一个骰子，这两个骰子六个面向上的概率都是相等的。
#
# 吉吉木和木木吉同时抛出它们的骰子，如果他们向上的点数相同，那么他们再扔一次；否则，点数高的那个人赢。
#
# 现在分别告诉你吉吉木的骰子和木木吉的骰子上的点数，求吉吉木获胜的概率。
#
# Input
# 第一行六个整数，表示吉吉木的骰子六个面上的点数。
#
# 第二行六个整数，表示木木吉的骰子六个面上的点数。
#
# 数据保证：
#
# 所有点数都是在 1 到 6 之间的。
# 12 个数字不全相同。
# Output
# 输出一个浮点数，表示概率。绝对误差不超过 10−4。
#
# Examples
# input
# 1 2 3 4 5 6
# 1 2 3 4 5 6
# output
# 0.50000
# input
# 4 4 4 4 1 1
# 3 3 3 3 3 3
# output
# 0.66667
input1 = map(int,input().split(' '))
input2 = map(int,input().split(' '))
data = []
for i,j in zip(input1,input2):
    data.append((i,j))
count = 0
equal = 0
for item in data:
    if item[0]>item[1]:
        count+=1
    if  item[0]==item[1]:
        equal+=1
if equal ==6:
    print(format(0.5,'0.5f'))
else:
    print(round(count/(6-equal),5))