/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/14/2012 02:33:12 PM
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
#define N 101000
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

struct edge{ int f,t,l,n; }e[S];
int pcnt[N],ttl[N],dis[N],top,list[N],tpp;
int v[N];

void insert(int f,int t,int l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int l)
{
	v[now]=1;
	dis[now]=l;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!v[to])
		{
			dfs(to,l+e[i].l);
			ttl[now]+=ttl[to];
		}
	}
	ttl[now]+=pcnt[now];
}

int dfs1(int now)
{
	v[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!v[to])
		{
			if(ttl[to]>tpp-ttl[to])
			{
				return dfs1(to);
			}
		}
	}
	return now;
}

LL get_ret(int n)
{
	LL ret=0;
	for(int i=0; i<n; i++)
		ret+=1LL*dis[i]*pcnt[i];
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		top=0,tpp=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		memset(ttl,0,sizeof(ttl));
		memset(dis,0,sizeof(dis));
		for(int i=0; i<n; i++)
		{
			scanf("%d",&pcnt[i]);
			tpp+=pcnt[i];
		}
		for(int i=0; i<n-1; i++)
		{
			int x,y,l;
			scanf("%d%d%d",&x,&y,&l);
			insert(x-1,y-1,l);
			insert(y-1,x-1,l);
		}
		memset(v,0,sizeof(v));
		dfs(0,0);
		memset(v,0,sizeof(v));
		int r=dfs1(0);
		memset(v,0,sizeof(v));
		dfs(r,0);
		cout<<get_ret(n)<<endl;
	}
	return 0;
}
