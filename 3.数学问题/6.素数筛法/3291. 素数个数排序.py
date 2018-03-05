"""
@Time:2018/3/5 15:41
@Author:xuzhongyou
"""
# 3291. 素数个数排序
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 设p(x, y)表示x到y之间的素数个数(包括x和y本身)。给你n组x，y，把它们按p(x, y)从小到大排序，若p(x, y)相等，则按x从小到大排序，若p(x, y)和x都相等，则按y从小到大排序。
#
# Input
# 第 1 行为一个整数T（1≤T≤15）为问题数。
#
# 以后T个问题，每个问题第一行为一个整数n（0<n<10000），之后n行每行两个用一个空格隔开的正整数x, y(x<y<=10000)。
#
# Output
# 对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）
# 然后输出n行，为排序之后的数据
#构造素数

#需要注意的地方是保存素数的总数，千万注意sorted不能放在循环里面
import operator
def get_prime(n):
    d = [0]*n
    prime = []
    sum = [0]*n
    total = 0
    for i in range(2,n):

        if d[i]==1:
            sum[i] = total
            continue
        else:
            prime.append(i)
            total+=1
            j = i+i
            while j<n:
                d[j] = 1
                j+=i
        sum[i]=total
    return prime,sum
prime,sum = get_prime(10000)


T = int(input())
for _ in range(T):
    n = int(input())
    a = []
    for i in range(n):
        inputs = list(map(int,input().split()))
        a.append(inputs)
        a[i].append(sum[a[i][1]]-sum[a[i][0]-1])
    a.sort(key=operator.itemgetter(2,0,1))
    print('case #%d:'%(_))
    for i in range(n):
        print(a[i][0],a[i][1])
