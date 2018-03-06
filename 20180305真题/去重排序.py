"""
@Time:2018/3/6 17:27
@Author:xuzhongyou
"""
# 有N个1到1000之间的整数（1≤N≤100），对于其中重复的数，只保留一个，把其余相同的数去掉。然后再按照个位数字进行升序排序，如果个位数字相同，则小的数排在前面。
inputs = '2 1 2 1 2 1 2 1 20 20 40 32 67 40 89 300 400 15'.split()
inputs =list(set(inputs))
print(inputs)
inputs.sort(key=lambda k:[k[-1],int(k)])
print(inputs)


