#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

char word[20][20];
int dis[20][20];
int posi[20];
int N;

int Distance(char *a,char *b)
{
	int l1=strlen(a);
	int l2=strlen(b);

	int ans=0;
	int now=0;
	int i,j;

	for (i=0;i<l1;++i)
	{
		now=0;
		for (j=0;j<l2 && j+i<l1;++j) if (b[j]==a[j+i]) now++;
		if (now>ans) ans=now;
	}

	for (i=0;i<l2;++i)
	{
		now=0;
		for (j=0;j<l1 && j+i<l2;++j) if (a[j]==b[j+i]) now++;
		if (now>ans) ans=now;
	}

	return ans;
}

void init()
{
	int i,j;
	int ans=0;
	int now=0;
	
	for (i=0;i<N;++i) cin>>word[i];

	for (i=0;i<N;++i)
		for (j=0;j<N;++j) dis[i][j]=Distance(word[i],word[j]);

	for (i=0;i<N;++i) posi[i]=i;



	now=0;
	for (i=0;i<N-1;++i) now+=dis[posi[i]][posi[i+1]];
	if (now>ans) ans=now;
	//…˙≥…≈≈¡–
	while (true)
	{
		if (next_permutation(posi,posi+N)==false) break;
		now=0;
		for (i=0;i<N-1;++i) now+=dis[posi[i]][posi[i+1]];
		if (now>ans) ans=now;
	}

	cout<<ans<<endl;
}


int main()
{
	while (cin>>N)
	{
		if (N==0) break;
		init();
	}
	return 0;
}