#include <cstdio>
#include <cstring>
#define N 1011
#define MOD 1000000007

char s[N];
int n;
int dp[N][N],sum[N][N];

int solve()
{
	memset(dp,0,sizeof(dp));
	memset(sum,0,sizeof(sum));
	dp[1][1]=1;
	for(int i=1; i<=n; i++)
		sum[1][i]=1;
	for(int i=2; i<=n; i++)
	{
		for(int j=1; j<=i; j++)
		{
			if(s[i-2]=='I')
			{
				dp[i][j]=sum[i-1][j-1];
			}
			else if(s[i-2]=='D')
			{
				dp[i][j]=sum[i-1][i-1]-sum[i-1][j-1];
				if(dp[i][j]<0)
					dp[i][j]+=MOD;
			}
			else
				dp[i][j]=sum[i-1][i-1];
	//		printf("%d %d %d\n",i,j,dp[i][j]);
		}
		for(int j=1; j<=n; j++)
			sum[i][j]=(sum[i][j-1]+dp[i][j])%MOD;
	}
	return sum[n][n];
}

int main()
{
	while(scanf("%s",s)!=EOF)
	{
		n=strlen(s);
		n++;
		printf("%d\n",solve());
	}
	return 0;
}
