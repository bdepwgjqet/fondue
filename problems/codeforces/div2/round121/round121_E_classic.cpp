/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/27/2012 05:59:51 PM
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

struct edge{ int f,t,n; }e[N<<1];
struct node{ int v,l; }no[N];
int list[N],top,dp[N][20],lay[N],id[N],cnt[N],tp,ans[N];

inline int B(int i){ return 1<<i; }
int cmp(node a,node b){ return a.l>b.l; }

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int l,int fa)
{
	dp[now][0]=fa;
	lay[now]=l;
	no[tp].l=l;
	no[tp++].v=now;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(to==fa)
			continue;
		id[to]=i>>1;
		dfs(to,l+1,now);
	}
}

int LCA(int u,int v)
{
	int t,k;
	if(lay[u]<lay[v])
		t=u,u=v,v=t;
	k=lay[u]-lay[v];
	for(int i=0; B(i)<=k; i++)
		if(B(i)&k)
			u=dp[u][i];
	if(u==v) return u;
	for(k=17; dp[u][0]!=dp[v][0]; u=dp[u][k],v=dp[v][k])
		for(; dp[u][k]==dp[v][k]; k--);
	return dp[u][0];
}

int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		top=0,tp=0;
		memset(dp,0,sizeof(dp));
		memset(ans,0,sizeof(ans));
		memset(cnt,0,sizeof(cnt));
		for(int i=0; i<=n; i++)
			list[i]=-1;
		for(int i=0; i<n-1; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			insert(x,y);
			insert(y,x);
		}
		dfs(1,0,0);
		id[1]=n;
		for(int k=1; k<18; k++)
			for(int i=1; i<=n; i++)
			{
				if(dp[i][k-1]==0)
					dp[i][k]=0;
				else
					dp[i][k]=dp[dp[i][k-1]][k-1];
			}
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			cnt[x]++,cnt[y]++;
			cnt[LCA(x,y)]-=2;
		}
		sort(no,no+tp,cmp);
		for(int i=0; i<tp; i++)
		{
			int now=no[i].v;
			cnt[dp[now][0]]+=cnt[now];
		}
		for(int i=2; i<=n; i++)
			ans[id[i]]=cnt[i];
		for(int i=0; i<n-1; i++)
			printf("%d ",ans[i]);
		puts("");
	}
	return 0;
}
