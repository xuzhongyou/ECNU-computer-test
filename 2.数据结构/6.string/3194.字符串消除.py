"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3194
@Website:http://acm.ecnu.edu.cn/problem/3194/
"""
"""
去除一段文字中多余的 whitespace(空格、制表符和换行符），即：当两个单词之间有多个空白符时，只保留第 1 个空白符。

注意：每行首部和 尾部多余的空白符也需要去除。多余的空行也需要去除。

例如：

Input:

The C

programming language

Output:

The C

programming language

Input
输入一段文本

Output
输出去除多余的 whitespace 后的文本。

Examples
    input
        The     C
        programming     language


    output
        The C
        programming language

"""

import re
contents = []
while True:
    try:
        line = input()
        line = re.sub(r'([ \t\n])[ \t\n]+',r'\1', line)
        line = line.strip()
        if line:
            contents.append(line)
    except EOFError:
        break
print('\n'.join(contents))
