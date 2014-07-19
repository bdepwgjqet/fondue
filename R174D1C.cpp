#include <cstdio>
#include <algorithm>
#include <cstring>
#define MOD 1000000007
#define N 303

using namespace std;

int mat[N][N];
int a[N],cnt[N],vis[N],b[N];
int n,q,t;
int dp[100100];

void dfs(int now,int x)
{
	vis[now]=1;
	cnt[now]=0;
	for(int i=0; i<n; i++)
		if(mat[now][i])
		{
			if(!vis[i])
				dfs(i,x+a[now]);
			cnt[now]=max(cnt[now],cnt[i]+1);
		}
}

int gao()
{
	for(int i=0; i<n; i++)
		if(mat[i][i])
			return 0;
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	memset(dp,0,sizeof(dp));
	for(int i=0; i<n; i++)
		if(!vis[i])
		{
			dfs(i,0);
		}
	int ttl=t;
	for(int i=0; i<n; i++)
	{
		ttl-=cnt[i]*a[i];
		if(ttl<0) return 0;
	}
	for(int i=0; i<n; i++)
	{
		b[i]=a[i];
		for(int j=0; j<n; j++)
			if(mat[j][i])
				b[i]+=a[j];
	}
	dp[0]=1;
	for(int i=0; i<n; i++)
		for(int j=b[i]; j<=ttl; j++)
			dp[j]=(dp[j]+dp[j-b[i]])%MOD;
	return dp[ttl];
}

int main()
{
	scanf("%d%d%d",&n,&q,&t);
	for(int i=0; i<n; i++)
		scanf("%d",&a[i]);
	for(int i=0; i<q; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		mat[x][y]=1;
	}
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			for(int k=0; k<n; k++)
				if(mat[j][i]&&mat[i][k])
					mat[j][k]=1;
	printf("%d\n",gao());
	return 0;
}
