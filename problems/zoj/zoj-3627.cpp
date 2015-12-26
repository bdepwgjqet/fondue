#include <cstdio>
#include <algorithm>
#define N 100010

typedef long long LL;
using namespace std;

LL dat[N];
LL sum[N],ret;

void cal(int l,int r,int t,int n)
{
	ret=max(ret,sum[r]-sum[l-1]);
	for(int u=0; u<=t; u++)
	{
		if(l-u<1)
			break;
		ret=max(ret,sum[min(n,max(r,r-u+t-u))]-sum[l-u-1]);
	}
	for(int u=0; u<=t; u++)
	{
		if(r+u>n)
			break;
		ret=max(ret,sum[r+u]-sum[max(0,min(l,l-t+u+u-1))]);
	}
}

int main()
{
	int n,p,m,t;
	while(scanf("%d%d",&n,&p)+1)
	{
		for(int i=1; i<=n; i++)
			scanf("%lld",&dat[i]);
		sum[0]=0;
		for(int i=1; i<=n; i++)
			sum[i]=sum[i-1]+dat[i];
		scanf("%d%d",&m,&t);
		if(t<=m/2)
			printf("%lld\n",sum[min(p+t,n)]-sum[max(p-t-1,0)]);
		else
		{
			ret=0;
			if(m&1)
			{
				cal(max(p-m/2-1,1),min(p+m/2,n),t-m/2-1,n);
				cal(max(p-m/2,1),min(p+m/2+1,n),t-m/2-1,n);
			}
			else
				cal(max(p-m/2,1),min(p+m/2,n),t-m/2,n);
			printf("%lld\n",ret);
		}
	}
	return 0;
}
