#include <cstdio>
#define MOD 1000000
#define N 100011
typedef long long LL;

int id[N],cnt[4];
LL two[N],f[N];

void init()
{
	two[0]=1;
	for(int i=1; i<N; i++)
		two[i]=two[i-1]*2%MOD;
	f[0]=0;
	for(int i=1; i<N; i++)
	{
		f[i]=two[i]-1;
		if(f[i]<0) f[i]+=MOD;
	}
}

int cal(int a,int b)
{
	if(a!=1&&b!=1)
		return 1;
	if(a!=2&&b!=2)
		return 2;
	return 3;
}

int main()
{
	int n;
	init();
	while(scanf("%d",&n)+1)
	{
		for(int i=1; i<=3; i++)
			scanf("%d",&cnt[i]);
		for(int i=1; i<=3; i++)
			for(int j=1; j<=cnt[i]; j++)
			{
				int x;
				scanf("%d",&x);
				id[x]=i;
			}
		int pre=id[n],now;
		printf("%d\n",pre);
		LL ret=0;
		for(int i=n-1; i>=1; i--)
		{
			now=id[i];
			if(pre==now)
				continue;
			ret=(ret+f[i-1]+1)%MOD;
			pre=cal(pre,now);
		}
		printf("%lld\n",ret);
	}
	return 0;
}
