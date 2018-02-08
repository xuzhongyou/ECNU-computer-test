"""
@Time:2018/1/11 16:38
@Author:xuzhongyou
"""
#输入：15 Aab3 7
#输出：210306

#养成写注释的习惯
str1= 'Aab3'
n = 15
#不想用int直接转的话
def tran_n_10(str_,n):
    rst = 0
    result = []
    for i in list(str_):
        if i >='0' and i<='9':
            result.insert(0,int(i))
        elif i >='a' and i<='z' :
            result.insert(0,ord(i)-ord('a')+10)
        elif i>='A' and i<='Z' :
            result.insert(0,ord(i)-ord('A')+10)
    for index,item in enumerate(result):
        rst += n**index*item
    return  rst

rst = tran_n_10(str1,15)

def tran_10_n(num,n):
    result = []
    while(num!=0):
        result.insert(0,str(num%n))
        num = int(num / n)
    for i,rst in enumerate(result):
        if rst>'9':
            result[i] = chr(rst+87)
    return result
print("".join(tran_10_n(rst,7)))