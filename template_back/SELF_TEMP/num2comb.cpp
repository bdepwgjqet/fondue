#include <cstdio>
typedef long long LL;

LL comb(int n,int m)
{
	LL ret=1; int i=n;
	for(; i>n-m; i--)	ret*=i,ret/=n-i+1;
	return ret;
}

//求出c的第t个组合,t=1时为第1个排列...c={ 1,2,3....n }
void num2comb(int n,int m,LL t,int c[])
{
	int i,j=1,p;
	for(i=0; i<m; c[i++]=j++)
		for(; t>(p=comb(n-j,m-i-1)); t-=p,j++);
}

