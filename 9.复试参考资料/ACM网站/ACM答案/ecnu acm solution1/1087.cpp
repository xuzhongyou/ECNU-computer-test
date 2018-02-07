#include <iostream>
using namespace std;

int R,C;

struct Point
{
	int x,y;
	int len;

	bool InRange()
	{
		if (x<1) return false;
		if (x>R) return false;
		if (y<1) return false;
		if (y>C) return false;
		return true;
	}
};

bool map[1005][1005];
bool visit[1005][1005];
int Dir[4][2]={ {1,0},{-1,0},{0,1},{0,-1} };
Point path[1000005];
Point start;
Point Rstart;
int ans;

void deal()
{
	int i,j,k;

	for (i=1;i<=R;++i) for (j=1;j<=C;++j) visit[i][j]=false;

	int open,closed;
	bool found;
	found=false;
	for (i=1;i<=R;++i) 
	{
		for (j=1;j<=C;++j) 
		{
			if (map[i][j])
			{
				start.x=i;
				start.y=j;
				found=true;
			}
			if (found) break;
		}
		if (found) break;
	}

	if (!found)
	{
		cout<<0<<endl;
		return;
	}

	path[0].x=start.x;
	path[0].y=start.y;
	path[0].len=0;
	visit[path[0].x][path[0].y]=true;
	
	Point temp;
	for (closed=0,open=1;closed<open;++closed)
	{
		for (k=0;k<4;++k)
		{
			temp.len=path[closed].len+1;
			temp.x=path[closed].x+Dir[k][0];
			temp.y=path[closed].y+Dir[k][1];
			if (temp.InRange() && !visit[temp.x][temp.y] && map[temp.x][temp.y]) 
			{
				path[open++]=temp;
				visit[temp.x][temp.y]=true;
			}
		}
	}
	
	Rstart.x=path[open-1].x;
	Rstart.y=path[open-1].y;

	for (i=1;i<=R;++i) for (j=1;j<=C;++j) visit[i][j]=false;

	path[0].x=Rstart.x;
	path[0].y=Rstart.y;
	path[0].len=0;
	visit[path[0].x][path[0].y]=true;
	
	for (closed=0,open=1;closed<open;++closed)
	{
		for (k=0;k<4;++k)
		{
			temp.len=path[closed].len+1;
			temp.x=path[closed].x+Dir[k][0];
			temp.y=path[closed].y+Dir[k][1];
			if (temp.InRange() && !visit[temp.x][temp.y] && map[temp.x][temp.y]) 
			{
				path[open++]=temp;
				visit[temp.x][temp.y]=true;
			}
		}
	}

	cout<<path[open-1].len<<endl;
}



void init()
{
	int i,j,k;
	char temp[2000];

	scanf("%d%d",&C,&R);
	gets(temp);
	for (i=1;i<=R;++i)
	{
		gets(temp);
		for (j=1;j<=C;++j) if (temp[j-1]=='#') map[i][j]=false; else map[i][j]=true;
	}

	deal();
}


int main()
{
	int T;
	int i;

	cin>>T;
	{
		for (i=1;i<=T;++i)
			init();
	}

	return 0;
}
