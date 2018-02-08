"""
@Time:2018/1/17 17:43
@Author:xuzhongyou
"""
#求最大公约数又公式推导得出的结论是：
#a,b的最大公约数同时也是b,a mod  b的最大公约数

#输入两个正整数，求其最大公约数
#输入： 49 14
#输出：7

def gcd(a,b):
    if a == 0 and b == 0 :
        result = 0
        return result
    elif a==0:
        result = b
        return result
    elif b == 0:
        result = a
        return result
    else:
        if a>b:
            return gcd(b,a%b)
        else:
            return gcd(a,b%a)
a = gcd(6,15)
print(a)