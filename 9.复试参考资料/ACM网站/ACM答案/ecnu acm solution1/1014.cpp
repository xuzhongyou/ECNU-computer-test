#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Rect
{
	int x,y;
	bool operator<(const Rect & b) const 
	{ return x<b.x || x==b.x && y<b.y; }

	bool operator==(const Rect & b) const
	{ return x==b.x && y==b.y; }
};

map<Rect,int> ans;
map<Rect,int>::iterator itr;
int answers;
int times[10];
Rect r[10];

void init()
{
	Rect temp;
	int i;

	while (cin>>temp.x>>temp.y)
	{
		ans.clear();
		if (temp.x>temp.y) swap(temp.x,temp.y);
		r[1]=temp;

		if (ans.find(temp)==ans.end()) 
			ans[temp]=1;
		else
			ans.find(temp)->second++;

		for (i=2;i<=6;++i)
		{
			cin>>temp.x>>temp.y;
			if (temp.x>temp.y) swap(temp.x,temp.y);
			r[i]=temp;
			if (ans.find(temp)==ans.end()) 
				ans[temp]=1;
			else
				ans.find(temp)->second++;
		}

		answers=0;
		for (itr=ans.begin();itr!=ans.end();itr++)
		{
			times[answers++]=itr->second;
		}
		
		sort(r+1,r+7);
		unique(r+1,r+7);

		if (answers==3)
		{
			if (times[0]==2 && times[1]==2 && times[2]==2 && r[1].x==r[2].x && r[1].y==r[3].x && r[2].y==r[3].y && r[1].y!=r[2].y) cout<<"POSSIBLE"<<endl;
			else cout<<"IMPOSSIBLE"<<endl;
			continue;
		}

		if (answers==2)
		{
			if (times[0]==4 && times[1]==2 && (r[2].x==r[2].y && r[2].x==r[1].x || r[2].x==r[2].y && r[2].x==r[1].y))
			{cout<<"POSSIBLE"<<endl; continue;}
			if (times[0]==2 && times[1]==4 && (r[1].x==r[1].y && r[1].x==r[2].x || r[1].x==r[1].y && r[1].x==r[2].y))
			{cout<<"POSSIBLE"<<endl; continue;}
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}

		if (answers==1)
		{
			if (r[1].x==r[1].y)
			{
				cout<<"POSSIBLE"<<endl;
				continue;
			}
		}
		cout<<"IMPOSSIBLE"<<endl;
		continue;
	}
}

int main()
{
	init();

	return 0;
}


