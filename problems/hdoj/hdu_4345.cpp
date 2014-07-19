#include <cstdio>
#include <cstring>
#define N 1001
typedef long long LL;

int p[N],plist[N],top;
LL dp[N][N];

void init()
{
	top=0;
	for(int i=0; i<N; i++)
		p[i]=i;
	for(int i=2; i<N; i++)
	{
		if(p[i]==i)
			plist[top++]=i;
		for(int j=0; j<top&&plist[j]*i<N; j++)
		{
			p[plist[j]*i]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
}

void solve()
{
	memset(dp,0,sizeof(dp));
	for(int i=0; i<N; i++)
		dp[0][i]=1,dp[i][0]=1,dp[i][1]=1;
	for(int i=1; i<=top; i++)
	{
		for(int j=2; j<N; j++)
			dp[i][j]=dp[i-1][j];
		for(int j=2; j<N; j++)
		{
			int x=plist[i-1],y=x;
			for(; y<=j; y*=x)
			{
				dp[i][j]+=dp[i-1][j-y];
			}
		}
	}
}

int main()
{
	init();
	solve();
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		//printf("%lld\n",dp[top][n]);
		printf("%I64d\n",dp[top][n]);
	}
	return 0;
}
