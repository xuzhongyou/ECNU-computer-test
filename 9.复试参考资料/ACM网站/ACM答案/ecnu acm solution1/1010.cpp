#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

//ifstream fin("1.in");

struct Word
{
	string w,num;
}word[200];

bool com(const Word & x,const Word & y)
{
	if (x.w<y.w) return true;
	return false;
}

string tar;
int words;

/*
2 A B C
3 D E F
4 G H I
5 J K L
6 M N O
7 P Q R S
8 T U V
9 W X Y Z
*/
char CharToChar(const char & x)
{
	if (strchr("ABC",x)!=NULL) return '2';
	if (strchr("DEF",x)!=NULL) return '3';
	if (strchr("GHI",x)!=NULL) return '4';
	if (strchr("JKL",x)!=NULL) return '5';
	if (strchr("MNO",x)!=NULL) return '6';
	if (strchr("PQRS",x)!=NULL) return '7';
	if (strchr("TUV",x)!=NULL) return '8';
	if (strchr("WXYZ",x)!=NULL) return '9';
	return 0;
}

void init()
{
	int i,j,k;

	for (i=0;i<words;++i)
	{
		cin>>word[i].w;
		word[i].num.resize(word[i].w.length());
		for (j=0;j<word[i].w.length();++j) word[i].num[j]=CharToChar(word[i].w[j]);
	}
	cin>>tar;
	char temp[20];
	int len=0;
	
	for (i=0;i<tar.length();++i) 
		if (tar[i]!='0' && tar[i]!='1') temp[len++]=tar[i];
	temp[len]='\0';

	tar=temp;

	sort(word,word+words,com);

	
	//完全相同
	for (i=0;i<words;++i)
	{
		if (word[i].num==tar) cout<<word[i].w<<endl;
	}

	//联想
	for (i=0;i<words;++i)
	{
		if (word[i].num.length()>tar.length() && word[i].num.substr(0,tar.length())==tar) cout<<word[i].w<<endl;
	}

	//差一位
	int changes;
	for (i=0;i<words;++i)
	{
		changes=0;
		if (word[i].num.length()==tar.length())
		{
			for (j=0;j<word[i].num.length();++j) if (word[i].num[j]!=tar[j]) changes++;
		}
		if (changes==1) cout<<word[i].w<<endl;
	}

	//差一位联想
	for (i=0;i<words;++i)
	{
		changes=0;
		if (word[i].num.length()>tar.length())
		{
			for (j=0;j<tar.length();++j) if (word[i].num[j]!=tar[j]) changes++;
		}
		if (changes==1) cout<<word[i].w<<endl;
	}



}



int main()
{
	while (cin>>words)
	{
		init();
	}

	//system("pause");
	return 0;
}
