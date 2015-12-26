#include <cstdio>
#include <cstring>
#define N 13
#define MOD 100000000

int mat[N][N],dp[N][N][4100],n,m;

inline int B(int i){ return 1<<i; }

int dfs(int x,int y,int s)
{
	int nextx,nexty,ret=0,t,ss;
	if(dp[x][y][s]>=0)	return dp[x][y][s];
	if(x==n&&y==m)
	{
		if(mat[x-1][y]!=-1&&mat[x][y-1]!=-1&&mat[x][y]!=1)
			return dp[x][y][s]=2;
		return dp[x][y][s]=1;
	}

	if(y==m)
		nextx=x+1,nexty=1;
	else
		nextx=x,nexty=y+1;

	if((mat[x][y]==1)||(mat[x-1][y]==-1||mat[x][y-1]==-1))	
	{
		ss=s;
		ss|=B(y-1);
		ss^=B(y-1);
		ret=dfs(nextx,nexty,ss);
	}
	else
	{
		ss=s;
		ss|=B(y-1);
		mat[x][y]=-1;
		ret=dfs(nextx,nexty,ss);
		mat[x][y]=0;
		ss^=B(y-1);
		ret=(ret+dfs(nextx,nexty,ss))%MOD;
	}
	return dp[x][y][s]=ret;
}

int main()
{
	int i,j,ret;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		memset(mat,0,sizeof(mat));
		for(i=1; i<=n; i++)
			for(j=1; j<=m; j++)
			{
				scanf("%d",&mat[i][j]);
				mat[i][j]=1-mat[i][j];
			}
		ret=dfs(1,1,0);
		printf("%d\n",ret);
	}
	return 0;
}
