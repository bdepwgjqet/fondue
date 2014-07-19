#include <cstdio>
#define N 1001

double dp[N][101];

int main()
{
	int n,c,m;
	while(scanf("%d%d%d",&c,&n,&m)!=EOF)
	{
		dp[0][0]=1;
		for(int i=1; i<=n&&i<N; i++)
		{
			for(int j=0; j<=i&&j<=c; j++)
			{
				dp[i][j]=0;
				if(j-1>=0)
					dp[i][j]+=dp[i-1][j-1]*(c-j+1)/c;
				if(i-1>=j+1&&j+1<=c)
					dp[i][j]+=dp[i-1][j+1]*(j+1)/c;
			}
		}
		double ret=0;
		if(m>c)
			ret=0;
		else
		{
			if(n>=N)
			{
				int x=n-1000;
				if(x&1)
					ret=dp[999][m];
				else
					ret=dp[1000][m];
			}
			else
				ret=dp[n][m];
		}
		printf("%.3f\n",ret);
	}
	return 0;
}
