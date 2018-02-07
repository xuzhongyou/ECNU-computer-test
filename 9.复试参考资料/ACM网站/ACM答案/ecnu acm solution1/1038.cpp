#include <iostream>
#include <set>
#include <string>

using namespace std;

int courses;
int cats;

set<string> app;

void init()
{
	int i,j,k;
	int total,demand;
	bool ok=true;
	
	char ctemp[100];
	string temp;
	app.clear();
	for (i=1;i<=courses;++i) 
	{
		scanf("%s",ctemp);
		temp=ctemp;
		app.insert(temp);
	}

	for (i=1;i<=cats;++i)
	{
		scanf("%d%d",&total,&demand);
		k=0;

		for (j=1;j<=total;++j)
		{
			scanf("%s",ctemp);
			temp=ctemp;
			if (app.find(temp)!=app.end()) k++;
		}

		if (k<demand) ok=false;
	}

	if (ok) printf("yes\n"); else printf("no\n");
}

int main()
{
	while (	cin>>courses)
	{
		if (courses==0) break;
		scanf("%d",&cats);
		init();
	}

	return 0;
}


	