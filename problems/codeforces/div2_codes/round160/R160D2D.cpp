#include <cstdio>
#define N 55

double dp[N][N],c[N][N];
int a[N];

void init()
{
	c[0][0]=1;
	for(int i=1; i<N; i++)
	{
		c[i][0]=1;
		for(int j=1; j<i; j++)
			c[i][j]=c[i-1][j]+c[i-1][j-1];
		c[i][i]=1;
	}
}

int main()
{
	int n,p;
	init();
	scanf("%d",&n);
	for(int i=1; i<=n; i++)
		scanf("%d",&a[i]);
	scanf("%d",&p);
	dp[0][0]=1;
	for(int i=1; i<=n; i++)
		for(int k=p; k>=a[i]; k--)
			for(int j=1; j<=i; j++)
				dp[j][k]+=dp[j-1][k-a[i]];
	double ret=0;
	for(int i=1; i<=n; i++)
		for(int j=1; j<=p; j++)
			ret+=dp[i][j]/c[n][i];
	printf("%.12lf\n",ret);
	return 0;
}
