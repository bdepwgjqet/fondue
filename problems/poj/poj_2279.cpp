#include <cstdio>
#include <cstring>
#define N 32
typedef long long LL;

int dat[N],cnt[N];

LL gcd(LL a,LL b){ return b?gcd(b,a%b):a; }

int main()
{
	int n,sum;
	while(scanf("%d",&n)!=EOF)
	{
		memset(cnt,0,sizeof(cnt));
		if(n==0)
			break;
		sum=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			sum+=dat[i];
		}
		int tmp;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=dat[i]; j++)
			{
				tmp=dat[i]-j;
				for(int k=i+1; k<=n; k++)
					if(dat[k]>=j)
						tmp++;
				tmp++;
				cnt[tmp]++;
			}
		}
		LL zi=1,mu=1,g;
		for(int i=2; i<=sum; i++)
		{
			zi*=i;
			for(int j=0; j<cnt[i]; j++)
				mu*=i;
			g=gcd(zi,mu);
			zi/=g,mu/=g;
		}
		printf("%lld\n",zi);
	}
	return 0;
}
