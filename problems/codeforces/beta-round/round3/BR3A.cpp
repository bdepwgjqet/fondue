/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/30/2012 09:32:15 PM
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
struct node{ int x,y; }st,ed;
char s[4];
char ret[10][10]={"L","R","U","D","LU","LD","RU","RD" };

node get()
{
	node ret;
	ret.y=s[1]-'1';
	ret.x=s[0]-'a';
	return ret;
}

int cal()
{
	if(ed.x==0&&ed.y==0)
		return -1;
	if(ed.y==0)
	{
		if(ed.x>0)
		{
			ed.x--;
			return 0;
		}
		if(ed.x<0)
		{
			ed.x++;
			return 1;
		}
	}
	if(ed.x==0)
	{
		if(ed.y<0)
		{
			ed.y++;
			return 2;
		}
		else if(ed.y>0)
		{
			ed.y--;
			return 3;
		}
	}
	if(ed.x>0&&ed.y<0)
	{
		ed.x--,ed.y++;
		return 4;
	}
	if(ed.x>0&&ed.y>0)
	{
		ed.x--,ed.y--;
		return 5;
	}
	if(ed.x<0&&ed.y<0)
	{
		ed.x++,ed.y++;
		return 6;
	}
	ed.x++,ed.y--;
	return 7;
}

int main()
{
	scanf("%s",s);
	ed=get();
	scanf("%s",s);
	st=get();
	ed.x-=st.x,ed.y-=st.y;
	int x=ed.x,y=ed.y;
	int res=0;
	for(; cal()>=0; )
	{
		res++;
	}
	ed.x=x,ed.y=y;
	printf("%d\n",res);
	for(int i=0; i<res; i++)
	{
		int id=cal();
		printf("%s\n",ret[id]);
	}
	return 0;
}
