#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff
#define N 200001
using namespace std;

int dp[N][2];

int main()
{
	int n,x;
	while(scanf("%d",&n)!=EOF)
	{
		dp[0][0]=0,dp[0][1]=-inf;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&x);
			dp[i][0]=dp[i-1][0];
			dp[i][0]=max(dp[i-1][1]-x,dp[i][0]);
			dp[i][1]=dp[i-1][1];
			dp[i][1]=max(dp[i-1][0]+x,dp[i][1]);
		//	printf("%d %d\n",dp[i][0],dp[i][1]);
		}
		printf("%d\n",max(dp[n][0],dp[n][1]));
	}
	return 0;
}
