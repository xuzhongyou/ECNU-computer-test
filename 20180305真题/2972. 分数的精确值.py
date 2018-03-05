# 2972. 分数的精确值
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 计算机内部表示的浮点数只有有限的精确位数。现在要找一种方法，使一个分数的精确值能够被表示为十进制小数，如果是一个无限循环小数，则指出它从哪一位到哪一位是循环节。
#
# Input
# 第 1 行：整数 $T$ ($1 \le T \le 10$) 为问题数
#
# 第 2 ∽ T+1 行：每行为每一个问题中的用一个空格分隔的分子 n 和分母 m （1≤n
#
# Output
# 对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等），然后在一行中输出精确值小数（无循环）或一个小数直到第一个循环节结束。如果有循环，则在下一行中以两个整数表示从哪一位到哪一位是循环节，中间用一个 “-” 号分隔。

T =int(input())
for _ in range(T):
    n1,n2 =map(int,input().split())
    print('case #%d:'%(_))
    res = ''
    r_list = []
    r = n1%n2
    #能够整除的
    if r ==0:
        print(int(n1/n2))
    else:
        # 解决整数部分
        res = res+str(n1//n2)+'.'
        while r not in r_list:
            r_list.append(r)
            n1 = (r)*10
            r = n1%n2
            res = res+str(n1//n2)
        # print(res[-1],r_list)
        s = 0
        while res[-1]=='0':
            res = res[:-1]
        print(res)
        if r != 0:
            for index,item in enumerate(r_list):
                if r == item:
                    s = index
                    break
            print(s+1,end='')
            print('-',end='')
            print(len(r_list))
