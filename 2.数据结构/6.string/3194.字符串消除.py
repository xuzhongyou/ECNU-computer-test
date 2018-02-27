"""
@Time:2018/2/11 10:58
@Author:xuzhongyou
"""
# 3194. 字符串消除
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 给定一个由大写字母’A’、’B’、’C’构成的字符串s，按如下进行消除过程：
#
# 1、字符串s中连续相同字母组成的子串，如果子串的长度大于1，那么这些子串会被同时消除，余下的字符拼成新的字符串。
#
# 例如：”ABCCBCCCAA”中”CC”,”CCC”和”AA”会被同时消除，余下”AB”和”B”拼成新的字符串”ABB”。
#
# 2、反复进行上述消除，直到新的字符串中相邻字符都不相同为止。
#
# 例如：”ABCCBCCCAA”经过一轮消除得到”ABB”，再经过一轮消除得到”A”。
#
# 假设在对字符串s消除开始前，允许在s中任意位置(第一个字符之前、最后一个字符之后以及相邻两个字符之间)插入任意一个字符(‘A’,’B’或者’C’)，得到字符串t，然后对字符串t经过一系列消除。
#
# 请问该如何插入字符，使得字符串t中被消除掉的字符总数（包括插入的字符）最多？
#
# Input
# 第 1 行：整数 T (1≤T≤10) 为问题数。
#
# 第 2 ~ T+1 行：每个问题占一行，每行输入一个由’A’、’B’、’C’组成的字符串s，长度不超过100。
#
# Output
# 对每个测试数据，首先输出一行问题的编号（0 开始编号，格式：case #0: 等）。在接下来一行中输出被消除掉的最大字符数。
#
# Examples
# input
# 3
# ABCBCCCAA
# AAA
# ABC
# output
# case #0:
# 9
# case #1:
# 4
# case #2:
# 2
#这一段好好体会,inputs是个list,添加的方式是根据第二个来决定是否添加第一个
#这是一个很好的例子用来解决重复问题
def judge(inputs):
    lens = len(inputs)
    if lens == 0 : return 0
    result = []
    #添加一个防止list越界问题
    inputs.append('#')
    input_len = len(inputs)
    flag = 0
    #用flag标志位来解决重复过后第一个不同的字符，例如ABCBCCCA 中的CA
    for i in range(1,input_len):
        if inputs[i] != inputs[i-1]:
            if flag == i-1:
                result.append(inputs[i-1])
            flag = i
    if len(result) == lens:return 0
    return lens-len(result)+judge(result)




if __name__ == '__main__':
    T = int(input())
    for index in range(T):
        result= []
        inputs = list(input())
        lens = len(inputs)
        for i in range(lens):
            temp = inputs[:]
            temp.insert(i, 'A')
            result.append(judge(temp))
            temp = inputs[:]
            temp.insert(i, 'B')
            result.append(judge(temp))
            temp = inputs[:]
            temp.insert(i, 'C')
            result.append(judge(temp))
        print('case #%d:'%(index))
        print(max(result))
