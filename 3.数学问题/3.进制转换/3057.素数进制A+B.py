"""
@Time:2018/2/8 21:28
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3057
@Website:http://acm.ecnu.edu.cn/problem/3057/
"""
"""
进制也就是进位制，是人们规定的一种进位方法。对于任何一种进制 —X 进制，就表示某一位置上的数运算时是逢 X 进一位。十进制是逢十进一， 十六进制 是逢十六进一，二进制就是逢二进一，以此类推，x 进制就是逢 x 进一。

现定义一种新的进制表示方法 —“ 素数进制 ” 表示法。“ 素数进制 ” 不是单一进制，在 “ 素数进制 ” 中，每一位的进制都各不相同，具体定义如下：

将素数从小到大排列成一个素数列表：{2,3,5,7,11,13,17,19,23,29,31,…}。
在 “ 素数进制 ” 表示法中，从右边最低位开始，第 n 位的进制定义为素数列表中第 n 个素数，第 n 位可用的数码为 0~（第 n 个素数 -1），第 n 位对应的位权为素数列表中前 n-1 个素数的乘积，第 n 位上的数在运算时逢该素数进一位。即：右边最低位个位（第 1 位）的进制为 2 进制 ( 个位上可用的数码为 0，1)，对应的位权为 1；十位（第 2 位）的进制为 3 进制（十位上可用的数码为 0，1，2），对应的位权为 2；百位的进制为 5 进制（百位上可用的数码为 0，1，2，3，4），对应的位权为 2*3；千位的进制为 7 进制（千位上可用的数码为 0，1，2，3，4，5，6），对应的位权为 2*3*5，依次类推。 例如：十进制整数 2 的 “ 素数进制 ” 表示为 10（1*2+0*1），记为：“1，0”，十进制整数 6 的 “ 素数进制 ” 表示为 100（1*2*3+0*2+0*1），记为：“1，0，0”，十进制整数 38 的 “ 素数进制 ” 表示为 1110（1*2*3*5+1*2*3+1*2+0*1），记为：“1，1，1，0”。
“ 素数进制 ” 表示的两个整数 “4，2，0” 和 “1，2，0”，加法运算的结果为 “1，1，1，0”。

输入两个不超过 25 位的 “ 素数进制 ” 表示的非负整数 A 和 B，请编写程序计算并输出 A+B。

Input
第 1 行：一个整数 T（1≤T≤10）为问题数。

第 2 行： 第一个问题的数据， 两个不超过 25 位的 “ 素数进制 ” 表示的非负整数 A 和 B。非负整数 A 和 B 中的相邻两位数码用逗号分隔，A 和 B 之间有一个空格间隔。

第 3 ∽T+1 行：后面问题的数据 ，格式与第一个问题相同 。

具体格式见 SampleInput。

Output
对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）。

然后在一行中输出 “ 素数进制 ” 表示的 A+B 的值，相邻两位数码用逗号分隔。

具体格式见 SampleOut。

Examples
    input
        3
        1,0 2,1
        4,2,0 1,2,0
        1,0 10,6,4,2,1


    output
        case #0:
        1,0,1
        case #1:
        1,1,1,0
        case #2：
        1,0,0,0,0,1
        Hints
        第25位的位权是一个非常大的数，有35位。
"""

# 先找出从2开始的25个连续的质数
prime = []
limit = 100
index = [0]*limit
n_len = len(index)
for i in range(2, len(index)):
    if index[i] ==  1:
        continue
    else:
        prime.append(i)
        j = i + i
        while j < limit:
            index[j] = 1
            j += i

if __name__ == "__main__":
    T = int(input())
    for j in range(T):
        A, B = input().split(' ')
        A = list(map(int, A.split(',')))[::-1]
        B = list(map(int, B.split(',')))[::-1]
        len_A = len(A)
        len_B = len(B)
        #给较小的数填充0
        if len_A < len_B:
            for _ in range(len_B-len_A):
                A.append(0)
        elif len_A > len_B:
            for _ in range(len_A-len_B):
                B.append(0)
        #进行加法运算
        result = []
        QUOT = 0
        for i in range(max(len_A, len_B)):
            SUM = A[i] + B[i] + QUOT
            QUOT = SUM // prime[i]
            REMAIN = SUM % prime[i]
            result.append(REMAIN)
        if QUOT != 0:
            result.append(QUOT)
        print("case #{}:".format(j))
        print(*result[::-1], sep=',')
