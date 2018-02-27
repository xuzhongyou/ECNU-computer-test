"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3218
@Website:http://acm.ecnu.edu.cn/problem/3218/
"""
"""
有一个单调递增的十进制数的数列，数列项组成规则为：每个数的每位都由相同个数的 0-9 数码组成，但排列不同。一个数开头的 0 省略。

例如 : 两个 1、一个 5 和一个 0 组成的数列为 115, 151, 511,1015, 1051……

现在给定数列中的某个项 N，请计算并输出下一项。

Input
第 1 行：整数 T (1≤T≤10) 为问题数。

第 2 行：一个十进制整数 N，1≤N≤1020

后面问题的数据格式与第一个问题相同。

Output
对于每个问题，输出一行问题的编号（0 开始编号，格式 case #0: 等），然后在一行中输出下一项的值。

Examples:
    input:
        3
        115
        1051
        6233
    output:
        case #0:
        151
        case #1:
        1105
        case #2:
        6323

"""

class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        partition = -1
        for i in range(len(nums)-2, -1, -1):  # 从倒数第二个数开始遍历到第0个数
            if nums[i] < nums[i+1]:  # 从后向前找到第一个升序对，并让partition等于升序对中较小的
                partition = i
                break
        if partition == -1:
            # 没找到升序对 e.g. 54321 --> 12345
            nums.append('0')
        else:
            for i in range(len(nums)-1, partition, -1):
                # 交换partition和升序对后面比partition更大的数 如14532 -> 15432
                if nums[i] > nums[partition]:
                    nums[i], nums[partition] = nums[partition], nums[i]
                    break
        # 将partition后面的数字逆向排序。由于找到的partition是从后向前的第一个升序对，所以可以放心partition后面一定都是降序的
        # 所以逆向排序后可以得到一个新的刚好大于之前permutation的next permutation
        # 比如此时14532已经变为15432，则再将5（此时partition已经是5了）后面的432逆序排列得到234.则最终的数字变为15234
            nums[partition+1:len(nums)] = nums[partition+1:len(nums)][::-1]  # 切片

if __name__ == "__main__":
    T = int(input())
    for i in range(T):
        N = list(input())
        solute = Solution()
        solute.nextPermutation(N)
        print("case #{0}:".format(i))
        print(*N, sep='')
