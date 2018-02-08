"""
@Time:2018/1/24 9:06
@Author:xuzhongyou
"""
#描述：输入一个正整数N,输出N的阶乘
#输入：正整数N 0<=N<=1000
#输出：N的阶乘

n1 = 123456789
n2 = 2
def demo(n1,n2):
    result = []
    output = []
    cf = 0
    while(n1!=0):
    #将数字4位切分,比按字符串切分更加方便
        result.append(n1%10000)
        n1 = int(n1/10000)
    for rst in result:
        temp = rst*n2+cf
        output.append(str(temp%10000))
        cf = int(temp/10000)
    if cf>0:
        output.append(str(cf))
    output.reverse()
    print("".join(output))
demo(n1,n2)