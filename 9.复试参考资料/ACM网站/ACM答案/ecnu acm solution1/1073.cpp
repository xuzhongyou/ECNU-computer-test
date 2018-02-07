#include <iostream>
#include <string>
using namespace std;

string a;

int main()
{
	int ans=0;
	int i;
	while (cin>>a) 
	{
		ans=a.length();
		i=0;
		while (a[i]=='0' && i<a.length()) {i++;ans--;}

		if (i==a.length()) cout<<1<<endl; else
			cout<<ans<<endl;
	}

	return 0;

}
