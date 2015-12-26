#include <cstdio>
#define N 50
typedef long long LL;

LL dp[N],ze[N];

void init()
{
	dp[1]=2,ze[1]=1;
	for(int i=2; i<N; i++)
	{
		dp[i]=dp[i-1]+ze[i-1];
		ze[i]=dp[i-1];
	}
}

int main()
{
	init();
	int n,ca=1,t;
	scanf("%d",&t);
	for(; ca<=t; ca++)
	{
		scanf("%d",&n);
		printf("Scenario #%d:\n",ca);
		printf("%lld\n",dp[n]);
		puts("");
	}
	return 0;
}
