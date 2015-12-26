#include <cstdio>
#include <cstring>
#define N 21

int vis,top,q[N],nvis,dp[1<<19];
inline int B(int i){ return 1<<(i-2); }

void get_next(int vis,int &nvis,int x)
{
	nvis=vis;
	nvis-=B(x);
	for(int i=x+1; i<N; i++)
		if(nvis&B(i))
		{
			for(int j=2; j<i&&i-j>=2; j++)
			{
				if(((nvis&B(j))==0)&&((nvis&B(i-j))==0))
				{
					nvis-=B(i);
					break;
				}
			}
		}
}

int dfs(int v)
{
	int nv;
	if(dp[v]>=0)
		return dp[v];
	for(int i=2; i<N; i++)
		if(v&B(i))
		{
			get_next(v,nv,i);
			if(dfs(nv)==0)
				return dp[v]=1;
		}
	return dp[v]=0;
}

int main()
{
	int ca=1,n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		printf("Test Case #%d\n",ca++);
		top=0;
		vis=0;
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			vis+=B(x);
		}
		memset(dp,-1,sizeof(dp));
		for(int i=2; i<N; i++)
		{
			if(vis&B(i))
			{
				get_next(vis,nvis,i);
				if(dfs(nvis)==0)
					q[top++]=i;
			}
		}
		if(top==0)
			puts("There's no winning move.\n");
		else
		{
			printf("The winning moves are:"); 
			for(int i=0; i<top; i++)
				printf(" %d",q[i]);
			puts("\n");
		}
	}
	return 0;
}
