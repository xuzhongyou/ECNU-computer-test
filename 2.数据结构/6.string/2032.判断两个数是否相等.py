"""
@Time:2018/2/11 9:19
@Author:xuzhongyou
"""
# 2032. 判断两个数是否相等
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 给你 2 个数 a 和 b，判断 2 个数是否相等。多考虑些特殊情况。
#
# 多 Case ， 处理到文件结束。
#
# Input
# 每行输入 2 个数，有小数，位数大于 double 的有效位数，需要大数。
#
# Output
# 如果相等输出 It’s xiao qiang, 否则输出 It isn’t xiao qiang
#
# Examples
# input
# 1 2
# 1 1
# output
# It isn't xiao qiang
# It's xiao qiang
def num(s):
    try:
        return str(int(s))
    except ValueError:
        return s.rstrip('0').rstrip('.')

if __name__=='__main__':
    while True:
        try:
            a, b = map(num, input().split(' '))
            if a == b:
                print("It's xiao qiang")
            else:
                print("It isn't xiao qiang")
        except EOFError:
            break
