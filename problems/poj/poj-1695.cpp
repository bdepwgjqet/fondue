#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3fffffff
#define N 35
using namespace std;

int dp[N][N][N],mat[N][N];

int dfs(int now,int p1,int p2,int n)
{
	if(dp[now][p1][p2]>=0)
		return dp[now][p1][p2];
	if(now==n-1)
		return dp[now][p1][p2]=0;
	int ret=inf;
	ret=min(ret,dfs(now+1,p1,p2,n)+mat[now][now+1]);
	ret=min(ret,dfs(now+1,now,p2,n)+mat[p1][now+1]);
	ret=min(ret,dfs(now+1,now,p1,n)+mat[p2][now+1]);
	return dp[now][p1][p2]=ret;
}

int main()
{
	int ts,n;
	scanf("%d",&ts);
	for(int ca=1; ca<=ts; ca++)
	{
		scanf("%d",&n);
		memset(dp,-1,sizeof(dp));
		for(int i=0; i<n; i++)
		{
			for(int j=i+1; j<n; j++)
			{
				scanf("%d",&mat[i][j]);
				mat[j][i]=mat[i][j];
			}
		}
		printf("%d\n",dfs(0,0,0,n));
	}
	return 0;
}
