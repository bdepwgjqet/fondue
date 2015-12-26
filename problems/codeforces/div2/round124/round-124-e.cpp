/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/12/2012 08:59:55 PM
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
#define N 1510
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 1e10
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

struct edge{ int f,t,n; }e[N<<1];
struct node{ LL x,y; int i; }no[N];
int top,list[N],cnt[N],vis[N],ret[N];

int cmp(node a,node b)
{
	return a.x*b.y-b.x*a.y>0;
}

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now)
{
	cnt[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(cnt[to])
			continue;
		dfs(to);
		cnt[now]+=cnt[to];
	}
}

void dfs(int now,int l,int r)
{
	if(l>r)
		return;
	vis[now]=1;
	int id=-1,nl;
	LL mi=inf;
	for(int i=l; i<=r; i++)
		if(mi>no[i].y)
			mi=no[i].y,id=i;
	swap(no[id],no[l]);
	for(int i=l+1; i<=r; i++)
		no[i].y-=no[l].y,no[i].x-=no[l].x;
	sort(no+l+1,no+r+1,cmp);
	nl=l+1;
	ret[no[l].i]=now;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(vis[to]) continue;
		dfs(to,nl,nl+cnt[to]-1);
		nl+=cnt[to];
	}
}

int main()
{
	int n,x,y;
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n-1; i++)
		{
			scanf("%d%d",&x,&y);
			x--,y--;
			insert(x,y);
			insert(y,x);
		}
		dfs(0);
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&x,&y);
			no[i].x=x,no[i].y=y,no[i].i=i;
		}
		memset(vis,0,sizeof(vis));
		dfs(0,0,n-1);
		for(int i=0; i<n; i++)
			printf("%d ",ret[i]+1);
		puts("");
	}
	return 0;
}
