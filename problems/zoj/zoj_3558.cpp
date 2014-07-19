#include <cstdio>
#include <cmath>
#define MOD 100000007
typedef long long LL;
using namespace std;

LL cal(LL l,LL r)
{
	return (l+r)*(r-l+1)/2%MOD;
}

int main()
{
	LL n,sq;
	while(scanf("%lld",&n)!=EOF)
	{
		LL ret=0;
		sq=(int)sqrt(1.0*n);
		for(LL d=1; d<=sq; d++)
		{
			LL ll=n/(d+1)+1,rr=n/d;
			if(rr==n)
				rr--;
			if(ll>rr) continue;
			LL now=((d*(d+1)/2%MOD*cal(ll,rr)%MOD-d*cal(ll,rr)%MOD+d*n%MOD*(rr-ll+1)%MOD-d*d%MOD*cal(ll,rr)%MOD)+MOD)%MOD;
			ret=(ret+now)%MOD;
		}
		for(LL l=1; l<=sq&&l<=n-1; l++)
		{
			LL d=n/l;
			LL now=((d*(d+1)/2%MOD*l-d*l+d*n-d*d%MOD*l)%MOD+MOD)%MOD;
			ret=(ret+now)%MOD;
		}
		LL d=sq;
		LL ll=n/(d+1)+1,rr=n/d;
		for(LL l=ll; l<=sq&&l<=n-1&&l<=rr; l++)
		{
			LL d=n/l;
			LL now=((d*(d+1)/2%MOD*l-d*l+d*n-d*d%MOD*l)%MOD+MOD)%MOD;
			ret=((ret-now)%MOD+MOD)%MOD;
		}
		printf("%lld\n",ret);
	}
	return 0;
}
