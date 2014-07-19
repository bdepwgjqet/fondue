#include <cstdio>
#include <cstring>
#define N 13
typedef long long LL;

LL dp[N][N][N];

void init()
{
	memset(dp,0,sizeof(dp));
	for(int i=0; i<N; i++)
		dp[1][i][i]=1;
	for(int i=0; i<N; i++)
		dp[i][0][0]=1;
	for(int i=2; i<N; i++)
		for(int j=1; j<N; j++)
		{
			for(int k=0; k<=j; k++)
				for(int u=0; u<=k; u++)
				{
					dp[i][j][k]+=dp[i-1][j-k][u];
				}
		}
}

int main()
{
	int m,n,t;
	init();
	scanf("%d",&t);
	while(scanf("%d%d",&m,&n)!=EOF,t--)
	{
		LL ret=0;
		for(int i=0; i<=m; i++)
			ret+=dp[n][m][i];
		printf("%lld\n",ret);
	}
	return 0;
}
