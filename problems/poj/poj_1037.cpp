#include <cstdio>
#include <cstring>
#define N 30
typedef long long LL;

LL updp[N][N],dndp[N][N],dp[N][N];
int vis[N];

void init()
{
	memset(dp,0,sizeof(dp));
	dp[1][1]=1;
	updp[1][1]=1;
	dndp[1][1]=1;
	updp[2][1]=1;
	dndp[2][2]=1;
	dp[2][1]=dp[2][2]=1;
	for(int i=3; i<N; i++)
	{
		for(int j=1; j<=i; j++)
		{
			for(int k=j+1; k<=i; k++)
				updp[i][j]+=dndp[i-1][k-1];
			for(int k=1; k<j; k++)
				dndp[i][j]+=updp[i-1][k];
			dp[i][j]=updp[i][j]+dndp[i][j];
		}
	}
}

int res[N],top;

void find(int k,int n)
{
	for(int i=1; i<=n; i++)
		if(!vis[i])
		{
			k--;
			if(k==0)
			{
				res[top++]=i;
				vis[i]=1;
				return;
			}
		}
}

int main()
{
	int n,T;
	LL c;
	scanf("%d",&T);
	init();
	while(scanf("%d%lld",&n,&c),T--)
	{
		memset(vis,0,sizeof(vis));
		top=0;
		int pre=0,tag;
		for(int i=1; i<=n; i++)
		{
			if(i<=2)
				tag=0;
			for(int j=1; j<=n-i+1; j++)
			{
				if(i<=2)
					tag=0;
				else if(tag==1&&j>=pre)
					continue;
				else if(tag==-1&&j<pre)
					continue;
				LL now;
				if(i==1)
					now=dp[n-i+1][j];
				else if(j<pre)
					now=updp[n-i+1][j];
				else
					now=dndp[n-i+1][j];
				if(now>=c)
				{
					if(tag==-1||(i==2&&j>=pre))
						tag=1;
					else
						tag=-1;
					pre=j;
					find(j,n);
					break;
				}
				else
					c-=now;
			}
		}
		printf("%d",res[0]);
		for(int i=1; i<top; i++)
			printf(" %d",res[i]);
		puts("");
	}
	return 0;
}
