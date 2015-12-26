#include <cstdio>
#include <cstring>
#define MAXN 200

double win[MAXN][MAXN],dp[MAXN][MAXN];

double solve(int n,int p)
{
	int i,x=1,m,k,j,l,r,ret=0;
	double max;
	memset(dp,0,sizeof(dp));
	for(i=1; i<=p; i++)
		dp[0][i]=1;
	for(i=1; i<=n; i++)
	{
		x<<=1;
		for(j=1; j<=p; j++)
		{
			l=(j-1)/x*x+1;
			r=l+x-1;
	//		printf("%d %d %d %d\n",i,j,l,r);
			m=(l+r)>>1;
			if(j>m)
			{
				for(k=l; k<=m; k++)
					dp[i][j]+=dp[i-1][k]*win[j][k];
			}
			else
			{
				for(k=m+1; k<=r; k++)
					dp[i][j]+=dp[i-1][k]*win[j][k];
			}
			dp[i][j]*=dp[i-1][j];
		}
	}
	for(i=1; i<=p; i++)
	{
	//	printf("%lf ",dp[n][i]);
		if(max<dp[n][i])
			max=dp[n][i],ret=i;
	}
//	puts("");
	return ret;
}

int main()
{
	int n,p,ret,i,j;
	while(scanf("%d",&n)!=EOF)
	{
		if(n<0)	break;
		p=1<<n;
		for(i=1; i<=p; i++)
			for(j=1; j<=p; j++)
				scanf("%lf",&win[i][j]);
		ret=solve(n,p);
		printf("%d\n",ret);
	}
	return 0;
}
