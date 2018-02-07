#include <iostream>
using namespace std;

const int w=3;
const int MaxSize=(1<<3)-1;

long long int F[40][10];
int state[10];
int newstate[10];



void search(int dep,int now,int situ)
{
	int i,j,k;
	if (dep>w)
	{
		k=0;
		for (i=w;i>=1;--i) if (newstate[i]) k=(k<<1)+1; else k=k<<1;
		F[now+1][k]+=F[now][situ];
		return;
	}

	if (state[dep]==0)
	{
		newstate[dep]=1;
		search(dep+1,now,situ);
	}
	else
	{
		if (dep+1<=w && state[dep+1]==1)
		{
			newstate[dep]=1;
			newstate[dep+1]=1;
			search(dep+2,now,situ);
		}

		{
		newstate[dep]=0;
		newstate[dep+1]=0;
		search(dep+1,now,situ);
		}
	}

	return;
}

void init()
{
	int i,j,k,l;
	memset(F,0,sizeof(F));
	F[0][MaxSize]=1;

	for (i=0;i<=31;++i)
	{
		for (j=0;j<=MaxSize;++j)
			if (F[i][j]!=0)
			{
				l=j;
				for (k=1;k<=w;++k) 
				{
					state[k]=l % 2;
					l/=2;
				}

				search(1,i,j);
			}
	}

}
			
int main()
{
	init();


	int i;
	while (cin>>i)
	{
		if (i>=0)
		{
			if (i==0) cout<<1<<endl; else
			cout<<F[i][MaxSize]<<endl;
		}
	}

	return 0;
}

