/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/05/2012 07:42:38 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[10][10];

void cnt_num(int &x,int &y)
{
	x=y=0;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			if(s[i][j]=='O')
				y++;
			else if(s[i][j]=='X')
				x++;
		}
}

int win(char x)
{
	for(int i=0; i<3; i++)
	{
		if(s[i][0]==x&&s[i][1]==x&&s[i][2]==x)
		{
			s[i][0]=s[i][1]=s[i][2]='.';
			return 1;
		}
		if(s[0][i]==x&&s[1][i]==x&&s[2][i]==x)
		{
			s[0][i]=s[1][i]=s[2][i]='.';
			return 1;
		}
	}
	if(s[0][0]==x&&s[1][1]==x&&s[2][2]==x)
	{
		s[0][0]=s[1][1]=s[2][2]='.';
		return 1;
	}
	if(s[0][2]==x&&s[1][1]==x&&s[2][0]==x)
	{
		s[0][2]=s[1][1]=s[2][0]='.';
		return 1;
	}
	return 0;
}

int put_yes()
{
	int x,o,xw,ow;
	cnt_num(x,o);
	if(x<o)	return 0;
	if(x>o+1)	return 0;
	xw=win('X');
	ow=win('O');
	/*
	for(int i=0; i<3; i++)
		printf("%s\n",s[i]);
		*/
	if(ow&&x>o)
		return 0;
	if(xw&&x==o)
		return 0;
	if(xw&&ow)	return 0;
	if(xw&&win('X'))
		return 0;
	if(ow&&win('O'))
		return 0;
	return 1;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(; t--; )
	{
		for(int i=0; i<3; i++)
			scanf("%s",s[i]);
		if(put_yes())
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
