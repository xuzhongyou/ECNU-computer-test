"""
@Time:2018/1/4 11:51
@Author:xuzhongyou
"""
while(1):
    num = int(input())
    inputs = input().split(" ")
    x = input()
    print(inputs)
    flag = 0
    for i,j in enumerate(inputs):
        if j == x:
            flag = 1
    if flag == 0:
        print(-1)
