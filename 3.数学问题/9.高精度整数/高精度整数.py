"""
@Time:2018/1/22 18:10
@Author:xuzhongyou
"""
#实现一个加法器，使其能够输出a+b的值
#输入：输入包括两个数a和b,其中a和b的位数不会超过1000位
#输出，可能多组数据，对于每组数据，输出a+b的值
#2 6
#100000000 10000000000

#其实可以依次取四位，然后去零
def add_two_numbers():
    # n_str = input()
    # n_results = n_str.split(" ")
    # n1 = n_results[0]
    # n2 = n_results[1]
    # n1 =     '100000000'
    # n2 = '1000000000000'
    n1 =   '12312'
    n2 = '3423423'
    num_n1 = len(n1)
    num_n2 = len(n2)
    if num_n1>num_n2:
        max_num = n1
        min_num = n2
    else:
        max_num = n2
        min_num = n1
    #下面三步并不一定需要
    result = []
    cf = 0
    while(len(min_num)>0):
        temp = str(int(min_num[-4:]) + int(max_num[-4:])+int(cf))
        if len(temp)==5:
            cf = temp[0]
            temp = temp[1:]
        else:
            cf = 0
            if len(temp)<4:
                temp_n = (4- len(temp))*'0'
                temp = temp_n+temp
        result.append(temp)
        min_num = min_num[:-4]
        max_num = max_num[:-4]
    print("加上最大之前",result)
    result.append(max_num)
    print("加上最大之后",result)
    return result

result = add_two_numbers()
print(result)
result.reverse()
print("result is ",result)
#注意下面这行不能这么写
# print("".join(result.reverse()))
print("".join(result))