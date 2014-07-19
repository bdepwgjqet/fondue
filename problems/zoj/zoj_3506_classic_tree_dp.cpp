#include <cstdio>
#include <algorithm>
#include <vector>
#define inf 0x3fffffff
#define N 1025

using namespace std;

int dp[N][25],val[N],n,k,cnt[N];
vector<int> list[N]; 

int dfs(int now,int p)
{
	cnt[now]=1;
	dp[now][0]=val[now];
	for(size_t i=0; i<list[now].size(); i++)
	{
		int to=list[now][i];
		if(to==p) continue;
		dfs(to,now);
		cnt[now]+=cnt[to];
		for(int u=k; u>=0; u--)
		{
			dp[now][u]+=dp[to][0];
			for(int v=1; v<=u; v++)
			{
				dp[now][u]=min(dp[now][u],dp[to][v]+dp[now][u-v]);
			}
			for(int v=1; v<=cnt[to]&&v<=u; v++)
				dp[now][u]=min(dp[now][u],dp[now][u-v]);
		}
	}
}

int solve()
{
	int ret;
	for(int i=0; i<n; i++)
		fill(dp[i],dp[i]+25,inf);
	dfs(0,-1);
	ret=dp[0][k];
	for(int i=1; i<n; i++)
		for(int j=1; j<=n-cnt[i]&&j<=k; j++)
			ret=min(ret,dp[i][k-j]);
	return ret;
}

int main()
{
	while(scanf("%d%d",&n,&k)+1)
	{
		for(int i=0; i<n; i++)
			list[i].clear();
		for(int i=0; i<n; i++)
			scanf("%d",&val[i]);
		for(int i=0; i<n-1; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			list[x].push_back(y);
			list[y].push_back(x);
		}
		printf("%d ",solve());
		for(int i=0; i<n; i++)
			val[i]=-val[i];
		printf("%d\n",-solve());
	}
	return 0;
}
