#include <iostream>
using namespace std;

long long int N;

const int maxlen = 200;
class HP 
{ 
public:
	int len,s[maxlen];

	HP() { (*this)=0;};
	HP(int inte) { (*this)=inte;};
	
	HP operator=(int inte);
	HP operator*(const HP & b);

	friend ostream& operator<<(ostream & cout,const HP &x);
};

ostream & operator<<(ostream & cout,const HP &x)
{ for (int i=x.len;i>=1;--i) cout<<x.s[i];return cout;}

HP HP::operator=(int inte)
{
	if (inte==0) {len=1;s[1]=0;return (*this);};
	for (len=0;inte>0;) {s[++len]=inte%10;inte/=10;};
	return (*this);
}

HP HP::operator*(const HP &b)
{
	int i,j;HP c;c.len=len+b.len;
	for (i=1;i<=c.len;i++) c.s[i]=0;
	for (i=1;i<=len;i++) for (j=1;j<=b.len;++j) c.s[i+j-1]+=s[i]*b.s[j];
	for (i=1;i<c.len;++i) {c.s[i+1]+=c.s[i]/10;c.s[i]%=10;}
	while (c.s[i]) {c.s[i+1]=c.s[i]/10;c.s[i]%=10;i++;}
	while (i>1 && !c.s[i]) i--;c.len=i;
	return c;
}

HP three[100];

void init()
{
	int i;
	three[0]=1;
	for (i=1;i<100;++i) three[i]=three[i-1]*3;
}

void deal()
{
	int temp[100];
	memset(temp,0,sizeof(temp));
	int len=0;

	int j;
	
	N--;
	while (N>0)
	{
		j=N % 2;
		N=N / 2;
		temp[len++]=j;
	}
	
	cout<<"{";
	int first=0;
	while (!temp[first]) first++;
	cout<<three[first];
	for (j=first+1;j<len;++j) if (temp[j]) cout<<","<<three[j];
	cout<<"}"<<endl;
	
}


int main()
{
	init();

	while (cin>>N)
	{
		if (N==0) break;
		deal();
	}

	return 0;
}