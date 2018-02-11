"""
@Time:2018/2/11 10:42
@Author:xuzhongyou
"""
# 3098. 字符串的交织
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 在一行中输入 2 个字符串 S1 和 S2，字符串本身不含空格的字符串 (长度均不超过 80)，2 个字符串之间以 1 个空格分隔。
#
# 将这 2 个字符串交织在一起 (laceString)，输出 laceString 后的字符串。
#
# Note：
#
# 字符串交织指：先取第一个字符串的第 1 个字符，后取第二个字符串的第 1 个字符，再取第一个字符串的第 2 个字符，再取第二个字符串的第 2 个字符，
# 如此重复，直至取完其中一个字符串的全部字符，最后取另一个字符串的全部剩余字符。
#
# 例子：
#
# abc 123 —> a1b2c3
#
# 123 abc —> 1a2b3c
#
# abcde 123 —> a1b2c3de
#
# abc 1234567 —> a1b2c34567
#
# Input
# 在一行中输入 2 个字符串，字符串本身不含空格的字符串 ( 长度均不超过 80)，2 个字符串之间以 1 个空格分隔。
#
# Output
# 输出 laceString 后的字符串。
#
# Examples
# input
# abc 123
# output
# a1b2c3

if __name__ == '__main__':
    strings = input().split(' ')
    string1 = strings[0]
    string2 = strings[1]
    list1 = list(string1)
    list2 = list(string2)
    for index,item in enumerate(list2):
        list1.insert(2*index+1,item)
    print(''.join(list1))