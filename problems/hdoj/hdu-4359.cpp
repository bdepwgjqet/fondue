#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#define N 371
#define MOD 1000000007
typedef long long LL;
using namespace std;

LL dp[N][N],sum[N][N],c[N][N];

void init()
{
	memset(dp,0,sizeof(dp));
	memset(c,0,sizeof(c));
	memset(sum,0,sizeof(sum));
	c[0][0]=1;
	for(int i=1; i<N; i++)
	{
		c[i][0]=1;
		for(int j=1; j<i; j++)
			c[i][j]=(c[i-1][j-1]+c[i-1][j])%MOD;
		c[i][i]=1;
	}
	dp[0][0]=1;
	sum[0][0]=1;
	for(int i=1; i<N; i++)
		sum[0][i]=1,sum[1][i]=1;
	dp[1][1]=1;
	sum[1][1]=1;
	LL d;
	for(int i=2; i<N; i++)
	{
		for(int j=2; j<=i; j++)
		{
			dp[i][j]=0;
			for(int k=0; k<i; k++)
			{
				if(k>0&&i-k-1>=1)
					d=c[i-2][i-k-2];
				else
					d=1;
				dp[i][j]=((dp[i][j]+d*((dp[k][j-1]*sum[i-k-1][j-1]%MOD+sum[k][j-1]*dp[i-k-1][j-1]%MOD-dp[k][j-1]*dp[i-k-1][j-1]%MOD)%MOD)%MOD)%MOD+MOD)%MOD;
			}
			dp[i][j]=(i*dp[i][j])%MOD;
			sum[i][j]=(sum[i][j-1]+dp[i][j])%MOD;
		}
		for(int k=i+1; k<N; k++)
			sum[i][k]=sum[i][k-1];
	}
}

int main()
{
	int t,ca=1;
	init();
	scanf("%d",&t);
	int m,n;
	for(; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d%d",&m,&n);
		cout<<dp[m][n]<<endl;
	}
	return 0;
}
