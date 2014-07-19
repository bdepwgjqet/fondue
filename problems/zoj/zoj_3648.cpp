#include <cstdio>
#include <cstring>
#define N 110

typedef long long LL;

LL dp[N][N],f[N][N];

void init()
{
	memset(dp,0,sizeof(dp));
	memset(f,0,sizeof(f));
	for(int i=2; i<N; i++)
		for(int j=2; j<N; j++)
		{
			for(int p=1; p<=i; p++)
			{
				int l=1,r=j;
				l=(i*p-p*p)/j;
				for(; l*j<=(i*p-p*p); )
					l++;
				int c=0;
				for(int q=l; q<=r; q++)
				{
					if(p==i&&q==j) continue;
					if(q*q+i*p>j*q)
						c++;
				}
				dp[i][j]+=c;
				if(p==i)
					f[i][j]=c;
			}
		}
}

int main()
{
	init();
	int m,n;
	while(scanf("%d%d",&m,&n)+1)
	{
		LL ret=0;
		for(int i=2; i<=m; i++)
			for(int j=2; j<=n; j++)
				ret+=(((dp[i][j]+dp[j][i])<<1)-((f[i][j]+f[j][i])<<1))*(m-i+1)*(n-j+1);
		printf("%lld\n",ret);
	}
	return 0;
}
