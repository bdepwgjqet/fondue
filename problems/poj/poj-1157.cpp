#include <cstdio>
#include <algorithm>
#define inf 0x3ffffff
#define N 111
using namespace std;

int dp[N][N];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				dp[i][j]=-inf;
		dp[0][0]=0;
		int x;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				scanf("%d",&x);
				for(int k=0; k<j; k++)
				{
					dp[i][j]=max(dp[i][j],dp[i-1][k]+x);
				}
			}
		}
		int ret=-inf;
		for(int i=1; i<=m; i++)
			ret=max(ret,dp[n][i]);
		printf("%d\n",ret);
	}
	return 0;
}
