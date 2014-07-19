#include <cstdio>
#include <iostream>
#include <algorithm>
#define N 11111
#define MOD 1000000007

using namespace std;
typedef long long LL;

int dat[N];
int cmp(int a,int b){ return a<b; }

LL jie[N];

LL power(LL a,LL b)
{
	LL ret=1;
	for(; b; b>>=1)
	{
		if(b&1)
			ret=ret*a%MOD;
		a=a*a%MOD;
	}
	return ret;
}

LL cal(int a,int b)
{
	return jie[a]*power(jie[b]*jie[a-b]%MOD,MOD-2)%MOD;
}

void init()
{
	jie[0]=1;
	for(int i=1; i<N; i++)
		jie[i]=jie[i-1]*i%MOD;
}

int main()
{
	int n,k,T;
	init();
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d%d",&n,&k);
		for(int i=0; i<n; i++)
			scanf("%d",&dat[i]);
		sort(dat,dat+n,cmp);
		LL ret=0;
		for(int i=k-1; i<n; i++)
		{
			ret=(ret+1LL*dat[i]*cal(i,k-1)%MOD)%MOD;
		}
		cout<<ret<<endl;
	}
	return 0;
}
