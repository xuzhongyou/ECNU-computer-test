#include <iostream>
using namespace std;

int days[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int mon;
int day;

void deal()
{
	int d1,d2;
	int i,j;

	d1=0;
	for (i=1;i<10;++i)
		d1+=days[i];
	for (j=1;j<=21;++j)
		d1++;

	//cout<<d1<<endl;

	d2=0;
	for (i=1;i<mon;++i)
		d2+=days[i];
	for (i=1;i<=day;++i)
		d2++;

	//cout<<d2<<endl;

	int ans;
	ans=d1-d2;

	if (ans>0) 
	{
		cout<<ans<<endl;
	}
	if (ans==0)
	{
		cout<<"It's today!!"<<endl;
	}
	if (ans<0)
	{
		cout<<"What a pity, it has passed!"<<endl;
	}

}


int main()
{
	int N;
	int i;
	cin>>N;
	for (i=1;i<=N;++i)
	{
		cin>>mon>>day;
		deal();
	}
	
	//system("pause");
	return 0;
}
