#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
string s[2000];

void deal()
{
	int i,j,k;

	for (i=0;i<N;++i) cin>>s[i];

	sort(s,s+N);
	int newlen=unique(s,s+N)-s;

	for (i=0;i<newlen;++i)
	{
		cout<<s[i]<<endl;
	}
}

int main()
{
	while (cin>>N) 
	{
		while (N<=0) continue;
		deal();
	}

	return 0;
}
