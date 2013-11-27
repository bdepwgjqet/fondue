/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/24/2012 04:19:25 PM
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

struct edge{ int f,t,n; }e[S];
int list[N],v[N],top;

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int dfs(int now,int ed,int l)
{
	printf("%d %d\n",now,ed);
	if(ed==now)	return 1;
	if(l==6)	return 0;
	v[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
		if(!v[e[i].t])
		{
			if(dfs(e[i].t,ed,l+1))	return 1;
		}
	v[now]=0;
	return 0;
}

int main()
{
	int n,m,st,ed,x,y;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		top=0;
		for(int i=0; i<=n; i++)	list[i]=-1;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d",&x,&y);
			insert(x,y);
			insert(y,x);
		}
		scanf("%d%d",&st,&ed);
		memset(v,0,sizeof(v));
		if(dfs(st,ed,0))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}


