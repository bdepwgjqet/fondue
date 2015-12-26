/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/07/2012 11:29:11 PM
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
#define N 100010
#define M 1000010
#define S 1000100
#define X 18
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

int id[N],top,vis[N],st[N],ID;
vector<int> list[N];
vector<int> tr[N];
int fa[N][X],dp[N][X],cir[N],lay[N];

void dfs(int now,int pre)
{
	vis[now]=1;
	st[++top]=now;
	for(int i=0; i<list[now].size(); i++)
	{
		int to=list[now][i];
		if(to==pre) continue;
		if(id[to]>=0) continue;
		if(vis[to])
		{
			for(; top>=0; )
			{
				int x=st[top];
				id[x]=ID;
				top--;
				if(x==to)
				{
					cir[ID++]=1;
					break;
				}
			}
			continue;
		}
		dfs(to,now);
	}

	if(id[now]==-1)
	{
		id[now]=ID++;
		top--;
	}
}

void dfs1(int now,int pa,int l)
{
	vis[now]=1;
	lay[now]=l;
	for(int i=0; i<tr[now].size(); i++)
	{
		int to=tr[now][i];
		if(vis[to]) continue;
		fa[to][0]=now;
		dp[to][0]=cir[to];
		for(int u=1; u<X; u++)
		{
			int pp=fa[to][u-1];
			fa[to][u]=fa[pp][u-1];
			dp[to][u]=dp[pp][u-1]+dp[to][u-1];
		}
		dfs1(to,now,l+1);
	}
}

inline int B(int i){ return 1<<i; }

int getp(int x,int y)
{
	if(lay[x]<lay[y]) swap(x,y);
	if(lay[x]>lay[y])
	{
		int d=lay[x]-lay[y];
		for(int i=0; i<X; i++)
			if(d&B(i))
				x=fa[x][i];
	}
	if(x!=y)
	{
		for(int i=X-1; i>=0; i--)
			if(fa[x][i]!=fa[y][i])
				x=fa[x][i],y=fa[y][i];
		x=fa[x][0],y=fa[y][0];
	}
	return x;
}

int ppow(LL a,LL b)
{
	LL ret=1;
	for(; b;)
	{
		if(b&1)
			ret=ret*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return int(ret);
}

int get(int x,int p)
{
	int d=lay[x]-lay[p],ret=0;
	for(int i=0; i<X; i++)
		if(B(i)&d)
		{
			ret+=dp[x][i];
			x=fa[x][i];
		}
	return ret;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(cir,0,sizeof(cir));
		for(int i=0; i<n; i++)
			list[i].clear();
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			list[x].push_back(y);
			list[y].push_back(x);
		}
		memset(vis,0,sizeof(vis));
		memset(id,-1,sizeof(id));
		top=-1;
		ID=0;
		dfs(0,-1);
		/*
		for(int i=0; i<n; i++)
			printf("%d %d\n",i+1,id[i]);
			*/

		for(int i=0; i<n; i++)
			tr[i].clear();
		for(int i=0; i<n; i++)
			for(int j=0; j<list[i].size(); j++)
			{
				int to=list[i][j];
				tr[id[i]].push_back(id[to]);
				tr[id[to]].push_back(id[i]);
			}
		memset(fa,0,sizeof(0));
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		dfs1(0,0,1);
		int qs;
		scanf("%d",&qs);
		for(; qs--;)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			x=id[x],y=id[y];
			int p=getp(x,y);
			int cc=get(x,p)+get(y,p)+cir[p];
			printf("%d\n",ppow(2,cc));
		}
	}
	return 0;
}
