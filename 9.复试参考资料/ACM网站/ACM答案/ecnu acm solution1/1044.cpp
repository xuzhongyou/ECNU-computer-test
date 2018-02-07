#include <iostream>
using namespace std;

int bians[100000];
int bian[100000][100];
int path[100005];
int depth[100005];
bool mark[100005];
int N;
int start,stop;

void deal()
{
	int open=1,closed=0;
	int i,j,k;
	memset(mark,false,sizeof(mark));
	path[1]=start;
	depth[start]=0;
	mark[start]=true;

	while (closed<open && !mark[stop])
	{
		closed++;
		i=path[closed];
		for (j=0;j<bians[i];++j) 
		{
			k=bian[i][j];
			if (!mark[k])
			{
				path[++open]=k;
				depth[k]=depth[i]+1;
				mark[k]=true;
			}
		}
	}
	cout<<start<<" "<<stop<<" "<<depth[stop]-1<<endl;
}

void init()
{
	int i;
	int ns;
	int j,k;

	for (i=0;i<N;++i)
	{
		scanf("%d%d",&i,&ns);
		bians[i]=ns;
		for (j=0;j<ns;++j) { scanf("%d",&k); bian[i][j]=k; }
	}
	scanf("%d%d",&start,&stop);
	deal();
}

int main()
{
	while (scanf("%d",&N)!=EOF) init();

	return 0;
}

