#include <cstdio>
#include <cstring>
#define MAXN 510

int rmat[MAXN][MAXN],rs[MAXN][MAXN],cs[MAXN][MAXN],dp[MAXN][MAXN],cmat[MAXN][MAXN],n,m,sum[MAXN][MAXN];

inline int max(int a,int b){ return a<b?b:a; }

int dfs(int now,int last)
{
	int ret=0,t,i,j;
	if(dp[now][last]>=0)	return dp[now][last];
	if(now==m+1)
	{
		/*
		for(i=last+1; i<=n; i++)
			ret+=cs[m][i];
			*/
		ret=sum[m][n]-sum[m][last]-sum[0][n]+sum[0][last];
		return dp[now][last]=ret;
	}
	for(i=last; i<=n; i++)
	{
		t=rs[now][i];
		t+=sum[now-1][i]-sum[now-1][last]-sum[0][i]+sum[0][last];
		/*
		for(j=last+1; j<=i; j++)
			t+=cs[now-1][j];
			*/
		ret=max(ret,t+dfs(now+1,i));
	}
	return dp[now][last]=ret;
}

int main()
{
	int i,j,ret;
	while(scanf("%d%d",&m,&n)&&(m||n))
	{
		memset(cmat,0,sizeof(cmat));
		memset(sum,0,sizeof(sum));
		memset(rmat,0,sizeof(rmat));
		memset(rs,0,sizeof(rs));
		memset(cs,0,sizeof(cs));
		memset(dp,-1,sizeof(dp));
		for(i=1; i<=m; i++)
			for(j=1; j<=n; j++)
				scanf("%d",&rmat[i][j]);
		for(i=1; i<=m; i++)
			for(j=1; j<=n; j++)
				scanf("%d",&cmat[i][j]);
		for(i=1; i<=m; i++)
			for(j=1; j<=n; j++)
			{
				rs[i][j]=rs[i][j-1]+rmat[i][j];
			//	printf("%d ",rs[i][j]);
			}
		for(i=1; i<=m; i++)
			for(j=1; j<=n; j++)
			{
				cs[i][j]=cs[i-1][j]+cmat[i][j];
				sum[i][j]=sum[i-1][j]+sum[i][j-1]+cmat[i][j]-sum[i-1][j-1];
				//printf("%d ",cs[i][j]);
			}
		dfs(1,0);
		printf("%d\n",dp[1][0]);
	}
	return 0;
}
