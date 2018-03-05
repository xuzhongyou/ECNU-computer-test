# 3023. 字符组合
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 输入一个由字母组成的字符串 S(1≤长度≤16)，按字典序输出由 S 中不同字符组成的所有字符组合（每个组合中的字符也按字典序排列）。
#
# 例如：“cbaabc” 中的不同字符是 ‘a’、‘b’、‘c’ 共 3 个，则 1 个字符组成的组合是 “a”、“b”、“c”3 种，2 个字符组成的组合是 “ab”、“bc”、“ac”3 种，3 个字符组成的组合是 “abc”1 种。注意：“ab” 和 “ba” 由相同字符组合而成，因此可认为是同一个组合。那么这个例子共有 7 种组合，按序分别为 “a”、“ab”、“abc”、“ac”、“b”、“bc”、“c”。
#
# Input
# 第 1 行：一个整数 T (1≤T≤10) 为问题数。
#
# 接下来共 T 行，每行输入一个长度不超过 16 的字符串 S。
#
# Output
# 对于每个问题，输出一行问题的编号（0 开始编号，格式：case #0: 等）。
#
# 然后对应每个问题按规定顺序在一行中输出每一个组合
from itertools import combinations, permutations

T = int(input())
for _ in range(T):
    data = list(input())
    data = set(data)
    data = sorted(data)
    lens = len(data)
    result = []
    for i in range(1,lens+1):
        result.extend(combinations(data,i))
    result = sorted(result)
    print('case #%d:'%(_))
    for item in result:
        print(''.join(list(item)))