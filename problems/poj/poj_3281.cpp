/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/11/2012 10:13:28 AM
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
#define N 402
#define M 10000
#define S 161000
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

struct edge{ int f,t,w,n; }e[S];
int list[N],top,lay[N],q[S];

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
	memset(lay,-1,sizeof(lay));
	q[l=r=0]=s;
	lay[s]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=list[now]; i!=-1; i=e[i].n)
		{
			int to=e[i].t;
			if(lay[to]<0&&e[i].w>0)
				lay[to]=lay[now]+1,q[++r]=to;
		}
	}
	return lay[t]>=0;
}

int dfs(int now,int t,int now_flow)
{
	int ttl=0,single;
	if(now==t)	return now_flow;
	for(int i=list[now]; i!=-1&&now_flow>ttl; i=e[i].n)
	{
		int to=e[i].t;
		if(lay[to]==lay[now]+1&&e[i].w>0&&(single=dfs(to,t,min(now_flow-ttl,e[i].w))))
		{
			e[i].w-=single;
			e[i^1].w+=single;
			ttl+=single;
		}
	}
	if(ttl==0) lay[now]=-1;
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
	int n,f,d,nn;
	while(scanf("%d%d%d",&n,&f,&d)!=EOF)
	{
		nn=2*n+f+d;
		top=0;
		for(int i=0; i<nn+2; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
			_insert(i,n+i,1);
		for(int i=0; i<f; i++)
			_insert(nn,2*n+i,1);
		for(int i=0; i<d; i++)
			_insert(2*n+f+i,nn+1,1);
		for(int i=0; i<n; i++)
		{
			int fi,di,x;
			scanf("%d%d",&fi,&di);
			for(int j=0; j<fi; j++)
			{
				scanf("%d",&x);
				x--;
				_insert(2*n+x,i,1);
			}
			for(int j=0; j<di; j++)
			{
				scanf("%d",&x);
				x--;
				_insert(n+i,2*n+f+x,1);
			}
		}
		printf("%d\n",dicnic(nn,nn+1,nn+2));
	}
	return 0;
}
