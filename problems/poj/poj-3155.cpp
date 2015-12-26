/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/10/2012 12:46:25 PM
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
#define N 2010
#define M 2000010
#define S 1000100
#define eps 1e-7
#define inf 1e8
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

struct edge{ int f,t,n; double w; }e[S],es[S];
int list[N],top,q[S],lay[S],vis[N],ans[N],anst;

void insert(int f,int t,double w)
{
	e[top].f=f,e[top].t=t,e[top].n=list[f];
	e[top].w=w,list[f]=top++;
}

void _insert(int f,int t,double w)
{
	insert(f,t,w);
	insert(t,f,0);
}

int bfs(int s,int t,int n)
{
	int l,r,i,j;
	for(int i=0; i<n; i++) lay[i]=-1;
	q[l=r=0]=s; lay[s]=0;
	for(; l<=r;)
	{
		i=q[l++];
		for(j=list[i]; j!=-1; j=e[j].n)
		{
			if(lay[e[j].t]<0&&e[j].w>eps)
				lay[e[j].t]=lay[i]+1,q[++r]=e[j].t;
		}
	}
	return lay[t]>=0;
}

double dfs(int now,int t,double now_flow)
{
	double ttl=0,single;
	int i,j;
	if(now==t)
		return now_flow;
	for(i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(lay[to]==lay[now]+1&&e[i].w>eps&&(single=dfs(to,t,min(e[i].w,now_flow-ttl))))
		{
			e[i].w-=single;
			e[i^1].w+=single;
			ttl+=single;
		}
	}
	if(fabs(ttl)<eps)	lay[now]=-1;
	return ttl;
}

double dicnic(int s,int t,int n)
{
	double ret=0;
	while(bfs(s,t,n))
	{
		ret+=dfs(s,t,inf);
	}
	return ret;
}

double get_val(int n,int m,double k)
{
	int f,t;
	top=0;
	for(int i=0; i<n+m+2; i++)
		list[i]=-1;
	for(int i=0; i<m; i++)
	{
		f=es[i].f-1,t=es[i].t-1;
		_insert(n+m,n+i,1);
		_insert(n+i,f,inf);
		_insert(n+i,t,inf);
	}
	for(int i=0; i<n; i++)
		_insert(i,n+m+1,k);
	double x=dicnic(m+n,m+n+1,m+n+2);
	return m-x;
}

void dfs2(int now,int n)
{
	vis[now]=1;
	if(now<n)
		ans[anst++]=now;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		if(e[i].w>eps&&!vis[e[i].t])
			dfs2(e[i].t,n);
	}
}

int cmp(int a,int b){ return a<b; }

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<m; i++)
			scanf("%d%d",&es[i].f,&es[i].t);
		if(m==0)
		{
			printf("1\n1\n");
			continue;
		}
		double l=0.0,r=m,k;
		double nn=1.0/n/n;
		for(; r-l>=nn;)
		{
			k=(l+r)/2;
			if(get_val(n,m,k)>eps)
				l=k;
			else
				r=k;
		}
		get_val(n,m,l);
		memset(vis,0,sizeof(vis));
		anst=0;
		dfs2(n+m,n);
		sort(ans,ans+anst,cmp);
		printf("%d\n",anst);
		for(int i=0; i<anst; i++)
			printf("%d\n",ans[i]+1);
		printf("%lf\n",get_val(n,m,1.5));
	}
	return 0;
}
