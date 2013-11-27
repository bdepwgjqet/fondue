#include <cstdio>
#include <cstring>
#include <vector>
#define N 111

using namespace std;

vector<int> list[N];
int val[N],ti[N][N];
int dp[N][N<<1];
int m,n;

void dfs(int now,int p)
{
	for(size_t i=0; i<list[now].size(); i++)
	{
		int to=list[now][i];
		if(to==p)
			continue;
		dfs(to,now);
		for(int u=m; u>=ti[now][to]; u--)
		{
			for(int v=0; v<=u-ti[now][to]; v++)
			{
				dp[now][u]=max(dp[now][u],dp[to][v]+dp[now][u-v-ti[now][to]]);
			}
		}
	}
}

int main()
{
	while(scanf("%d",&n)+1)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d",&val[i]);
			list[i].clear();
		}
		for(int i=0; i<n-1; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x--,y--;
			list[x].push_back(y);
			list[y].push_back(x);
			ti[x][y]=ti[y][x]=z;
		}
		int k;
		scanf("%d%d",&k,&m);
		m/=2;
		k--;
		memset(dp,0,sizeof(dp));
		for(int i=0; i<n; i++)
			for(int j=0; j<=m; j++)
				dp[i][j]=val[i];
		dfs(k,-1);
		int ret=0;
		for(int i=0; i<=m; i++)
			ret=max(ret,dp[k][i]);
		printf("%d\n",ret);
	}
	return 0;
}
