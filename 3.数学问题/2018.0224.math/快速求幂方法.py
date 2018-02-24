"""
@Time:2018/2/24 11:55
@Author:xuzhongyou
"""
#A^n = A^(n/2) * A^(n/2)    当A为偶数时
#A^n = A^(n/2) * A^(n/2)*A  当A为基数时

def cal(n,m):
    if m ==0:
        return 1
    if m ==1:
        return n
    if m%2==0:
        return cal(n*n,int(m/2))
    else:
        return cal(n*n,int(m/2))*n

if __name__ == '__main__':
    result = cal(4,10000)
    print(result)