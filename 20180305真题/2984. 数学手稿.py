"""
@Time:2018/3/6 16:02
@Author:xuzhongyou
"""
#从题目来确认
m,w,c = 3,2,1
#表示人数和花费
T = int(input())
for _ in range(T):
    n,k=map(int,input().split())
    data = []
    for i in range(0,n+1):
        for j in range(0,n-i+1):
            cost = 3*i+j*2+(n-i-j)
            if cost==k:
                data.append((i,j,n-i-j))
    print('case #%d:' % (_))
    if len(data)==0:
        print(-1)
    else:
        data.sort(key=lambda k:[k[0],k[1],k[2]])
        for datum in data:
            print(*datum)