#include <cstdio>
#define N 100011

double dp[N];

int main()
{
	int ts,n;
	double p;
	scanf("%d",&ts);
	for(; ts--;)
	{
		scanf("%d%lf",&n,&p);
		dp[0]=0;
		for(int i=1; i<n; i++)
		{
			dp[i]=dp[i-1]+(1.0*n*(n-1)/2.0)/(1.0*i*(n-i)*p);
		}
		printf("%.3lf\n",dp[n-1]);
	}
	return 0;
}
