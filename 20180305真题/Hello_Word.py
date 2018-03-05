"""
@Time:2018/3/5 11:53
@Author:xuzhongyou
"""
import re
T = int(input())
chara = ['\.','\?','\!']
p = re.compile('|'.join(chara))
def len_1(x):
    if x!='':
        return len(x)+1
for _ in range(T):
    n =int(input())
    inputs = p.split(input())
    if inputs[-1] == '':
        inputs = inputs[:-1]
    data = list(map(len_1,inputs))
    lens = len(data)
    count_= 0
    result = 0
    if lens==1:
        if data[0]>n:
            print('Impossible')
        else:
            print('1')
    else:
        for i in range(lens):
            if data[i]>n:
                print('Impossible')
                break
            count_+=data[i]
            if count_>n:
                if i == lens-1:
                    result+=2
                else:
                    result += 1
                count_ = data[i]
            else:
                if i==lens-1:
                    result+=1
        print(result)

    # 40
    # Hello.Welcome to East China Normal University!What is your name?


# character = [';', '；']
# p = re.compile('|'.join(character))
