"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3210
@Website:http://acm.ecnu.edu.cn/problem/3210/
"""
"""
sunny 非常喜欢吃零食，有时候会一下子买好多零食，所以有些会吃不完，本着节约的原则，他把这些吃不完的零食用特殊的罐头装起来，等以后再吃。罐头有三种，分别用{},[],() 表示，当罐头里面装了零食之后，就变成了{CHOCOLATE}, 或者 [POTATOCHIPS], 或者 (COKE), 这种罐头的材质很特殊，对食品不会产生污染，所以可以把食品用罐头装起来之后，放到另一个装有食品的罐头里，例如{CHOCOLATEPOTATOCHIPS}, 其中 CHOCOLATE 被放在{}罐头中，POTATOCHIPS 被放在 [] 罐头中，那么 COKE 当然被放在了 () 罐头中。但是在使用这种罐头的时候必须小心，罐头的盖子必须要盖起来，比如一个罐头的左盖子必须对应该罐头的右盖头，也就是不能出现这种{CHOCOLATE[POTATO(COKE)}，食品罐头的盖子没有盖全，会导致里面的食品变质，sunny 就不要吃了。

一天，sunny 从柜子里翻出好多罐子，这都是他以前保存的零食，他怀疑有些罐头由于当初没有盖好盖子，里面的零食已经变质，不能吃了。但是由于数量太多，手工检查起来太麻烦，于是他想请你帮他写个程序，来检测这些罐头里面的食品是否能吃。

特别需要注意的地方：

(1) 左右两个盖子不能互换，比如)COKE(是不允许的 ,[(APPLE)COKE(ORANGE)] 是允许的 ,COKE 其实是放在 [] 中。

(2) 必须配套使用，用{的左盖子，右盖子一定要是}，其他两种盖子也是一样。

(3) 罐头里不放食品是允许的。

(4) 用正确的方法储存起来的食品，将永远不会变质。

(5) 只要用了左盖子，就一定要用右盖子；用了右盖子，也一定要用左盖子，否则也不能正常保存食品。
Input
第一行有一个整数 k, 表示有 k 组罐头 (0<k<=100)。

第二行到第 k+1 行，每行一个字符串，每个字符串表示一组待检查的罐头，字符串由 ‘A’…’Z’, 以及 ‘{‘,’}’,’[‘,’]’,’(‘,’)’ 组成。题目保证，一组罐头中，至少会有一种零食，一个罐头里只会放一种零食或者不放。(字符串长度不大于 1000)

Output
对应每组罐头，输出一行，假如食品还能吃，就输出 “YES”, 否则输出 “NO”.
Examples
    input
        5
        {CHOCOLATE[POTATO(COKE)}
        {CHOCOLATE[]()}
        {CHOCOLATE{CHOCOLATE[]()}
        {CHOCOLATE[()}
        {CHOCOLATE[]()COKE}

    output
        NO
        YES
        NO
        NO
        YES
"""
mapp = {')':'(', ']':'[', '}':'{'}

if __name__ == "__main__":
    T = int(input())
    stack = []
    stack_max = []
    index = 0
    for _ in range(T):
        str = list(input())
        stack = []
        match = True
        for value in str:
            if value in ['(', '[', '{']:
                stack.append(value)

                all
            elif value in [')', ']', '}']:
                if len(stack) == 0 or stack.pop() != mapp[value]:
                    match = False
                    break
        if len(stack) != 0:
            match = False
        print({True:'YES', False:'NO'}[match])
