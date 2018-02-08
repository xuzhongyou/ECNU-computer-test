"""
@Time:2018/1/11 15:36
@Author:xuzhongyou
"""
#写个算法，对2个小于1000000000的输入，求结果
#特殊乘法举例：123*45=1*4+1*5+2*4+2*5+3*4+3*5
#输入：两个小于1000000000的数
#输出可能有多组数据，对于每一组数据，输出input中的两个数按照题目要求的方法进行运算后得到结果
#123 45
#54
# a = 123
# result = []
# while(a!=0):
#     # result.append(a%10)
#     result.insert(0,a%10)
#     a = int(a/10)
# print(result)
str_1 = '123 45'
print(str_1)
str_list = str_1.split(" ")
num1 = str_list[0]
num2 = str_list[1]
result = 0
for i in list(num1):
    for j in list(num2):
        result += int(i)*int(j)
print(result)
