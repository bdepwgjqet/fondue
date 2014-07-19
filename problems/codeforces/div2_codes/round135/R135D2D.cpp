/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/28/2012 12:30:22 AM
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
#define N 200010
#define M 1000010
#define S 600010
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

struct edge{ int f,t,i,n; }e[S];
int vis[N],in[N],list[N],top;

void insert(int f,int t,int i)
{
	e[top].f=f,e[top].t=t,e[top].i=i;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now)
{
	vis[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!vis[to])
		{
			dfs(to);
			if(e[i].i==1)
			{
				in[now]+=in[to];
			}
			else
				in[now]+=in[to]+1;
		}
	}
}

void dfs2(int now)
{
	vis[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!vis[to])
		{
			if(e[i].i==1)
				in[to]=in[now]+1;
			else
				in[to]=in[now]-1;
			dfs2(to);
		}
	}
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		int x,y;
		memset(vis,0,sizeof(vis));
		memset(in,0,sizeof(in));
		memset(vis,0,sizeof(vis));
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n-1; i++)
		{
			scanf("%d%d",&x,&y);
			x--,y--;
			insert(x,y,1);
			insert(y,x,0);
		}
		dfs(0);
		memset(vis,0,sizeof(vis));
		dfs2(0);
		int ret=N;
		for(int i=0; i<n; i++)
			ret=min(ret,in[i]);
		printf("%d\n",ret);
		for(int i=0; i<n; i++)
			if(in[i]==ret)
				printf("%d ",i+1);
		puts("");
	}
	return 0;
}
