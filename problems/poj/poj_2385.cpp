#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001][31][2];
int n,m,dat[1001];

int dfs(int t,int c,int p)
{
	int ret=0;
	if(dp[t][c][p]>=0)
		return dp[t][c][p];
	if(t==n)
		return dp[t][c][p]=0;
	if(dat[t]==p)
		ret=max(ret,dfs(t+1,c,p)+1);
	else
	{
		if(c>0)
			ret=max(ret,dfs(t+1,c-1,dat[t])+1);
		ret=max(dfs(t+1,c,p),ret);
	}
	return dp[t][c][p]=ret;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d",&dat[i]);
			dat[i]--;
		}
		memset(dp,-1,sizeof(dp));
		printf("%d\n",dfs(0,m,0));
	}
	return 0;
}
