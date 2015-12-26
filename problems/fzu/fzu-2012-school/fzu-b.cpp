/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 01:17:33 PM
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
#define S 400100
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct edge{ int f,t,id,w,n; }e[S],es[S];
struct ufind
{
	int p[S],t;
	void init()
	{
		int i;
		for(i=0; i<S; i++)	p[i]=i;
	}
	void run(int &x)
	{
		for(; p[t=x]!=x; x=p[x],p[t]=p[x]);
	}
	void set_friend(int i,int j)
	{
		run(i);
		run(j);
		p[i]=j;
	}
	int is_friend(int i,int j)
	{
		run(i);
		run(j);
		return i==j;
	}
	int _p(int x)
	{
		run(x);
		return x;
	}
}uf;
int tree,T,list[S],top,g[S],low[S],dfn[S],tag[S];

inline int cmp(edge a, edge b){ return a.w<b.w; }

void insert(int f,int t,int id)
{
	es[top].f=f,es[top].t=t,es[top].id=id;
	es[top].n=list[f],list[f]=top++;
}

void tarjan(int now,int id)
{
	int i;
	dfn[now]=low[now]=T++;
	g[now]=tree;
	for(i=list[now]; i!=-1; i=e[i].n)
	{
		if(es[i].id==id)
			continue;
		if(g[es[i].t]!=tree)
		{
			tarjan(es[i].t,es[i].id);
			if(low[now]>low[es[i].t])
				low[now]=low[es[i].t];
		}
		else if(low[now]>dfn[es[i].t])
			low[now]=dfn[es[i].t];
	}
	if(id>=0&&dfn[now]==low[now])
		tag[id]=-1;
}

int main()
{
	int n,m,i,j,k,fa,fb,ca,ret;
	scanf("%d",&ca);
	for(int _ca=1; _ca<=ca; _ca++)
	{
		uf.init();
		ret=0;
		tree=0;
		memset(g,0,sizeof(g));
		scanf("%d%d",&n,&m);
		for(i=0; i<=n; i++)
			list[i]=-1;
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d",&e[i].f,&e[i].t,&e[i].w);
			e[i].f--,e[i].t--;
			e[i].id=i;
		}
		sort(e,e+m,cmp);
		for(i=0; i<m; i=j)
		{
			for(j=i+1; j<m&&e[j].w==e[i].w; j++);
			for(k=i; k<j; k++)
			{
				fa=uf._p(e[k].f),fb=uf._p(e[k].t);
				if(fa==fb)
					tag[e[k].id]=0;
				else
					tag[e[k].id]=1;
				list[fa]=-1,list[fb]=-1;
			}
			/*
			for(top=0,k=i; k<j; k++)
			{
				fa=uf._p(e[k].f),fb=uf._p(p[k].t);
				if(fa!=fb)
				{
					insert(fa,fb,e[k].id);
					insert(fb,fa,e[k].id);
				}
			}
			for(tree++,T=1,k=i; k<j; k++)
			{
				fa=uf._p(e[k].f),fb=uf._p(e[k].t);
				if(fa!=fb)
				{
					if(g[fa]!=tree)
						tarjan(fa,-1);
					if(g[fb]!=tree)
						tarjan(fb,-1);
				}
			}
			*/
			for(k=i; k<j; k++)
				uf.set_friend(e[k].f,e[k].t);
		}
		for(i=0; i<m; i++)
			if(tag[i]!=0)
				ret++;
		printf("%d\n",ret);
	}
	return 0;
}
