"""
@Time:2018/2/8 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3342
@Website:http://acm.ecnu.edu.cn/problem/3342/
"""
"""
我想了一个数，要让你猜一猜。

这个数在 −109 到 109 之间。
这个数是整数。
你每猜一个数，我都会回答你大了 (big) 或者小了 (small) 或者正好 (equal)。
你猜的数也必须是 −109 和 109 之间的整数，不然我可能不知道你在说什么……
你猜的次数不能超过 32 次。

Examples
    input
        2
        -3
        -1
        0
    output
        big
        small
        small
        equal
Note
这是一个交互题。你要先猜，输出到标准输出流 (stdout)。对于我的回答，你要从标准输入流中读入 (stdin)。

你需要清空缓存，在 C 中使用 fflush，C++ 中使用 flush 或 endl，在 Python 中使用 sys.stdout.flush()。

你可能会遇到 Idleness Limit Exceeded，这种错误表示你的程序「太闲了」。你可能在等待输入，或者只是超时了（而我并不知道，以为你闲着）。
"""
import sys
reply = ""
l, r = int(-1e9), int(1e9)
while(reply != "equal"):
    m = (l + r) // 2
    print(m)
    sys.stdout.flush()
    reply = input().strip()
    if reply == "big":
        r = m - 1
    elif reply == 'small':
        l = m + 1
    else:
        break
