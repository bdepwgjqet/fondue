#include <cstdio>
#include <cstring>
#define N 110
#define K 210

struct edge{ int f,t,n; }e[2*N];
int n,k,vis[N],val[N],list[N],top,dp[N][K],back[N][K];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

inline int max(int a,int b){ return a<b?b:a; }

void dfs(int now)
{
	int i,u,v;
	vis[now]=1;
	for(i=0; i<=k; i++)
		dp[now][i]=back[now][i]=val[now];
	for(i=list[now]; i!=-1; i=e[i].n)
		if(!vis[e[i].t])
		{
			dfs(e[i].t);
			for(u=k-1; u>=0; u--)
				for(v=0; v<=u; v++)
				{
					back[now][u+2]=max(back[now][u+2],back[e[i].t][v]+back[now][u-v]);
					dp[now][u+2]=max(dp[now][u+2],back[e[i].t][v]+dp[now][u-v]);
					dp[now][u+1]=max(dp[now][u+1],dp[e[i].t][v]+back[now][u-v]);
				}
		}
}

int main()
{
	int i,x,y;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(vis,0,sizeof(vis));
		memset(dp,0,sizeof(dp));
		memset(back,0,sizeof(back));
		for(top=i=0; i<n; i++)
			list[i]=-1;
		for(i=0; i<n; i++)
			scanf("%d",&val[i]);
		for(i=0; i<n-1; i++)
		{
			scanf("%d%d",&x,&y);
			insert(x-1,y-1);
			insert(y-1,x-1);
		}
		dfs(0);
		printf("%d\n",dp[0][k]);
	}
	return 0;
}
