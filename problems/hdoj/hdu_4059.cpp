#include <cstdio>
#define N 30000
#define MOD 1000000007
typedef long long LL;

int top,plist[N],p[N],ntop,list[N];
LL res;

void init()
{
	top=0;
	for(int i=0; i<N; i++)
		p[i]=i;
	for(int i=2; i<N; i++)
	{
		if(p[i]==i) plist[top++]=i;
		for(int j=0; j<top&&plist[j]*i<N; j++)
		{
			p[i*plist[j]]=plist[j];
			if(i%plist[j]==0)
				break;
		}
	}
}

LL expow(LL a,LL b)
{
	LL ret=1;
	for(; b;)
	{
		if(b&1)
			ret=ret*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return ret;
}

LL get(LL n)
{
	LL ret,tmp;
	ret=n*(n+1)%MOD;
	ret=ret*(2*n+1)%MOD;
	tmp=(3*n*n+3*n-1)%MOD;
	ret=ret*tmp%MOD;
	return ret*expow(30,MOD-2)%MOD;
}

void div(int n)
{
	ntop=0;
	for(int i=0; i<top; i++)
	{
		if(plist[i]*plist[i]>n)
			break;
		if(n%plist[i]==0)
		{
			list[ntop++]=plist[i];
			for(; n%plist[i]==0; )
				n/=plist[i];
		}
	}
	if(n>1)
		list[ntop++]=n;
}

LL four(int x)
{
	LL ret=x;
	ret=ret*x%MOD;
	ret=ret*x%MOD;
	return ret*x%MOD;
}

void dfs(int lay,int cnt,int now,int n)
{
	if(lay==ntop)
	{
		if(cnt&1)
		{
			res=((res-four(now)*get(n/now)%MOD)%MOD+MOD)%MOD;
		}
		else
		{
			res=((res+four(now)*get(n/now)%MOD)%MOD+MOD)%MOD;
		}
		return;
	}
	dfs(lay+1,cnt,now,n);
	dfs(lay+1,cnt+1,now*list[lay],n);
}

int main()
{
	init();
	int t,n;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		div(n);
		res=0;
		dfs(0,0,1,n);
//		printf("%lld\n",res);
		printf("%I64d\n",res);
	}
	return 0;
}
