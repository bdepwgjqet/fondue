#include <cstdio>
#define N 510

int cnt[10][N][N],dp[10][N][N];
int dx[4]={0,0,1,1};
int dy[4]={0,1,0,1};
char s[N];

inline int B(int i){ return 1<<i; }

int gao(int m,int n)
{
	int ret=0;
	for(int k=1; B(k)<=m&&B(k)<=n; k++)
	{
		for(int i=0; i+B(k)<=m; i++)
			for(int j=0; j+B(k)<=n; j++)
			{
				for(int u=0; u<4; u++)
				{
					int now=cnt[k-1][i+dx[u]*B(k-1)][j+dy[u]*B(k-1)];
					cnt[k][i][j]+=now;
					if(now==B(2*(k-1)))
						dp[k][i][j]+=B(u);
				}
				if(k>1)
				{
					for(int u=0; u<4; u++)
					{
						if((dp[k][i][j]&B(u))==0)
							if(dp[k][i][j]!=dp[k-1][i+dx[u]*B(k-1)][j+dy[u]*B(k-1)])
								dp[k][i][j]=-1;
					}
					if(dp[k][i][j]>=0)
						ret++;
				}
			}
	}
	return ret;
}

int main()
{
	int m,n;
	scanf("%d%d",&m,&n);
	for(int i=0; i<m; i++)
	{
		scanf("%s",s);
		for(int j=0; j<n; j++)
		{
			if(s[j]=='*')
				cnt[0][i][j]=1;
			else
				cnt[0][i][j]=0;
		}
	}
	printf("%d\n",gao(m,n));
	return 0;
}
