#include <cstdio>
#include <iostream>
#include <algorithm>

typedef long long LL;
using namespace std;

int get(int n){ return n*(n-1)/2; }

LL gao(int m,int n,int k)
{
	LL ret=0;
	for(int i=2; i<=m; i++)
	{
		if(k-i*n>=n) continue;
		int a=k/i,b=k%i;
		for(int j=min(a,n); j>=2; j--)
		{
			int le=k-i*j;
			if(le>=j)
				break;
			if(i+1<=m||le==0)
				ret=max(ret,1LL*get(i)*get(j)+1LL*get(le)*i);
			else break;
		//	cout<<ret<<" "<<i<<" "<<j<<" "<<le<<endl;
		}
	}
	return ret;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		printf("Case #%d: ",ca);
		int m,n,k;
		scanf("%d%d%d",&m,&n,&k);
		LL ret=0;
		ret=max(ret,gao(m,n,k));
		ret=max(ret,gao(n,m,k));
		cout<<ret<<endl;
	}
	return 0;
}
