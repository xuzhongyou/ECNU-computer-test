"""
@Time:2018/2/24 9:15
@Author:xuzhongyou
"""
# Input
# The first line contains an integer m, the number of test cases. After that follow m lines. Every line represents one testcase, which only contains the integer number n. The value of n will be at least 1 and won’t be bigger than 2.000.000.000.
#
# Output
# For each testcase, print a line containing the number of trailing zeros. Do not print whitespace before or after the number.
#
# Examples
# input
# 4
# 1
# 23
# 42
# 2000000000
# output
# 0
# 4
# 9
# 499999997

def process(n):
    res = 0
    while(n):
        res+= int(n/5)
        n/=5
    print(res)

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        n = int(input())
        process(n)
