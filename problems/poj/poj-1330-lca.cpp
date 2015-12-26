/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/17/2012 03:47:33 PM
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
#define N 20010
#define M 1000010
#define S 100010
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

struct edge{ int f,t,n; }e[S];
struct node{ int h,i; }no[N];
int v[N],top,list[N],tp,dp[N][17],in[N],pos[N];

inline int B(int i){ return 1<<i; }
int big(int i,int j){ return no[i].h>no[j].h?i:j; }
int small(int i,int j){ return no[i].h<no[j].h?i:j; }

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int l)
{
	v[now]=1;
	pos[now]=tp;
	no[tp].i=now;
	no[tp++].h=l;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!v[to])
		{
			dfs(to,l+1);
			no[tp].i=now;
			no[tp++].h=l;
		}
	}
}

void RMQ(int n)
{
	int k=int(log(1.0*n)/log(2.0));
	for(int i=1; i<=n; i++)
		dp[i][0]=i;
	for(int j=1; j<=k; j++)
		for(int i=1; i<=n; i++)
		{
			if(i+B(j)-1>n)
				break;
			dp[i][j]=small(dp[i][j-1],dp[i+B(j-1)][j-1]);
		}
}

int query(int l,int r)
{
	int d,k;
	if(l>r) d=l,l=r,r=d;
	d=r-l+1;
	k=int(log(1.0*d)/log(2.0));
	return small(dp[l][k],dp[r-B(k)+1][k]);
}

int main()
{
	int t,n,r;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%d",&n);
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		memset(in,0,sizeof(in));
		for(int i=0; i<n-1; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			insert(x,y);
			insert(y,x);
			in[y]++;
		}
		for(int i=0; i<n; i++)
			if(in[i]==0)
				r=i;
		memset(v,0,sizeof(v));
		tp=1;
		dfs(r,0);
		/*
		for(int i=1; i<tp; i++)
			printf("%d %d=>\n",no[i].i,no[i].h);
		*/
		RMQ(2*n-1);
		int x,y,ret;
		scanf("%d%d",&x,&y);
		ret=query(pos[x-1],pos[y-1]);
		printf("%d\n",no[ret].i+1);
	}
	return 0;
}
