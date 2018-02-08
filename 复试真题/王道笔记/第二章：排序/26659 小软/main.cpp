#include <iostream>
#include<set>
using namespace std;
set<int>s1;
int main() {
	int n;
	int j;
	while(cin>>n)
	{
    while(n--)
	  {
           cin>>j;
	   if(s1.count(j*2)==1&&s1.count(j)==0)
          s1.erase(j*2);
	  s1.insert(j);

	  }
	  cout<<s1.size()<<endl;
	  s1.clear();
	}
}
