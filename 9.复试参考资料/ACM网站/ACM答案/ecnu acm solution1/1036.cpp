#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INFINITE=2147483647;

int dis[2000];
bool visit[2000];
int map[1001][1001];
int path[2000];

//存储边集
int bian[1001][1002];

struct node
{
	int dist;
	int ID;
};

bool operator<(const node &a,const node &b)
{ return a.dist>b.dist; }

priority_queue< node,vector<node> > heap;

int N,M;

void init()
{
	int i,j,k;
	scanf("%d",&M);

	while( !heap.empty() ) heap.pop();

	//初始化
	for (i=1;i<=N;++i) 
	{
		dis[i]=INFINITE;
		visit[i]=false;
		path[i]=0;
		bian[i][0]=0;
		for (j=1;j<=N;++j) map[i][j]=INFINITE;
	}

	//读入信息
	for (k=1;k<=M;++k)
	{
		scanf("%d%d",&i,&j);
		scanf("%d",&map[i][j]);
		map[j][i]=map[i][j];

		bian[i][0]++;
		bian[j][0]++;
		bian[i][bian[i][0]]=j;
		bian[j][bian[j][0]]=i;
	}

	//堆初始化
	dis[2]=0;
	path[2]=1;
	node temp;
	temp.dist=0;
	temp.ID=2;
	heap.push(temp);

	int l;
	while (true)
	{
		//从堆中找出最小距离
		while (!heap.empty() && visit[heap.top().ID]) heap.pop();
		if (heap.empty()) break;

		k=heap.top().ID;
		dis[k]=heap.top().dist;
		heap.pop();

		visit[k]=true;
		for (j=1;j<=bian[k][0];++j) 
		{
			l=bian[k][j];
			//满足松弛操作，加入堆
			if (dis[k]+map[k][l]<dis[l]) 
			{
				dis[l]=dis[k]+map[k][l];
				temp.ID=l;
				temp.dist=dis[l];
				heap.push(temp);
			}
			//DP计算方案
			if (visit[l] && dis[l]<dis[k]) path[k]+=path[l];
		}

	}

	printf("%d\n",path[1]);
}

int main()
{
	while (scanf("%d",&N)==1)
	{
		if (N==0) break;
		init();
	}
	return 0;
}