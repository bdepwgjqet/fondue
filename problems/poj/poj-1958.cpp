#include <cstdio>
#include <climits>
#include <algorithm>
#define N 13
#define inf LLONG_MAX
using namespace std;
typedef long long LL;

LL dp[N],three[N];

void init()
{
	dp[1]=1;
	dp[0]=0;
	three[1]=1,three[0]=0;
	for(int i=2; i<N; i++)
		three[i]=three[i-1]*2+1;
	for(int i=2; i<N; i++)
	{
		LL mi=inf;
		for(int j=0; j<i; j++)
			mi=min(2*dp[j]+three[i-j],mi);
		dp[i]=mi;
	}
}

int main()
{
	init();
	int n;
	for(int i=1; i<=12; i++)
		printf("%lld\n",dp[i]);
	return 0;
}
