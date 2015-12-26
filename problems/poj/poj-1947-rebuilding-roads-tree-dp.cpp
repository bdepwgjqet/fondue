#include <cstdio>
#include <cstring>
#define inf 300
#define MAXN 160
#define MAXS 200

struct edge{ int f,t,n; }e[MAXS];

int list[MAXN],top,dp[MAXN][MAXN],n,p,in[MAXN];

inline int min(int a,int b){ return a<b?a:b; }

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now)
{
	int i,u,v,cnt;
	for(cnt=0,i=list[now]; i!=-1; i=e[i].n,cnt++)
		dfs(e[i].t);
	
	dp[now][1]=cnt;

	for(i=list[now]; i!=-1; i=e[i].n)
	{
		for(u=p; u>=1; u--)
		{
			if(dp[now][u]==inf)	continue;
			for(v=1; v+u<=p; v++)
			{
				dp[now][u+v]=min(dp[now][u+v],dp[now][u]+dp[e[i].t][v]-1);
			}
		}
	}
}

int main()
{
	int i,x,y,j,root,ret;
	while(scanf("%d%d",&n,&p)!=EOF)
	{
		memset(in,0,sizeof(in));
		for(top=i=0; i<=n; i++)
		{
			list[i]=-1;
			for(j=0; j<=n; j++)
				dp[i][j]=inf;
		}
		for(i=0; i<n-1; i++)
		{
			scanf("%d%d",&x,&y);
			insert(x-1,y-1);
			in[y-1]++;
		}
		for(i=0; i<n; i++)
			if(in[i]==0)
			{
				root=i;
				break;
			}
		dfs(root);
		for(ret=inf,i=1; i<n; i++)
			ret=min(ret,dp[i][p]+1);
		ret=min(ret,dp[0][p]);
		printf("%d\n",ret);
	}
	return 0;
}
