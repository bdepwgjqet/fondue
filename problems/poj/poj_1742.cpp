#include <cstdio>
#include <cstring>
#define N 100011
#define M 1011

int q[N],c[M],w[M];
bool dp[N];

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		if(n==0&&m==0)
			break;
		for(int i=1; i<=n; i++)
			scanf("%d",&w[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&c[i]);
		int l,r,now,mx;
		for(int i=0; i<=m; i++)
			dp[i]=0;
		dp[0]=1;
		for(int i=1; i<=n; i++)
		{
			mx=w[i]*c[i];
			if(c[i]==1)
			{
				for(int j=m-w[i]; j>=0; j--)
					if(dp[j])
						dp[j+w[i]]=1;
			}
			else if(mx<m)
			{
				for(int j=0; j<w[i]; j++)
				{
					l=0,r=-1;
					for(int k=j; k<=m; k+=w[i])
					{
						if(r>=l&&k-q[l]>mx)
							l++;
						if(dp[k])
							q[++r]=k;
						else if(r>=l)
							dp[k]=1;
					}
				}
			}
			else
			{
				for(int j=0; j+w[i]<=m; j++)
					if(dp[j])
						dp[j+w[i]]=1;
			}
		}
		int ret=0;
		for(int i=1; i<=m; i++)
			if(dp[i])
				ret++;
		printf("%d\n",ret);
	}
	return 0;
}
