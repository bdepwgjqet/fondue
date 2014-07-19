/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/23/2012 11:12:59 PM
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

struct edge{ int f,t,n; }e[N];
int dp[N][18],vis[N],id[N],top,list[N],tp,rr[N],ll[N],lay[N];
vector<int> lc[N];

inline int B(int i){ return 1<<i; }

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t,e[top].n=list[f];
	list[f]=top++;
}

void dfs(int now,int l)
{
	vis[now]=1;
	lay[now]=l;
	lc[l].push_back(tp);
	ll[now]=tp;
	id[now]=tp++;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(vis[to]) continue;
		dfs(to,l+1);
	}
	rr[now]=tp-1;
}

int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		for(int i=0; i<=n; i++)
			list[i]=-1,lc[i].clear();
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; i++)
		{
			int x;
			scanf("%d",&x);
			insert(x,i);
			dp[i][0]=x;
		}
		for(int i=1; i<18; i++)
			for(int j=1; j<=n; j++)
			{
				if(dp[j][i-1]==0)
					dp[j][i]=0;
				else
					dp[j][i]=dp[dp[j][i-1]][i-1];
			}
		memset(vis,0,sizeof(vis));
		tp=0;
		dfs(0,0);
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			int x,y,p;
			scanf("%d%d",&x,&y);
			p=x;
			for(int j=0; j<18; j++)
				if(B(j)&y)
					p=dp[p][j];
			if(p==0)
				printf("0 ");
			else
				printf("%d ",upper_bound(lc[lay[x]].begin(),lc[lay[x]].end(),rr[p])-lower_bound(lc[lay[x]].begin(),lc[lay[x]].end(),ll[p])-1);
		}
		puts("");
	}
	return 0;
}
