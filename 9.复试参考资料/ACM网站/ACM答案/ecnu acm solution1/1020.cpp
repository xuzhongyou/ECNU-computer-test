#include <iostream>
using namespace std;

int remind[20];
int my;
int enemy;
int total;
int N;
int Ans;
double ans;

int ChartoValue(char x)
{
	if (x=='A') return 11;
	if (x=='T' || x=='J' || x=='Q' || x=='K') return 10;
	return x-'0';
}

int ChartoIndex(char x)
{
	if (x=='A') return 1;
	if (x=='T') return 10;
	if (x=='J') return 10;
	if (x=='Q') return 10;
	if (x=='K') return 10;
	return x-'0';
}

void init()
{
	int i,j;
	char a,b,c;
	cin>>a>>b>>c;

	total=N*52-3;
	for (i=1;i<=9;++i) remind[i]=4*N;
	remind[10]=4*4*N;

	if (b=='A' && c=='A') 
	{
		my=12;
		remind[1]-=2;
	}
	else
	{
		my=ChartoValue(b)+ChartoValue(c);
		remind[ChartoIndex(b)]--;
		remind[ChartoIndex(c)]--;
	}

	enemy=ChartoValue(a);
	remind[ChartoIndex(a)]--;


	int Ans=0;
	for (i=1;i<=10;++i)
	{
		if (i!=1)
		{
			if (i+enemy>=my) Ans+=remind[i];
		}
		else
		{
			if (enemy==11)
			{
				if (i+enemy>=my) Ans+=remind[i];
			}
			else
				if (11+enemy>=my) Ans+=remind[i];
		}
	}
	Ans=total-Ans;
	ans=(double)Ans/(double)total;

	char temp='%';
	printf("%.3lf%c\n",ans*100,temp);

}


int main()
{
	int t=0;
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		if (t) printf("\n");
		t++;
		init();
	}
	return 0;
}

