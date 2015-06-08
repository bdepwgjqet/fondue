/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/16/2012 11:20:14 PM
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
#define MAXM 1000010
#define MOD 1000000007
#define N 100011

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
inline int lowbit(int x){ return x&(-x); }

struct edge{ int f,t,n,i; }e[2*N];

int bit[N],deg[N],top,list[N],id[N],bran[N],BR,T,dis[N],e2p[N],head[N];

void insert(int f,int t,int id)
{
	e[top].f=f,e[top].t=t,e[top].i=id;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int pre,int lay)
{
	int i;
	bran[now]=BR;
	id[now]=T++;
	dis[now]=lay;
	for(i=list[now]; i!=-1; i=e[i].n)
	{
		if(e[i].t==pre)
			continue;
		dfs(e[i].t,now,lay+1);
	}
}

void update(int pos,int x)
{
	int i;
	for(i=pos; i<N; i+=lowbit(i))
		bit[i]+=x;
}

int calc(int pos)
{
	if(pos<0)	return 0;
	int i,ret=0;
	for(i=pos; i>0; i-=lowbit(i))
		ret+=bit[i];
	return ret;
}

int calc(int x,int y,int tag)
{
	int t;
	if(y<x)
		t=x,x=y,y=t;
	if(tag)
		x--;
	return calc(y)-calc(x);
}

int main()
{
	int n,i,x,y,m,t,root,u;
	while(scanf("%d",&n)!=EOF)
	{
		memset(bit,0,sizeof(bit));
		memset(deg,0,sizeof(deg));
		for(top=i=0; i<=n; i++)
			list[i]=-1;
		for(i=1; i<n; i++)
		{
			scanf("%d%d",&x,&y);
			insert(x,y,i);
			insert(y,x,i);
			deg[x]++;
			deg[y]++;
		}
		root=1;
		for(i=1; i<=n; i++)
			if(deg[i]>2)
				root=i;
		T=1,BR=1;
		for(i=list[root]; i!=-1; i=e[i].n)
		{
			head[BR]=T;
			dfs(e[i].t,root,1);
			BR++;
		}
		dis[root]=0,bran[root]=0,id[root]=0;
		head[0]=0;
		for(i=0; i<n-1; i++)
		{
			x=e[i<<1].f,y=e[i<<1].t;
			e2p[i+1]=(dis[x]>dis[y]?x:y);
		}
		scanf("%d",&m);
		for(i=0; i<m; i++)
		{
			scanf("%d",&t);
			if(t==1)
			{
				scanf("%d",&x);
				update(id[e2p[x]],-1);
			}
			else if(t==2)
			{
				scanf("%d",&x);
				update(id[e2p[x]],1);
			}
			else
			{
				scanf("%d%d",&x,&y);
				if(bran[x]==bran[y])
				{
					u=calc(id[x],id[y],0);
					if(u!=0)
						puts("-1");
					else
						printf("%d\n",abs(dis[x]-dis[y]));
				}
				else
				{
					u=calc(id[x],head[bran[x]],1);
					u+=calc(id[y],head[bran[y]],1);
					if(u!=0)
						puts("-1");
					else
						printf("%d\n",dis[x]+dis[y]);
				}
			}
		}
	}
	return 0;
}
