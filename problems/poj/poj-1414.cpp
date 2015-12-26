#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 1000000
#define N 101
using namespace std;

int dat[N][N],vis[N][N];
int n;
int dir[6][2]={{0,-1},{0,1},{1,0},{-1,0},{-1,-1},{1,1}};

int inboard(int i,int j){ return j<=i&&i<=n&&j>=1&&i>=1; }

void dfs(int u,int v,int &cnt,int &tag,int c)
{
	if(dat[u][v]==0)
	{
		tag=1;
		return;
	}
	cnt++;
	vis[u][v]=1;
	for(int i=0; i<6; i++)
	{
		int x=u+dir[i][0],y=v+dir[i][1];
		if(!inboard(x,y))
			continue;
		if(dat[x][y]!=c&&dat[x][y]!=0)
			continue;
		if(vis[x][y])
			continue;
		dfs(x,y,cnt,tag,c);
	}
}

int solve(int u,int v,int c)
{
	int ret=0,tmp,tag;
	dat[u][v]=c;
	memset(vis,0,sizeof(vis));
	for(int i=1; i<=n; i++)
		for(int j=1; j<=i; j++)
		{
			if(dat[i][j]!=0&&!vis[i][j])
			{
				tmp=tag=0;
				dfs(i,j,tmp,tag,dat[i][j]);
				if(tag==1)
					tmp=0;
				if(dat[i][j]==c)
					ret-=tmp;
				else
					ret+=tmp;
			}
		}
	dat[u][v]=0;
	return ret;
}

int main()
{
	int c;
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		if(n==0&&c==0)
			break;
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=i; j++)
				scanf("%d",&dat[i][j]);
		}
		int ret=-inf;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=i; j++)
			{
				if(dat[i][j]==0)
					ret=max(ret,solve(i,j,c));
			}
		printf("%d\n",ret);
	}
	return 0;
}
