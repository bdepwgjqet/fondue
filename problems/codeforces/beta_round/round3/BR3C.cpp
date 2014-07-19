/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/27/2012 09:57:06 AM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

char s[3][3];
int c1,c2,np;

int ok()
{
	int a=0,b=0;
	for(int i=0; i<3; i++)
	{
		if(s[i][0]==s[i][1]&&s[i][1]==s[i][2])
		{
			if(s[i][0]=='0')
				b=1;
			else if(s[i][0]=='X')
				a=1;
		}
		if(s[0][i]==s[1][i]&&s[1][i]==s[2][i])
		{
			if(s[0][i]=='0')
				b=1;
			else if(s[0][i]=='X')
				a=1;
		}
	}
	if(s[0][0]==s[1][1]&&s[1][1]==s[2][2])
		if(s[0][0]=='0')
			b=1;
		else if(s[0][0]=='X')
			a=1;
	if(s[0][2]==s[1][1]&&s[1][1]==s[2][0])
		if(s[0][2]=='0')
			b=1;
		else if(s[0][2]=='X')
			a=1;
	if(a&&b)
		return -1;
	if(a==0&&b==0)
	{
		for(int i=0; i<3; i++)
			for(int j=0; j<3; j++)
				if(s[i][j]=='.')
					return 0;
		return -2;
	}
	if(a)
		return 1;
	if(b)
		return 2;
}

int main()
{
	for(int i=0; i<3; i++)
		scanf("%s",s[i]);
	c1=c2=0;
	for(int i=0; i<3; i++)
		for(int j=0; j<3; j++)
		{
			if(s[i][j]=='0')
				c2++;
			else if(s[i][j]=='X')
				c1++;
		}
	int tag=ok();
	if(c1==c2||c1==c2+1)
	{
		if(tag==0)
		{
			if(c1==c2)
				np=0;
			else
				np=1;
			if(np==0)
				puts("first");
			else
				puts("second");
		}
		else if(tag==-1)
			puts("illegal");
		else if(tag==-2)
			puts("draw");
		else if(tag==1)
		{
			if(c1!=c2)
				puts("the first player won");
			else
				puts("illegal");
		}
		else
		{
			if(c1==c2)
				puts("the second player won");
			else
				puts("illegal");
		}
	}
	else
		puts("illegal");
	return 0;
}
