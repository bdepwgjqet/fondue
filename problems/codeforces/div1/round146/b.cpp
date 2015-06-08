#include <cstdio>
#define N 100011

double p[N],f[N],dp[N];

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		for(int i=1; i<=n; i++)
			scanf("%lf",&p[i]);
		for(int i=1; i<=n; i++)
		{
			dp[i]=dp[i-1]+(2*f[i-1]+1)*p[i];
			f[i]=(f[i-1]+1)*p[i];
		}
		printf("%.12lf\n",dp[n]);
	}
	return 0;
}
