"""
@Time:2018/2/23 8:49
@Author:xuzhongyou
"""
# 2995. 科学计数法
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 任给一个十进制正数 M>0 (M 可能为整数或小数，且最多包含 200 位数字)。写一个程序将其转换成科学计数法表示，形式为 aFb。其中 1≤a<10 且不含前置 0，a 的长度为给定精度 p （p 包括 a 中整数及小数部分但不包含小数点）。a 的值由四舍五入方法确定，M 中有效数字长度小于 p 时，后面填充 0 补足。b 为指数，b=0 时，省略指数部分。
#
# Input
# 第 1 行：一个整数 T（1≤T≤10）为问题数。
#
# 每组测试数据为一行，包含两个数字，之间由一个空格分开。第一个数字是待转换数字 M，第二个数字是要求的输出精度 p （1<p≤30）。
#
# Output
# 对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）。
#
# 然后接下来一行中输出给定数字的科学计数法表示。
#
# Examples
# input
# 3
# 123456789 8
# 0.0045678 3
# 1.8 4
# output
# case #0:
# 1.2345679F8
# case #1:
# 4.57F-3
# case #2:
# 1.800
def process(str_,n):
    #没有小数点的情况下
    lens = len(str_)
    str_+= (abs(n-lens)+2)*'0'
    #去掉点
    index = str_.find('.')
    str_ = str_[:index]+str_[index+1:]
    new_str = ''
    if index == -1:
        num = int(str_[n])
        if num >= 5:
            new_str = str_[:n - 1] + str(int(str_[n - 1:n]) + 1)
        else:
            new_str = str_[:n]
        new_str = new_str[:1] + '.' + new_str[1:] + 'F' + str(lens-1)
        return new_str
    #整数部分是一位，并且不为零时
    elif str_[0]!='0' and len(str_[:index]) == 1 :
        num = int(str_[n])
        if num >= 5:
            new_str = str_[:n - 1] + str(int(str_[n - 1:n]) + 1)
        else:
            new_str = str_[:n]
        new_str = new_str[:1] +'.'+new_str[1:]
        return new_str
    elif str_[0]!='0' and len(str_[:index]) > 1:
        num = int(str_[n])
        if num >= 5:
            new_str = str_[:n - 1] + str(int(str_[n - 1:n]) + 1)
        else:
            new_str = str_[:n]
        new_str = new_str[:1] + '.' + new_str[1:] + 'F' + str(index-1)
        return new_str
    else:
        count = 0
        for item in str_:
            if item=='0':
                count+=1
            else:
                break
        str_ = str_[count:]+'0'*(count+2)
        num = int(str_[n])
        if num >= 5:
            new_str = str_[:n - 1] + str(int(str_[n - 1:n]) + 1)
        else:
            new_str = str_[:n]
        new_str = new_str[:1] + '.' + new_str[1:] + 'F-' + str(count)
        return new_str
if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        inputs = input().split(' ')
        str_ = inputs[0]
        n = int(inputs[1])
        result = process(str_,n)
        print('case #%d:'%(i))
        print(result)







