#include <cstdio>
#include <iostream>
#include <cstring>
#define MOD 1000000007
#define N 10001
typedef long long LL;
using namespace std;

LL dp[101][N],c[N][101];

void init()
{
	c[0][0]=1;
	for(int i=1; i<N; i++)
	{
		c[i][0]=1;
		for(int j=1; j<101&&j<i; j++)
		{
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
		}
		if(i<101)
			c[i][i]=1;
	}
}

int main()
{
	int n,ca=1;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		printf("Case %d: ",ca++);
		int m,ttl;
		memset(dp,0,sizeof(dp));
		for(int i=0; i<=n; i++)
			dp[i][0]=1;
		LL ret=0;
		ttl=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&m);
			ttl+=m;
			for(int j=1; j<=ttl; j++)
			{
				for(int k=0; k<=j&&k<=m; k++)
					dp[i][j]=(dp[i][j]+dp[i-1][j-k]*c[j][k]%MOD)%MOD;
				if(i==n)
					ret=(ret+dp[i][j])%MOD;
			}
		}
		cout<<ret<<endl;
	}
	return 0;
}
