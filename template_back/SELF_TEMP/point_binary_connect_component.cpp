//point_binary_connect_component
//tarjan
#include <cstdio>
#include <cstring>
#define MAXS 8000800
#define MAXN 1010

struct edge{ int f,t,n,v; }e[MAXS];
int list[MAXN],top,st[MAXS],s_top,dfn[MAXN],low[MAXN],id,comp[MAXN];

void s_insert(int f,int t,int v)
{
	e[top].f=f,e[top].t=t,e[top].v=v;
	e[top].n=list[f],list[f]=top++;
}

void insert(int f,int t,int v)
{
	s_insert(f,t,0);
	s_insert(t,f,0);
}

inline int min(int a,int b){ return a<b?a:b; }


void record(int now,int n)
{
	int i;
	for(id++; ;)
	{
		i=st[s_top--];
		comp[e[i].f]=comp[e[i].t]=id;
		if(e[i].f==now)	break;
	}
}

void dfs(int now,int &cnt,int n)
{
	int i,t;
	dfn[now]=low[now]=++cnt;
	for(i=list[now]; i!=-1; i=e[i].n)
		if(!e[i].v)	
		{
			e[i].v=e[i^1].v=1;
			t=e[i].t;
			st[++s_top]=i;
			if(!dfn[t])
			{
				dfs(t,cnt,n);
				low[now]=min(low[now],low[t]);
				if(low[t]>=dfn[now])
					record(now,n);
			}
			else low[now]=min(low[now],dfn[t]);
		}
}

void p_b_component(int n)
{
	int i,cnt=0; s_top=-1,id=0;
	memset(st,0,sizeof(st));
	memset(dfn,0,sizeof(dfn));
	for(i=0; i<n; i++)
		if(!dfn[i])
			dfs(i,cnt,n);
}


