"""
@Time:2018/2/22 10:45
@Author:xuzhongyou
"""
# 3256. 拼音魔法
# Time limit per test: 2.0 seconds
#
# Memory limit: 256 megabytes
#
# 魔法学校小学一年级有一种题。就是给一个字的拼音，给一个声调，让你正确地注音。但魔法老师给了巨量的题，你不用魔法根本不可能做完。所以现在要让你发明一种魔法完成这个任务。
#
# 问题已经讲完了，下面开始教授汉语。（会汉语或者自认为会汉语的可以自动跳过）
#
# 汉语中一个字的拼音由声母和韵母两部分组成，在极少数情况下也会没有声母，但一定有韵母。
#
# 一般认为，声母有 b, p, m, f, d, t, l, n, g, k, h, j, q, x, z, c, s, zh, ch, sh, r, y, w；韵母有：a, e, o, i, u, ü, ai, ei, ui, ao, ou, iu, ie, üe, er, an, en, in, un, ün, ang, eng, ing, ong。
#
# 不是所有的字母都能组合的，组合的时候有时会发生一些神奇的事情，例如 üe 变成了 ue。但是标调规则有如下口诀：
#
# 有 a 先找 a，没 a 找 o e，i u 并排标在后，这样标调不会错。
#
# 只有下面列出的元素可能会被标调。请按照下表输出（尤其注意 a 不要输出成 ɑ 了）：
#
# 第一声：ā ē ī ō ū ǖ。
# 第二声：á é í ó ú ǘ。
# 第三声：ǎ ě ǐ ǒ ǔ ǚ。
# 第四声：à è ì ò ù ǜ。
# 轻声：à è ì ò ù ǜ。
# 辅助材料：由教育部公布的拼音方案。如果有描述不一致的地方，请以本题描述为准。
#
# Input
# 第一行一个整数 T (1≤T≤105)。
#
# 下面 T 行，每行一个拼音：拼音声调在各个拼音之后，用数字 [1-4] 进行表示。例如 zhong1 guo2。没有数字的说明是轻声，不用标调。
#
# 按照国际惯例，输入文件全部由 ASCII 编码组成。ü 用 v 来代替。但在输出中，应仍然用 ü 来表示。
#
# Output
# 对于每一组数据，输出 Case x: y。其中 x 是从 1 开始的测试数据编号，y 是一个拼音标调后的答案。
#
# 注意：对于非 ASCII 字符的输出，请使用 UTF-8 编码。
#
# Examples
# input
# 5
# zhong1
# guo2
# me
# que1
# nv3
# output
# Case 1: zhōng
# Case 2: guó
# Case 3: me
# Case 4: quē
# Case 5: nǚ

table = [['ā','ō', 'ē','iū','uī', 'ī',  'ū', 'ǖ'],
         ['á', 'ó','é','iú','uí','í',  'ú', 'ǘ'],
         ['ǎ', 'ǒ','ě', 'iǔ','uǐ','ǐ',  'ǔ', 'ǚ'],
         ['à', 'ò','è', 'iù','uì','ì',  'ù', 'ǜ']]
six_list = ['a','o', 'e', 'iu','ui','i', 'u', 'v']

if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        inputs = input()
        try:
            n = int(inputs[-1])
            for index,item in enumerate(six_list):
                if item in inputs:
                    inputs = inputs.replace(item,table[n-1][index])
                    break
            print("Case %d:" % (i+1), ''.join(inputs[:-1]))
        except Exception:
            print("Case %d:"%(i+1),''.join(inputs))