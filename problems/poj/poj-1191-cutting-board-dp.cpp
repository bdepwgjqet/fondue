#include <cstdio>
#include <cmath>
#include <cstring>
#define inf 1000000000
#define MAXN 10
#define N 8

int mat[MAXN][MAXN],sum[MAXN][MAXN];
int dp[16][MAXN][MAXN][MAXN][MAXN];

inline int min(int a,int b){ return a<b?a:b; }

int main()
{
	int n,i,j,u,v,k,tmp,c; double ave,ret;
	while(scanf("%d",&n)!=EOF)
	{
		ave=0.0;
		memset(sum,0,sizeof(sum));
		for(k=0; k<n; k++)
		for(i=0; i<=N; i++)
		for(j=0; j<=N; j++)
		for(u=0; u<=N; u++)
		for(v=0; v<=N; v++)
			dp[k][i][j][u][v]=inf;
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
			{
				scanf("%d",&mat[i][j]);
				ave+=mat[i][j];
			}
		ave/=n,ave*=ave;
	//	printf("%lf\n",ave);
		for(i=1; i<=N; i++)
			for(j=1; j<=N; j++)
				sum[i][j]=mat[i][j]+sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1];
		for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
		for(u=i; u<=N; u++)
		for(v=j; v<=N; v++)
		{
			tmp=sum[u][v]-sum[u][j-1]-sum[i-1][v]+sum[i-1][j-1];
			dp[0][i][j][u][v]=tmp*tmp;
		}
		for(k=1; k<n; k++)
		for(i=1; i<=N; i++)
		for(j=1; j<=N; j++)
		for(u=i; u<=N; u++)
		for(v=j; v<=N; v++)
		{
			for(c=i; c<u; c++)
			{
				tmp=sum[c][v]-sum[c][j-1]-sum[i-1][v]+sum[i-1][j-1];
				dp[k][i][j][u][v]=min(dp[k][i][j][u][v],dp[k-1][c+1][j][u][v]+tmp*tmp);
				tmp=sum[u][v]-sum[u][j-1]-sum[c][v]+sum[c][j-1];
				dp[k][i][j][u][v]=min(dp[k][i][j][u][v],dp[k-1][i][j][c][v]+tmp*tmp);
			}
			for(c=j; c<v; c++)
			{
				tmp=sum[u][c]-sum[u][j-1]-sum[i-1][c]+sum[i-1][j-1];
				dp[k][i][j][u][v]=min(dp[k][i][j][u][v],dp[k-1][i][c+1][u][v]+tmp*tmp);
				tmp=sum[u][v]-sum[u][c]-sum[i-1][v]+sum[i-1][c];
				dp[k][i][j][u][v]=min(dp[k][i][j][u][v],dp[k-1][i][j][u][c]+tmp*tmp);
			}
		}
		ret=dp[n-1][1][1][8][8];
		ret/=n;
		printf("%.3f\n",sqrt(ret-ave));
	}
	return 0;
}
