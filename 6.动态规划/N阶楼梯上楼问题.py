"""
@Time:2018/2/22 14:11
@Author:xuzhongyou
"""
#一次可以走两阶或一阶，问有多少种上楼方式（要求采用非递归算法）
#可以理解为数学归纳法：
#n阶楼梯的上方方式取决于n-1阶个n-2阶
#假设F(n)是n阶楼梯上楼方式，则F(n) = F(n-1)+F(n-2)
#F(1) = 1 F(2) = 2,则可以推算出所有的F(n)
def get_f():
    f = [0]*100
    f[1] = 1
    f[2] = 2
    for i in range(3,100):
        f[i] = f[i-1]+f[i-2]
    return f

if __name__ == '__main__':
    f = get_f()
    print(f[4])
