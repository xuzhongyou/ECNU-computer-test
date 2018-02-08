#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

int main()
{
    string a=" 123456789";
    string b="79";
    //if(a<=b)//输出
      //  printf("%s\b",b.c_str());
    //else printf("%s\b",a.c_str());

    //遍历
    //for(int i=0;i<a.size();i++)
      //  printf("%c",a[i]);

    //删除a[7]（包括a[7]）后的1个数
    //a.erase(7,1);
    //puts(a.c_str());

    //查找和插入
    int startPos=0;
    int pos=a.find(b,startPos);
    printf("%d\n",pos);

    a.insert(2,b);
    printf("%s",a.c_str());
    return 0;
}
