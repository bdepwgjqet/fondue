#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 220
#define inf 0x3ffffff
using namespace std;

int dp[N][N][2],d[N],t[N],n,next[N][N][2];

int dfs(int l,int r,int tag)
{
	int ret=inf,tmp;
	if(dp[l][r][tag]>=0)
		return dp[l][r][tag];
	if(l==r)
		return dp[l][r][tag]=0;
	if(tag==0)
	{
		tmp=dfs(l+1,r,0)+d[l+1]-d[l];
		if(tmp<t[l])
		{
			if(ret>tmp)
			{
				ret=tmp;
				next[l][r][tag]=0;
			}
		}
		tmp=dfs(l,r-1,1)+d[r]-d[l]+d[r]-d[r-1];
		if(tmp-d[r]+d[l]<t[r])
		{
			if(ret>tmp)
			{
				ret=tmp;
				next[l][r][tag]=1;
			}
		}
	}
	else
	{
		tmp=dfs(l+1,r,0)+d[r]-d[l]+d[l+1]-d[l];
		if(tmp-d[r]+d[l]<t[l])
		{
			if(ret>tmp)
			{
				ret=tmp;
				next[l][r][tag]=0;
			}
		}
		tmp=dfs(l,r-1,1)+d[r]-d[r-1];
		if(tmp<t[r])
		{
			if(ret>tmp)
			{
				ret=tmp;
				next[l][r][tag]=1;
			}
		}
	}
	return dp[l][r][tag]=ret;
}

void show(int l,int r,int tag)
{
	if(l==r)
	{
		printf("%d\n",l);
	}
	else
	{
		if(next[l][r][tag]==0)
		{
			printf("%d ",l);
			show(l+1,r,0);
		}
		else
		{
			printf("%d ",r);
			show(l,r-1,1);
		}
	}
}

int main()
{
	int l,r;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&t[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&d[i]);
		memset(dp,-1,sizeof(dp));
		dfs(1,n,0);
		dfs(1,n,1);
		if(dp[1][n][0]>=inf&&dp[1][n][1]>=inf)
			puts("Mission Impossible");
		else
		{
			if(dp[1][n][0]<inf)
				show(1,n,0);
			else
				show(1,n,1);
		}
	}
	return 0;
}
