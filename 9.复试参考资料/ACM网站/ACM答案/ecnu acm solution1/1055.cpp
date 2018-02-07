#include <iostream>
using namespace std;

int a,b;

int gcd(int x,int y)
{
	if (x % y==0) return y;
	else return gcd(y,x%y);
}

int main()
{
	while (cin>>a>>b) cout<<gcd(a,b)<<endl;

	return 0;
}
