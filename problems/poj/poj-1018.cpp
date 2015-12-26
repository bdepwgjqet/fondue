#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 101
#define inf 0x3ffffff
using namespace std;

int dat[N][N],dp[N][1001];

int main()
{
	int t,n,mx,nmx,m;
	scanf("%d",&t);
	for(; t--;)
	{
		for(int i=0; i<N; i++)
			for(int j=0; j<1001; j++)
				dp[i][j]=inf;
		scanf("%d",&n);
		dp[0][0]=0;
		mx=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&m);
			int b,p,now;
			nmx=mx;
			for(int j=1; j<=m; j++)
			{
				scanf("%d%d",&b,&p);
				for(int k=mx; k>=0; k--)
				{
					if(dp[i-1][k]<inf)
					{
						if(i==1)
							now=b;
						else
							now=min(b,k);
						dp[i][now]=min(dp[i][now],dp[i-1][k]+p);
						nmx=max(nmx,now);
					}
				}
			}
			mx=nmx;
		}
		double ret=0;
		for(int i=1; i<1001; i++)
		{
			if(dp[n][i]<inf)
			{
			//	printf("%d %d\n",dp[n][i],i);
				ret=max(ret,1.0*i/dp[n][i]);
			}
		}
		printf("%.3f\n",ret);
	}
	return 0;
}
