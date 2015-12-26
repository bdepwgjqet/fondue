#include <cstdio>
#define inf 1e8

int main()
{
	int n,p,q,ca=1;
	double ret,now,ttl;
	while(scanf("%d%d%d",&n,&p,&q)!=EOF)
	{
		printf("Case %d: ",ca++);
		ret=0;
		ttl=1;
		now=1;
		for(int i=q+1; i<=n-p+q; i++)
		{
			now/=n-i+1;
			now*=i;
			now*=n-i-p+q+1;
			ret+=now;
			now/=i-q;
			ttl+=now;
			for(; ttl>inf||ret>inf||now>inf; )
				ttl/=inf,ret/=inf,now/=inf;
		}
		ret*=1.0/(n-p);
		ret=ret/ttl;
		printf("%.4lf\n",ret);
	}
	return 0;
}
