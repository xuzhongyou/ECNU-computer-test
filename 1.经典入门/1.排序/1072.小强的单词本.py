"""
@Time:2018/1/3 18:02
@Author:xuzhongyou
@Source:ECNU Online Judge
@Problem:1072
@Website:http://acm.ecnu.edu.cn/problem/1072/
"""
# 大二的小强马上就要英语四级考试了，小强不想像别人一样拿着四级词汇书背啊背，于是他决定每天阅读几篇英语文章，并把其
# 中需要记忆的单词写到 notobook 上，一周之后问题来了，单词太乱了，现在小强决定请学计算机的同学你帮他解决这个问题。
# Input
# 第一行为一个数字 N ( 0 < n <= 1000 ), 接下来的 N 行中，每行只含有一个单词 (连续的小写英语字母)，每个单词长度不超过 32(注意 ‘\0’)!
#
# Output
# 将这单词按照字典序排序好，去除重复的单词，并输出，同样每行只输出一个单词。
# Hint:
# 字典序中
# abc < bbc
# abc < abcd

result = []
num = int(input())
while(num):
    result.append(input())
    num -=1
new_result = sorted(set(result))
for res in new_result:
    print(res)




