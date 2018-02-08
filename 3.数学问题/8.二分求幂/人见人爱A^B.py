"""
@Time:2018/1/22 16:52
@Author:xuzhongyou
"""
#求A^B的最后三位数表示的整数
#输入：2 3
#输出：8
#法一直接上数据
def compute_mi():
    while(True):
        n_str = input()
        if n_str == '0 0':
            break
        n_result = n_str.split(" ")
        result = int(n_result[0]) ** int(n_result[1])
        result= list(str(result))[-3:]
        result = int("".join(result))
        print(result)
# compute_mi()

#法二
def compute_mi_2():
    while(True):
        n_str = input()
        if n_str == '0 0':
            break
        n_result = n_str.split(" ")
        #取n1 的前三位：
        n1 = int(str(n_result[0][-3:]))
        n2 = int(n_result[1])
        result = n1**n2
        result = list(str(result))[-3:]
        result = int("".join(result))
        print(result)
compute_mi_2()



