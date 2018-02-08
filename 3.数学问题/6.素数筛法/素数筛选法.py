"""
@Time:2018/1/17 18:07
@Author:xuzhongyou
"""
#首先素数就是质数
#素数判定
#问题给定一个数，判断其是否为素数
#输入多组数据
#输出：每组输入若为素数则输出yes,否则输入no

def judge(x):
    flag = 0
    for i in range(2,int(x**0.5+1)):
        if x%i == 0:
            flag = 1
            break
    if flag== 0:
        print("yes")
    else:
        print("no")

judge(11)