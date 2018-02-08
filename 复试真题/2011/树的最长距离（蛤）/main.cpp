#include <iostream>
#include <string.h>
#include <vector>
#define MAX 1001
using namespace std;

int map[MAX][MAX],dis[MAX],vis[MAX],cnt[MAX],parent[MAX],path[MAX];
//dfs(起点,总节点数,是否访问过的数组,最大值,最大值下标)

void dfs(int s,int n,int vis[],int &max,int &max_p){
	vis[s] = 1;
	for(int i = 1;i <= n;i++){
		if(vis[i]==0&&map[s][i]!=0)
        {
			dis[i] = dis[s] + map[s][i];
			if(max < dis[i]){
				max = dis[i];
				max_p = i;
			}
			parent[i] = s;
			dfs(i,n,vis,max,max_p);
		}
	}
}

void maxdis(int s,int n,int _dis,int &max,int vis[]){
	vis[s] = 1;
	for(int i = 1;i <= n;i++)
    {
		if(path[i]==0&&map[s][i]!=0&&vis[i] == 0){
			if(_dis+map[s][i] > max){
				max = _dis+map[s][i];
			}
			maxdis(i,n,_dis+map[s][i],max,vis);
		}
	}
}

void output(int n){
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= n;j++)
			cout<<map[i][j]<<" ";
		cout<<endl;
	}
}

int main(){
	int T;
	cin>>T;
	while(T--){
		memset(map,0,sizeof(map));
		memset(cnt,0,sizeof(cnt));
		memset(dis,0,sizeof(dis));
		memset(path,0,sizeof(path));
		int n;
		cin>>n;
		for(int k = 1;k < n;k++){
			int i,j,d;
			cin>>i>>j>>d;
			map[i][j] = d;
			map[j][i] = d;
			cnt[i]++;
			cnt[j]++;
		}
		output(n);
		int max = 0,max_p,max_e;
		for(int i = 1;i <= n;i++){
			if(cnt[i] == 1)
			{
				memset(vis,0,sizeof(vis));
				dfs(i,n,vis,max,max_p);
				break;
			}
		}

		cout<<"最长路径起点:"<<max_p<<endl;//找到距离任选的起点的最远点
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		memset(parent,0,sizeof(parent));
		parent[max_p] = max_p;
		max = 0;
		dfs(max_p,n,vis,max,max_e);
		cout<<"最长路径终点:"<<max_e<<endl;

		int n1 = parent[max_e];
		vector<int> v;
		while(n1!=parent[n1]){
			path[n1] = 1;
			v.push_back(n1);
			n1 = parent[n1];
		}//标记路径上的点并加入vector
		path[max_e] = 1;
		path[max_p] = 1;
		for(int i = 1;i <= n;i++)
			cout<<parent[i]<<" ";
		cout<<endl;
		//---求得最远距离
		int maxres = 0;
		for(int i = 0;i < v.size();i++){
			int sp = v[i];
			memset(vis,0,sizeof(vis));
			int _maxd = 0;
			maxdis(sp,n,0,_maxd,vis);
			if(_maxd>maxres)
				maxres=_maxd;
		}
		cout<<maxres<<endl;
	}
}
