"""
@Time:2018/1/17 18:20
@Author:xuzhongyou
"""
#如何去找素数
#让一个数不是素数时，必存在一个素数是其因数，这个命题是显然成立的
#输入一个整数n,
# 要求输出所有从1到这个整数之间（不包括1和这个整数）个位为1的素数，如果没有则输出-1

#首先拿到一个质数list

def get_zhishu(n):
    model = [0]*n
    result = []
    n_len = len(model)
    for index,i in enumerate(model):
        if index == 0 or index ==1 or i ==  1:
            continue
        else:
            result.append(index)
            count= 2
            j = index*count
            while(j<n_len):
                model[j] = 1
                count +=1
                j = index*count
    return result

#遍历找到个位为1的数
results = get_zhishu(120)
rst = []
for result in results:
    if result%10 ==1 :
        rst.append(str(result))
print(" ".join(rst))





