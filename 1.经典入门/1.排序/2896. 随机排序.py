"""
@Time:2018/2/8 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:2896
@Website:http://acm.ecnu.edu.cn/problem/2896/
"""
"""
给定一组以一个空格分隔的只含大小写字母的字符串。与普通字典序不同，按照给定的字母顺序对这组字符串排序。设两个字符串的字母不会完全相同。如：Hat、hat、HAt 等不会同时出现。

例如：字母顺序为 QWERTYUIOPASDFGHJKLZXCVBNM 时，一组字符串 hat cat bat book bookworm Dallas Austin Houston fire firefox fumble 的排序结果为：Austin Dallas fumble fire firefox Houston hat cat book bookworm bat。

Input
每组数据由 2 行组成，第 1 行为字母顺序（26 个大写字母），第 2 行是需要排序的一组字符串（只含大小写字母，长度不大于 20）。
数据不多于 100 组。需要排序的一组字符串中包含的字符串个数至少 1 个，至多 100 个。

Output
对于每一组数据，输出排序后的字符串。字符串之间输出一个空格，最后一个字符串后面没有空格，而是输出一个换行符。

Examples
    input
        QWERTYUIOPASDFGHJKLZXCVBNM
        hat cat bat book bookworm Dallas Austin Houston fire firefox fumble
        QWERTYUIOPASDFGHJKLZXCVBNM
        How are you
        QAZWSXEDCRFVTGBYHNUJMIKOLP
        How are you
        ABCDEFGHIJKLMNOPQRSTUVWXYZ
        How are you
    output
    Austin Dallas fumble fire firefox Houston hat cat book bookworm bat
    you are How
    are you How
    are How you
"""

def custom_sort(string, custom):
    custom_dict = {v: chr(97 + k) for (k, v) in enumerate(custom)}
    string_lst = list(string)
    return "".join([custom_dict[s.upper()] for s in string_lst])

if __name__ == '__main__':
    while True:
        try:
            custom = list(input())
            if custom == "":
                break
            string = (input()).split(' ')
            string_sorted = sorted(string, key= lambda s: custom_sort(s, custom))
            print(*string_sorted, sep=' ')
        except EOFError:
            break
