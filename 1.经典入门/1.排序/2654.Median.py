"""
@Time:2018/2/8 21:28
@Author:qingliui
@Source:ECNU Online Judge
@Problem:2654
@Website:http://acm.ecnu.edu.cn/problem/2654/
"""
"""
This problem is easy. You are giving N numbers, and you are going to find the Median of them. Median is the number that separates the higher half the numbers given from the lower half.

Input
There are some cases. Process to the end of file

Each case give as N,A,X0,B,M separates by a single space, and you are going to generate the numbers as follow:

Xi=(Xi−1⋅A+B)modM

N would be less than 1 000 000. Both A,B,M,Xi would be a positive number less than 40000.

Output
Output the number which is the median of the sequence in one line. If N is even,you should output the second of the two medians.

Example
    Input
        5 73 5 97 43
    output
        25
"""
from statistics import median

def num_generate(N, A, X0, B, M):
    global num
    num = [X0]
    for i in range(1, N):
        num.append((num[i-1]*A + B) % M)

if __name__ == '__main__':
    raw = (input()).split(' ')
    raw_num = [int(num) for num in raw]
    num_generate(raw_num[0], raw_num[1], raw_num[2], raw_num[3], raw_num[4])
    print(median(num))
