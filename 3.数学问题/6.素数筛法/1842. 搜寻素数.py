"""
@Time:2018/3/9 11:00
@Author:xuzhongyou
"""
# 津津最近迷上了数学，她想知道任给的一个非负整数是否是素数，如果是就输出它本身，如果不是就输出离它最近的素数，若有两个离它最近的素数，那么输出较小那个。
# Input
# 第一行是一个 t (t<=100)，接下来的 t 行每行有一个非负整数 Ki(<=1,000,000)
#
# Output
# 输出有 t 行，对于每个 Ki，输出离 Ki 最近的素数（包括 Ki 本身）

def get_prime(n):
    d = [0]*n
    prime = [0]*n
    o_prime = []
    for i in range(2,n):
        if d[i]==1:
            prime[i]=prime[i-1]
            continue
        else:
            o_prime.append(i)
            prime[i]=i
            j = i+i
            while j<n:
                d[j] = 1
                j+=i
    return o_prime,prime

o_prime,prime = get_prime(1000000)
# print(o_prime)
# print(prime)
T = int(input())
for _ in range(T):
    ki =int(input())
    if ki ==1or ki==0:
        print(2)
        continue
    sushu =prime[ki]
    # print(sushu)
    if ki == sushu:
        print(ki)
    else:
        index = o_prime.index(sushu)
        b = o_prime[index+1]
        if ki-sushu<=abs(b-ki):
            print(sushu)
        else:
            print(b)
