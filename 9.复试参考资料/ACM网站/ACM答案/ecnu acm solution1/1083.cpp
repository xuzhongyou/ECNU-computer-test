#include <iostream>
using namespace std;

int T;
char s[200];

int now;
int state[10][256];

void init()
{
	int i,j,k;
	char c;

	for (i=1;i<=6;++i) for (j=0;j<=255;++j) state[i][j]=6;

	for (c='0';c<='9';++c) state[1][c]=1;
	for (c='0';c<='9';++c) state[2][c]=2;
	for (c='0';c<='9';++c) state[4][c]=5;
	for (c='0';c<='9';++c) state[5][c]=5;

	state[1]['.']=2;
	state[1]['E']=3;
	state[2]['E']=3;
	state[3]['-']=4;
	for (c='0';c<='9';++c) state[3][c]=5;

}

void deal()
{
	cin.getline(s,100);

	int i,j,k;
	bool ok;

	while (T--)
	{
		cin.getline(s,150,'\n');
		i=0;
		j=strlen(s)-1;
		while (s[i]==' ') i++;
		while (s[j]==' ') j--;

		if (s[i]=='.' || s[i]=='E') {cout<<"NO"<<endl; continue;}
		ok=true;
		for (k=i;k<j;++k) if (s[k]=='.' && s[k+1]=='E') {cout<<"NO"<<endl; ok=false;break;}
		if (!ok) continue;

		now=1;
		for (k=i;k<=j;++k) now=state[now][s[k]];

		if (now==3 || now==4 || now==6) cout<<"NO"<<endl; else cout<<"YES"<<endl;
	}
}


int main()
{
	init();
	
	while (cin>>T) deal();
	
	return 0;
}
