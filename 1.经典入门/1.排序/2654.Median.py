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

# Solution in C
"""
#include <stdlib.h>
#include <stdio.h>

int N, A, X0, B, M;

int main()
{
    while(scanf("%d %d %d %d %d", &N, &A, &X0, &B, &M)!=EOF)
    {
       static int num[1000000];
       num[0] = X0;

       for(int i=1; i <N; i++)
       {
           num[i] = (num[i-1]*A + B) % M;
       }
        int HASH_SIZE;
        HASH_SIZE = M>X0?M:X0;

       int HASH[HASH_SIZE];

       for(int i=0; i<HASH_SIZE; i++)
            HASH[i] = 0;

        for (int i=0; i<N; i++)
            HASH[num[i]]++;

        int sum =0;
        for (int i=0; i<HASH_SIZE; i++)
        {

            sum += HASH[i];
            if(sum >= (N/2 + 1))
            {
                printf("%d\n", i);
                break;
            }
        }
    }
}
"""

def num_generate(N, A, X0, B, M):
    global num
    num = [X0]
    for i in range(1, N):
        num.append((num[i-1]*A + B) % M)

if __name__ == '__main__':
    while True:
        try:
            raw = (input().strip()).split(' ')
            N, A, X0, B, M = [int(num) for num in raw]
            num_generate(N, A, X0, B, M)
            HASH_Size =  max(M, X0) + 1
            HASH = [0] * (HASH_Size)
            for val in num:
                HASH[val] += 1
            sum = 0
            for i in range(HASH_Size):
                sum += HASH[i]
                if sum >= (N//2+1):
                    print(i)
                    break
        except EOFError:
            break
