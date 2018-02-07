#include <iostream>
#include <string>
using namespace std;

string s;
string word[200];
int words;
int F[300];

void deal()
{
	int i,j,k;
	fill_n(F,300,99999999);

	cin>>s;
	cin>>words;
	for (i=0;i<words;++i) cin>>word[i];

	F[0]=0;
	int len=s.length();

	/*
	cout<<s<<endl;
	cout<<words<<endl;
	for (i=0;i<words;++i) cout<<word[i]<<endl;
	*/

	for (i=1;i<=len;++i)
		for (k=0;k<words;++k)
		{
			if (i>=word[k].length())
			{
				if (word[k]==s.substr(i-word[k].length(),word[k].length()))
					if (F[i-word[k].length()]+1<F[i]) F[i]=F[i-word[k].length()]+1;
			}
		}

	cout<<F[len]<<endl;
}

int main()
{
	int T;
	int i;
	cin>>T;

	for (i=1;i<=T;++i)
	deal();

	//system("pause");
	return 0;
}
