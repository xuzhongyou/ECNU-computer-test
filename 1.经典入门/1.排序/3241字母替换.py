"""
@Time:2017/12/29 11:02
@Author:xuzhongyou
"""
#输入一个长度不超过80的字符串S，将字符串S中所有下标为偶数位置的英文字母转换为小写字母，若该位置上不是字母，则不转换。

#例如，若输入ABC4efG，则输出aBc4efg。
#Input
#第1行为一个整数T（1≤T≤10）为问题数。

#接下来T行，每行输入一个字符串，字符串长度≤80。

#Output
#对于每个问题，输出一行问题的编号（0开始编号，格式：case #0: 等），然后输出替换后的字符串
# case #0:
# eWrDfDdfldfke
# case #1:
# 213233439849384934
# case #2:
# ?Df":*(**^&WeqwewE

#Tips:少一个：也是无法AC的
input_n = int(input())
def char_replace(input_n):
    temp_n = input_n
    while(temp_n):
        str_1 = input()
        str_1 = list(str_1)
        for i,char_ in enumerate(str_1):
            if i%2 == 0:
                str_1[i] = char_.lower()
        print('case #%d:'%(input_n-temp_n) )
        print("".join(str_1))
        temp_n -= 1
char_replace(input_n)



