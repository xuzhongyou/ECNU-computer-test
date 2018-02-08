"""
@Time:2018/1/19 17:18
@Author:xuzhongyou
"""
#题目：求正整数N的质因数的个数
#输入：输入一个正整数
#输出：输出N质因数的个数
#注意这边的质因数的个数：相同的质因数需要重复计算。如120 = 2*2*2*3*5

result = []
def get_zhishu(n):
    model = [0]*n
    for index,item in enumerate(model):
        if index ==0 or index ==1 or item ==1:
            continue
        else:
            result.append(index)
            count = 2
            temp = index*count
            while(temp<n):
                model[temp] = 1
                count += 1
                temp = index * count

def get_number_zhishu(n):
    zhishu = []
    for rst in result:#这个逻辑居然想了一分钟，尴尬
        while(n%rst)== 0:
            zhishu.append(rst)
            n = n/rst
    return zhishu

n = 120
get_zhishu(n)
rst = get_number_zhishu(n)
print(rst)

