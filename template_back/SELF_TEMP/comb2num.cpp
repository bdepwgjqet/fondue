//字典序组合与序号的转换  求c是所有组合中的第ret个,第一个组合ret为1.
//c={1,.2,3...n}
#include <cstdio>
typedef long long LL;

LL comb(int n,int m)
{
	LL ret=1; int i=n;
	for(; i>n-m; i--)	ret*=i,ret/=n-i+1;
	return ret;
}

LL comb2num(int n,int m,int c[])
{
	LL ret=comb(n,m); int i,j;
	for(i=0; i<m; i++)
		ret-=comb(n-c[i],m-i);
	return ret;
}

