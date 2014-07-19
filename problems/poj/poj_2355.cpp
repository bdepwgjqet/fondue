#include <cstdio>
#include <algorithm>
#define N 10011
#define inf 0x3ffffffffffLL
typedef long long LL;
using namespace std;

LL dis[N],c[4],l[4],dp[N];

int find(LL x,int ql,int i)
{
	int l=ql,r=i,mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(dis[mid]>=x)
			r=mid-1;
		else
			l=mid+1;
	}
	return l;
}

int main()
{
	int n,ql,qr;
	for(int i=1; i<=3; i++)
		scanf("%lld",&l[i]);
	for(int i=1; i<=3; i++)
		scanf("%lld",&c[i]);
	scanf("%d%d%d",&n,&ql,&qr);
	dis[1]=0;
	for(int i=2; i<=n; i++)
		scanf("%lld",&dis[i]);
	if(ql>=qr)
		swap(ql,qr);
	for(int i=ql+1; i<=qr; i++)
		dp[i]=inf;
	dp[ql]=0;
	for(int i=ql+1; i<=qr; i++)
	{
		for(int j=1; j<=3; j++)
		{
			LL x=dis[i]-l[j];
			int id=find(x,ql,i-1);
	//		printf("%d %d %d\n",i,j,id);
			if(id==i)
				continue;
			dp[i]=min(dp[id]+c[j],dp[i]);
		}
	}
	printf("%lld\n",dp[qr]);
	return 0;
}
