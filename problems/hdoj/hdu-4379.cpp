#include <cstdio>
#include <algorithm>
typedef long long LL;
int n;
LL a,b,l,mod;
using namespace std;

int solve()
{
	LL now=b,mx1=0,mx2=0,ant;
	int ret=0;
	for(int i=0; i<n; i++)
	{
		now=(a+now)%mod;
		if(now<=l)
		{
			mx1=max(mx1,now);
			ret++;
		}
	}
	ant=2*l-mx1;
	now=b;
	for(int i=0; i<n; i++)
	{
		now=(a+now)%mod;
		if(now<=ant)
			mx2=max(mx2,now);
	}
	if(mx2>l)
		return ret+1;
	return ret;
}

int main()
{
	int aa,bb,ll,mm;
	while(scanf("%d%d%d%d%d",&n,&ll,&aa,&bb,&mm)!=EOF)
	{
		a=aa<<1,b=bb<<1,mod=mm<<1,l=ll;
		if(mod-1<=l)
			printf("%d\n",n);
		else
		{
			printf("%d\n",solve());
		}
	}
	return 0;
}
