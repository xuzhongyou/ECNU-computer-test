"""
@Time:2018/1/8 19:02
@Author:xuzhongyou
"""
#读入一个只包含+-*/的非负整数计算表达式，计算该表达式的值
#输入：整数和运算符之间用一个空格分割。当一行只有零时输入结束
#输出：对每个测试用例输出一行，及该表达式的值精确到小数点后两位

##除了用堆栈的思想还有一个优先级的问题
#思路：
# 1.在表达式尾添加标记运算符。
# 2.从左到右依次遍历字符串，若遍历到运算符，则将其与运算符栈的栈顶元素进行比较，若栈顶小于该运算符，或运算符栈为空时，将该运算符压入该栈
# 3.若栈顶运算符大于该运算符，则弹出栈顶运算符，再从数据栈中一次弹出两个栈顶元素，完成该运算再压入数据栈
# 4.当运算符栈只剩下认为添加的标记运算符，则表达式运算结束（用for可以规避这个问题）。

str_ = '4 + 2 * 5 - 7 / 11'
# str_1 = '1 + 2'
str_list = str_.split(" ")
print(str_list)
str_list.append('$')
op_dict = {}
op_dict['+'] = 1
op_dict['-'] = 1
op_dict['*'] = 2
op_dict['/'] = 2
op_dict['$'] = 0
op_stack = []
num_stack = []
#将字符串变为
def calculate(num1,num2,item):
    if item == '+':
        # print(num1,item,num2)
        return num1+num2
    elif item == '-':
        # print(num1,item,num2)
        return num1-num2
    elif item == '*':
        # print(num1,item,num2)
        return num1*num2
    else:
        # print(num1,item,num2)
        return num1/num2


for i,item in enumerate(str_list):
    #当遍历到数字时，直接压栈
    if item > '0' and item<'9':
        num_stack.append(int(item))
        # print(num_stack)
    ##当前运算符栈顶元素低于读取运算符
    else:
        if len(op_stack)==0 or op_dict[op_stack[-1]] < op_dict[item]:
            op_stack.append(item)
            # print(op_stack)
        # 当前运算符栈顶元素优先级高于读取运算符优先级
        else:
            while (op_dict[op_stack[-1]] >= op_dict[item]):
                    num2 = num_stack.pop()
                    num1 = num_stack.pop()
                    temp = calculate(num1,num2,op_stack[-1])
                    num_stack.append(temp)
                    #并弹出该运算符
                    op_stack.pop()
                    #当运算符栈为空时，跳出循环
                    if len(op_stack)==0:
                        op_stack.append(item)
                        break

print(round(num_stack[0],2))



