#include <cstdio>
#include <cstring>
#define N 1000001
typedef long long LL;
int n,m,mod;

LL expmul(LL a,LL b)
{
	LL ret=1;
	for(; b;)
	{
		if(b&1)
			ret=ret*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ret;
}

LL comb(LL a,LL b)
{
	if(a<b) return 0;
	LL ret=1;
	LL up,dn;
	int c=0;
	for(int i=1; i<=b; i++)
	{
		up=a-i+1;
		dn=i;
		for(; up%mod==0;) c++,up/=mod;
		for(; dn%mod==0;) c--,dn/=mod;
		ret=ret*up%mod*expmul(dn,mod-2)%mod;
	}
	if(c>0) return 0;
	return ret;
}

int main()
{
	LL a,b;
	while(scanf("%d%d%d",&n,&m,&mod)!=EOF)
	{
		b=m;
		a=n-(m-1);
		printf("%lld\n",comb(a,b));
	}
	return 0;
}
