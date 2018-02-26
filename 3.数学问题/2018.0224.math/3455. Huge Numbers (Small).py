"""
@Time:2018/2/24 9:42
@Author:xuzhongyou
"""
# 3455. Huge Numbers (Small)
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# Professor Shekhu has another problem for Akki today. He has given him three positive integers A, N and P and wants him to calculate the remainder when AN! is divided by P. As usual, N! denotes the product of the first N positive integers.
#
# Input
# The first line of the input gives the number of test cases, T. T lines follow. Each line contains three integers A, N and P, as described above.
#
# Limits: 1≤T≤100.
# Small dataset: 1≤A≤10,1≤N≤10,1≤P≤10.
# Large dataset: 1≤A≤105,1≤N≤105,1≤P≤105.
# Output
# For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is the answer.
#
# Examples
# input
# 2
# 2 1 2
# 3 3 2
# output
# Case #1: 0
# Case #2: 1
# Note
# In Sample Case #1, the answer is the remainder when 21!=2 is divided by 2, which is 0.
#
# In Sample Case #2, the answer is the remainder when 33!=36=729 is divided by 2, which is 1.

#这种网上的解法，可以解决求阶乘问题
def g(A, N, P):
    A = A % P
    ans = A
    for i in range(1, N+1):
        ans **= i
        ans = ans % P
    return ans

T = int(input())
for i in range(1, T+1):
    A, N, P = map(int, input().split())
    print("Case #%d: %d" % (i, g(A, N, P)))

# def process(n,m,k):
#     temp = 1
#     for i in range(2,m+1):
#         temp*=i
#     result = n**temp
#     res= 1
#     for i in range(result):
#         res = (res*n)%k
#     return res
#
# if __name__ == '__main__':
#     T = int(input())
#     for i in range(T):
#         inputs = [int(item) for item in input().split(' ')]
#         result = process(inputs[0],inputs[1],inputs[2])
#         print('Case #%d:'%(i+1),result)




