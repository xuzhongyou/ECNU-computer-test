"""
@Time:2018/1/24 10:21
@Author:xuzhongyou
"""
#描述：将M进制的数X转换为N进制的数输出
#输入：第一行包含两个整数：M 和 N 下面一行输入一个数X，X是M进制的数，现在要求你将M进制的数X转换为N进制的数输出
#输出X的N进制表示的数
##16 10
#F
#15
#一定是先转换为10进制再进行转换：


#令人悲伤的是完全可以用一个int('',flag)来解决问题
def trans_to_ten(n_str,flag):
    n =len(n_str)
    result = 0
    for i,item in enumerate(n_str):
        if 'A'<=item and item<='Z':
            item = ord(item)-55
        result += int(item)*(flag**(n-i-1))
    print(result)
    return result
# n_str = '2E'
# flag = 16
# result = trans_to_ten(n_str,flag)

#十进制转为其他进制：
n2 = 16
flag = 2
def tran_ten_to_other(n2,flag):
    result = []
    while(n2!=0):
        result.insert(0,n2%flag)
        n2 = int(n2/flag)
    print(result)
    return result

result = tran_ten_to_other(n2,flag)
#大于10的进行转化就可以了