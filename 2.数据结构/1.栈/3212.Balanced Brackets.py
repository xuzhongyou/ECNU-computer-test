"""
@Time:2018/2/10 17:56
@Author:qingliu
@Source:ECNU Online Judge
@Problem:3212
@Website:http://acm.ecnu.edu.cn/problem/3212/
"""
"""
You have an empty sequence, and you will be given N queries. Each query is one of these three types:
A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or { ) occurs to the left of a closing bracket (i.e., ), ], or } ) of the exact same type. There are three types of matched pairs of brackets: [ ], { }, and ( ).

A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. For example, {[(])} is not balanced because the contents in between { and } are not balanced. The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

By this logic, we say a sequence of brackets is considered to be balanced if the following conditions are met:

It contains no unmatched brackets.
The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
Given strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, print YES on a new line; otherwise, print NO on a new line.

Input
The first line contains a single integer, n, denoting the number of strings.

Each line i of the n subsequent lines consists of a single string, s, denoting a sequence of brackets.

1≤n≤103
1≤lens≤103, where lens is the length of the sequence.
Each character in the sequence will be a bracket (i.e., {, }, (, ), [, and ]).
Output
For each string, print whether or not the string of brackets is balanced on a new line. If the brackets are balanced, print YES; otherwise, print NO
Examples
    input
        3
        {[()]}
        {[(])}
        {{[[(())]]}}

    output
        YES
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
            else:
                if len(stack) == 0 or stack.pop() != mapp[value]:
                    match = False
                    break
        if len(stack) != 0:
            match = False
        print({True:'YES', False:'NO'}[match])
