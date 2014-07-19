#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 0x3fffffff
#define N 201

using namespace std;

int sum[N];
int dp[N][40011][2],dat[N];
int n,a,b;

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	while(scanf("%d%d%d",&n,&a,&b)+1)
	{
		sum[0]=0;
		dat[0]=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			sum[i]=dat[i]+sum[i-1];
		}
		memset(dp,0x3f,sizeof(dp));
		dp[1][dat[1]][0]=0;
		if(b>=dat[1])
			dp[1][0][1]=0;
		for(int i=2; i<=n; i++)
		{
			for(int j=0; j<=a; j++)
			{
				int bb=sum[i]-j;
				if(bb>b)
					continue;
				if(j>=dat[i])
					dp[i][j][0]=min(dp[i-1][j-dat[i]][0],dp[i-1][j-dat[i]][1]+min(dat[i],dat[i-1]));
				dp[i][j][1]=min(dp[i-1][j][0]+min(dat[i],dat[i-1]),dp[i-1][j][1]);
			}
		}
		int ret=inf;
		for(int j=0; j<=a; j++)
			ret=min(ret,min(dp[n][j][0],dp[n][j][1]));
		printf("%d\n",ret>=N*N?-1:ret);
	}
	return 0;
}
