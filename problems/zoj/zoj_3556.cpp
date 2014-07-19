#include <cstdio>
#define MOD 1000000007 
typedef long long LL;

LL cal(LL a,LL b)
{
	LL ret=1;
	if(a<0) a+=MOD;
	for(; b;)
	{
		if(b&1)
			ret=ret*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ret;
}

int main()
{
	int n,k;
	while(scanf("%d%d",&n,&k)+1)
	{
		printf("%lld\n",cal(cal(2,k)-1,n));
	}
	return 0;
}
