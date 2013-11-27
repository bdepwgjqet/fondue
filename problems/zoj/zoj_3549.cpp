#include <cstdio>
#define MOD 1000000000000000LL
typedef long long LL;

LL mul(LL a,LL b)
{
	LL ret=0;
	for(; b; b>>=1)
	{
		if(b&1)
			ret=(ret+a)%MOD;
		a=(a+a)%MOD;
	}
	return ret;
}

LL expmul(LL a,LL b)
{
	LL ret=1;
	for(; b; )
	{
		if(b&1)
			ret=mul(ret,a);
		a=mul(a,a);
		b>>=1;
	}
	return ret;
}

int main()
{
	int m,n;
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		LL ret=0;
		for(int i=1; i<=m; i++)
			ret=(ret+expmul(i,n))%MOD;
		int r=0;
		for(; ret%10==0;)
			ret/=10,r++;
		printf("%d\n",r);
	}
	return 0;
}
