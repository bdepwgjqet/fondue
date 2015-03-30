#include <cstdio>

//字典序全排列与序号的转换  求p是所有排列中的第ret个,第一个排列ret为1.
int perm2num(int n,int p[])
{
	int ret=1,k=1,i,j;
	for(i=n-2; i>=0; k*=(n-(i--)))
		for(j=i+1; j<n; j++)
			if(p[j]<p[i])
				ret+=k;
	return ret;
}

