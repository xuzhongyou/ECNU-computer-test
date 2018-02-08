"""
@Time:2018/1/17 18:00
@Author:xuzhongyou
"""
#最小公倍数为乘积除以最大公约数

def gcd(a,b):
    if a == 0 and b == 0:
        return 0
    elif a ==0:
        return b
    elif b == 0:
        return a
    else:
        if a>b:
            return gcd(b,a%b)
        else:
            return  gcd(a,b%a)
num_1 = 2
num_2 = 3
gcd_num = gcd(num_1,num_2)
print(int(num_1*num_2/gcd_num))
