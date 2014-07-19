#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 555
#define inf 0x3ffffffffffffLL
typedef long long LL;
using namespace std;

LL mat[N][N],dp[N][N][3];
int m,n,dir[N][N][3],len[N][N][3];

LL dfs(int r,int c,int d,int &prel)
{
	LL ret=inf,tmp;
	int now,bd,nowl=0;
	if(dp[r][c][d]>=0)
		return dp[r][c][d];
	if(r==m)
		return dp[r][c][d]=0,prel=1;
	if(c>1&&d!=0)
	{
		tmp=dfs(r,c-1,2,nowl)+mat[r][c-1];
		if(ret>tmp)
			ret=tmp,bd=0,prel=nowl+1;
	}
	if(c<n&&d!=2)
	{
		tmp=dfs(r,c+1,0,nowl)+mat[r][c+1];
		if(ret>tmp)
			ret=tmp,bd=2,prel=nowl+1;
		else if(ret==tmp)
		{
			if(prel>nowl+1)
				ret=tmp,bd=2,prel=nowl+1;
		}
	}
	tmp=dfs(r+1,c,1,nowl)+mat[r+1][c];
	if(ret>tmp)
		ret=tmp,bd=1,prel=nowl+1;
	else if(ret==tmp)
	{
		if(prel>nowl+1)
			ret=tmp,bd=1,prel=nowl+1;
	}
	dir[r][c][d]=bd;
	return dp[r][c][d]=ret;
}

void show(int r,int c,int d)
{
	if(r==m)
		return;
	int nr,nc,nd,bd=dir[r][c][d];
	if(bd==0)
		nr=r,nc=c-1,nd=2;
	else if(bd==2)
		nr=r,nc=c+1,nd=0;
	else
		nr=r+1,nc=c,nd=1;
	if(nr>=1)
	{
		printf("%d\n",nc);
	}
	show(nr,nc,nd);
}

int main()
{
	memset(mat,0,sizeof(mat));
	while(scanf("%d%d",&m,&n)!=EOF)
	{
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				scanf("%lld",&mat[i][j]);
		memset(dp,-1,sizeof(dp));
		int nowl;
		dfs(0,1,0,nowl);
		show(0,1,0);
	}
	return 0;
}
