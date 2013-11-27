#include <cstdio>

//求出p的第(t+1)%(n!)个排列,t=0时为第1个排列...p={ 0,1,....n-1 }
void num2perm(int n,int t,int p[])
{
	int i,j;
	for(i=n-1; i>=0; i--)
		p[i]=t%(n-i),t/=n-i;
	for(i=n-1; i>=0; i--)
		for(j=i-1; j>=0; j--)
			if(p[j]<=p[i])
				p[i]++;
}

