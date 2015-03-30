#include <cstdio>
typedef long long LL;

//计算m^a, O(loga),  本身没什么用, 注意这个按位处理的方法  :-P 
LL exponent(LL m,LL a)
{
	LL ret=1;
	for(; a; a>>=1,m*=m)
		if(a&1)
			ret*=m;
	return ret;
}

//计算幂取模a^b mod n, O(logb)
LL modular_exponent(LL a,LL b,LL m)
{
	LL ret=1;
	for(; b; b>>=1,a=(a%m*(a%m))%m)
		if(b&1)
			ret=ret%m*(a%m)%m;
	return ret;
}
