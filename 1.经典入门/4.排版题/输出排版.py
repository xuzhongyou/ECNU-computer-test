"""
@Time:2018/1/4 9:43
@Author:xuzhongyou
"""
#输入一个高度h,输出一个高为h,上底边为h的梯形
#输入一个整数h(1<=h<=1000)
#对于这种题目思路要清晰，有多少个*,有多少个空格
num = int(input())
for i in range(num):
    #每一行有2n+2个字符
    star = num+2*i
    blank = 2*num+2 - star
    str_ = " "*blank +"*"*star
    print(str_)
