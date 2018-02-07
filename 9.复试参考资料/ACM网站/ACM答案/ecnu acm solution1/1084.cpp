#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

int gcd(int x,int y)
{
	if (y==0) return x;
	else return gcd(y,x%y);
}

struct vect
{
	int x,y;
	
	void normal()
	{
		int k=gcd(x,y);
		x=x/k;
		y=y/k;
	}

	vect operator-(const vect & b)
	{
		vect temp;
		temp.x=x-b.x;
		temp.y=y-b.y;
		return temp;
	}

	bool operator<(const vect & b) const
	{
		if (x<b.x) return true;
		if (x==b.x && y<b.y) return true;
		return false;
	}

}v[1000],p[1000];

int N;
map<vect,int> app;
map<vect,int>::iterator itr;

bool com(const vect &a,const vect &b)
{
	if (a.x<b.x) return true;
	if (a.x==b.x && a.y<b.y) return true;
	return false;
}


void deal()
{
	int i,j,k;
	for (i=1;i<=N;++i) scanf("%d%d",&p[i].x,&p[i].y);

	int ans=2;
	int now;
	int nowbest;
	
	for (i=1;i<=N;++i)
	{
		//app.clear();
		now=0;
		for (j=i+1;j<=N;++j) 
		{
			v[now]=p[j]-p[i];
			v[now].normal();
			//itr=app.find(v[now]);
			/*if (itr==app.end())
			{
				app[v[now]]=2;
			}
			else
			{
				itr->second++;
				if (itr->second>ans) ans=itr->second;
			}
			*/
			now++;
		}
		sort(v,v+now,com);
		//cout<<now<<endl;
		//for (j=0;j<now;++j) cout<<v[j].x<<" "<<v[j].y<<endl;
		
		j=0;
		while (j<now)
		{
			nowbest=2;
			while (j+1<now && v[j+1].x==v[j].x && v[j+1].y==v[j].y) 
			{
				j++;
				nowbest++;
			}
			if (nowbest>ans) ans=nowbest;
			j++;
		}
		
		
	}
	
	printf("%d\n",ans);
}


int main()
{
	while (true)
	{
		scanf("%d",&N);
		if (N==0) break;
		deal();
	}

	return 0;
}





