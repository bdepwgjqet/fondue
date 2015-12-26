#include <cstdio>
#include <cmath>
#include <cstring>
#define X 1000010
#define MAXN 5010
typedef long long LL;

struct node{ LL x,y,st; }p[MAXN];

int n,dp[X],idd[X];

inline int fly(LL x,int id)
{
	return (p[id].y-p[1].y)*(p[id].y-p[1].y)+(p[id].x-x)*(p[id].x-x)<=p[id].y*p[id].y;
}

inline int min(int a,int b){ return a<b?a:b; }

inline LL cal(int id)
{
	LL ret=p[id].x-(LL)sqrt((p[id].y)*(p[id].y)-(p[id].y-p[1].y)*(p[id].y-p[1].y));
	if(ret<p[1].x)	return p[1].x;
	return ret;
}

int solve()
{
	int ret=MAXN,i,j;
	for(i=0; i<X; i++)	dp[i]=MAXN;
	dp[p[1].x]=0;
	for(i=2; i<=n; i++)
		for(j=p[i].st; j<p[i].x; j++)
		{
			if(2*p[i].x-j>=p[n].x)
				ret=min(ret,dp[j]+1);
			else
				dp[2*p[i].x-j]=min(dp[2*p[i].x-j],dp[j]+1);
		}
	return ret;
}

int main()
{
	int t,i,ret,j;
	scanf("%d",&t);
	for(; t--; )
	{
		scanf("%d",&n);
		for(i=1,j=0; i<=n; i++)
		{
			scanf("%lld%lld",&p[i].x,&p[i].y);
			p[i].st=cal(i);
		}
		ret=solve();
		if(ret>=MAXN)
			puts("-1");
		else
			printf("%d\n",ret);
	}
	return 0;
}
