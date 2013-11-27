/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/16/2012 11:20:00 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MAXS 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

struct point{ int x,y; }p[MAXN];

int is_sup(int id,int n)
{
	int i,x=p[id].x,y=p[id].y;
	int tag[4];
	memset(tag,0,sizeof(tag));
	for(i=0; i<n; i++)
	{
		if(i==id)	continue;
		if(x==p[i].x)
		{
			if(y>p[i].y)
				tag[0]=1;
			else if(y<p[i].y)
				tag[1]=1;
		}
		else if(y==p[i].y)
		{
			if(x>p[i].x)
				tag[2]=1;
			else if(x<p[i].x)
				tag[3]=1;
		}
	}
	for(i=0; i<4; i++)
		if(tag[i]==0)
			return 0;
	return 1;
}

int main()
{
	int n,i,ret;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0; i<n; i++)
			scanf("%d%d",&p[i].x,&p[i].y);
		for(ret=i=0; i<n; i++)
			if(is_sup(i,n))
				ret++;
		printf("%d\n",ret);
	}
	return 0;
}


