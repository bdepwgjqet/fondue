/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/10/2012 08:18:17 PM
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
#define N 210
#define M 100010
#define S 100100
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

struct edge{ int f,t,n,w; }e[S],es[S];
int top,list[N],lay[N],q[S];

void insert(int f,int t,int w)
{
	e[top].f=f,e[top].t=t,e[top].w=w;
	e[top].n=list[f],list[f]=top++;
}

void _insert(int f,int t,int w)
{
	insert(f,t,w);
	insert(t,f,0);
}

int bfs(int s,int t,int n)
{
	int l,r;
	for(int i=0; i<n; i++)
		lay[i]=-1;
	q[l=r=0]=s;
	lay[s]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=list[now]; i!=-1; i=e[i].n) 
		{
			int to=e[i].t;
			if(lay[to]<0&&e[i].w>0)
			{
				lay[to]=lay[now]+1;
				q[++r]=to;
			}
		}
	}
	return lay[t]>=0;
}

int dfs(int now,int t,int now_flow)
{
	int ttl=0,i,j,single;
	if(now==t)
		return now_flow;
	for(int i=list[now]; i!=-1&&ttl<now_flow; i=e[i].n)
	{
		int to=e[i].t;
		if(lay[to]==lay[now]+1&&e[i].w>0&&(single=dfs(to,t,min(now_flow-ttl,e[i].w))))
		{
			e[i].w-=single;
			e[i^1].w+=single;
			ttl+=single;
		}
	}
	if(ttl==0)
		lay[now]=-1;
	return ttl;
}

int dicnic(int s,int t,int n)
{
	int ret=0;
	while(bfs(s,t,n))
	{
		ret+=dfs(s,t,inf);
	}
	return ret;
}

int main()
{
	int s,t,n,m,x,y,ret;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<m; i++)
		{
			scanf(" (%d,%d)",&x,&y);
			es[i].f=x,es[i].t=y;
		}
	//	s=0;
		ret=inf;
		for(s=0; s<n; s++)
		for(t=1; t<n; t++)
		{
			if(t==s)	continue;
			top=0;
			for(int i=0; i<n+n; i++)
				list[i]=-1;
			for(int i=0; i<n; i++)
				_insert(i,n+i,1);
			for(int i=0; i<m; i++)
			{
				x=es[i].f,y=es[i].t;
				_insert(n+x,y,inf);
				_insert(n+y,x,inf);
			}
			ret=min(ret,dicnic(s+n,t,n+n));
		}
		if(ret>n) ret=n;
		printf("%d\n",ret);
	}
	return 0;
}
