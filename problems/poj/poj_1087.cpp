/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/11/2012 06:39:03 PM
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
#define M 160010
#define S 1001100
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

struct edge{ int f,t,n,w; }e[S];
int list[N],top,lay[N],q[S],tp;

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
	if(now==t) return now_flow;
	int ttl=0,single;
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

string s;
map<string,int> mp;

int main()
{
	int n,m,k;
	while(scanf("%d",&n)!=EOF)
	{
		top=tp=0;
		for(int i=0; i<N; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
		{
			cin>>s;
			mp[s]=tp++;
		}
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			cin>>s;
			cin>>s;
			int to;
			if(mp.count(s)<=0)
			{
				mp[s]=tp++;
				to=tp-1;
			}
			else
				to=mp[s];
	//		printf("%d ",to);
			_insert(i,m+to,1);
		}
		scanf("%d",&k);
		string a,b;
		for(int i=0; i<k; i++)
		{
			cin>>a>>b;
			int sa,sb;
			if(mp.count(a)<=0)
			{
				mp[a]=tp++;
				sa=tp-1;
			}
			else
				sa=mp[a];
			if(mp.count(b)<=0)
			{
				mp[b]=tp++;
				sb=tp-1;
			}
			else
				sb=mp[b];
			_insert(m+sa,m+sb,inf);
		}
		for(int i=0; i<m; i++)
			_insert(m+tp,i,1);
		for(int i=0; i<n; i++)
			_insert(m+i,m+tp+1,1);
		printf("%d\n",m-dicnic(m+tp,m+tp+1,m+tp+2));
	}
	return 0;
}
