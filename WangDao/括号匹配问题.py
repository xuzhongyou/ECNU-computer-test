"""
@Time:2018/1/4 17:22
@Author:xuzhongyou
"""
#输入包括多组数据，每组数据一行，包含一个字符串，只包含左右括号和大小写字母，字符串长度不超过100
#输出两行，第一行是源字符串，第二行由$,?空格组成分别表示左括号不匹配和右括号不匹配
#inputs       )(rttyy())sss)(
#outputs

# str_ = ')(rttyy())sss)('
str_ = input()
stack = []
str_list = list(str_)
print(str_)
for i,char_ in enumerate(str_list):
    if char_ ==")":
        if len(stack) == 0:
            str_list[i] = "?"
        else:
            stack.pop()
            str_list[i] = " "
    elif char_=="(":
        stack.append(i)
        str_list[i] = " "
    else:
        str_list[i] = " "

for item in  stack:
    str_list[item] = "$"
print("".join(str_list))



