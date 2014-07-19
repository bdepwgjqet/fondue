/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/24/2012 07:13:48 PM
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
#define N 101000
#define M 1000010
#define S 1000100
#define inf 0x7fffffff
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct edge{ int f,t,n; }e[N<<1];

int list[N],top,v[N],vis[N],ret,tag,col[N],dp[N][3],n,find_id;

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int dfs(int now,int pre)
{
	int r=0;
	if(dp[now][col[pre]]>=0)	return dp[now][col[pre]];
	v[now]=1;

	col[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
		if(!v[e[i].t])
			r+=dfs(e[i].t,now);
	r++;
	col[now]=-1;

	if(col[pre]==1)
	{
		col[now]=0;
		int tmp=0;
		for(int i=list[now]; i!=-1; i=e[i].n)
			if(!v[e[i].t])
				tmp+=dfs(e[i].t,now);
		r=min(r,tmp);
		col[now]=-1;
	}

	v[now]=0;
	return dp[now][col[pre]]=r;
}

int calc(int now,int ignore)
{
	int r=0;
	memset(v,0,sizeof(v));
	memset(col,-1,sizeof(col));
	memset(dp,-1,sizeof(dp));
	v[now]=1,col[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
		if(e[i].t!=ignore)
			r+=dfs(e[i].t,now);
	return r+1;
}

void solve(int id)
{
	ret=inf;
	ret=min(ret,calc(e[id].f,e[id].t));
	ret=min(ret,calc(e[id].t,e[id].f));
}

void find_round(int now,int pre)
{
	vis[now]=1;
	for(int i=list[now]; i!=-1&&tag==0; i=e[i].n)
	{
		if(e[i].t==pre)	continue;
		if(!vis[e[i].t])
			find_round(e[i].t,now);
		else
		{
			tag=1;
			find_id=i;
			return ;
		}
	}
}

int main()
{
	int x,y,m;
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&m);
			for(int j=0; j<m; j++)
			{
				scanf("%d",&x);
				x--;
				insert(i,x);
			}
		}
		memset(vis,0,sizeof(vis));
		tag=0;
		find_round(0,-1);
		solve(find_id);
		printf("%d\n",ret);
	}
	return 0;
}
