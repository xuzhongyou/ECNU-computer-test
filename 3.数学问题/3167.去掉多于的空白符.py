"""
@Time:2018/2/23 12:00
@Author:xuzhongyou
"""
# 3167. 去掉多余的空白符
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 去除一段文字中多余的 whitespace(空格、制表符和换行符），即：当两个单词之间有多个空白符时，只保留第 1 个空白符。
#
# 注意：每行首部和 尾部多余的空白符也需要去除。多余的空行也需要去除。
#
# 例如：
#
# Input:
#
# The C
#
# programming language
#
# Output:
#
# The C
#
# programming language
#
# Input
# 输入一段文本
#
# Output
# 输出去除多余的 whitespace 后的文本。
#
# Examples
# input
# The     C
# programming     language
# output
# The C
# programming language
import re
p = re.compile('|'.join(['\n','\t',' ']))

def process(str_):
    str1 = p.split(str_)
    new_list = []
    for item in str1:
        if item !='':
            new_list.append(item)
    return ' '.join(new_list)



if __name__ == '__main__':
    inputs = input()
    result = process(inputs)
    if len(result)>0:
        print(''.join(result))

