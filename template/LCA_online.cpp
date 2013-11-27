#include <cstdio>
#include <cmath>
#define N 20000
#define S 100000

typedef long long LL;

struct edge{ int f,t,n; }e[S];
struct node{ int h,i; }no[N];
int v[N],top,list[N],tp,dp[N][17],pos[N];

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
