#include <iostream>
#include <string.h>
#include <vector>
#define MAX 1001
#include <stdio.h>
using namespace std;

int map[MAX][MAX],dis[MAX],vis[MAX],cnt[MAX],parent[MAX],path[MAX];
//dfs(起点,总节点数,是否访问过的数组,最大值,最大值下标)
void dfs3(int s,int n,int vis[],int &max,int &max_p)
{
	vis[s] = 1;
	for(int i = 1;i <= n;i++)
    {
		if(vis[i]==0&&map[s][i]!=0)
		{
			dis[i] = dis[s] + map[s][i];
			if(max < dis[i]){
				max = dis[i];
				max_p = i;
			}
			parent[i] = s;
			dfs3(i,n,vis,max,max_p);
		}
	}
}

void maxDfs(int s,int n,int vis[],int &ans)
{
    vis[s]=1;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0&&path[i]==0&&map[s][i]!=0)
        {
            dis[i]=dis[s]+map[s][i];
            if(ans<dis[i])
            {
                ans=dis[i];
            }
            maxDfs(i,n,vis,ans);
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
				dfs3(i,n,vis,max,max_p);
				break;
			}
		}
		cout<<"最长路径起点:"<<max_p<<endl;//找到距离任选的起点的最远点
		memset(vis,0,sizeof(vis));
		memset(dis,0,sizeof(dis));
		memset(parent,0,sizeof(parent));
		parent[max_p] = max_p;
		max=0;
		dfs3(max_p,n,vis,max,max_e);
		cout<<"最长路径终点:"<<max_e<<endl;

		vector<int> v;
		int n1=max_e;
		path[max_p]=1;
		while(n1!=max_p)
        {
            v.push_back(n1);
            path[n1]=1;
            n1=parent[n1];
        }
        v.push_back(max_p);
        for(int i=0;i<v.size();i++)
            printf(" %d ",v[i]);
        printf("\n");

        max=0;

        for(int i=0;i<v.size();i++)
        {
            int ans=0;
            int sp=v[i];
            memset(vis,0,sizeof(vis));
            memset(dis,0,sizeof(dis));
            maxDfs(sp,n,vis,ans);
            printf("%d ",ans);
            if(max<ans)
                max=ans;
        }
        cout<<"distant is："<<max<<endl;

	}
}

