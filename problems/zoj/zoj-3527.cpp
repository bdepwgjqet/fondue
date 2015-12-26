#include <cstdio>
#include <cstring>
#include <vector>
#define N 100100

typedef long long LL;
using namespace std;

struct node{ int a,b,p; }no[N];
struct edge{ int f,t,n; }e[N<<1];
int vis[N],ring[N],ok,T,rt,ri,top,list[N];
LL dp[N][2][2];
int n;

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now)
{
	vis[now]=T;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(vis[to]==T)
		{
			ok=1;
			ring[now]=1;
			return ;
		}
		if(vis[to]) continue;
		dfs(to);
		if(ok) 
		{
			ring[now]=1;
			return;
		}
	}
}

LL gao(int now,int pre,int p,int len)
{
	if(len>100000) for(;;);
	if(dp[now][pre][p]>=0)
		return dp[now][pre][p];
	LL ret=0,add=0;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		if(e[i].t==rt) continue;
		add+=gao(e[i].t,0,p,len+1);
	}
	ret=max(ret,add);
	add=no[now].a;
	if(p>0&&now==ri)
		add+=no[rt].b;
	if(pre)
		add+=no[now].b;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		if(e[i].t==rt) continue;
		add+=gao(e[i].t,1,p==0?now==rt:p,len+1);
	}
	ret=max(ret,add);
	return dp[now][pre][p]=ret;
}

void fill(int now)
{
	vis[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!vis[to])
			fill(to);
	}
}

int main()
{
	while(scanf("%d",&n)+1)
	{
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d%d",&no[i].a,&no[i].b,&no[i].p);
			no[i].p--;
			insert(no[i].p,i);
		}
		memset(vis,0,sizeof(vis));
		memset(ring,0,sizeof(ring));
		T=1;
		for(int i=0; i<n; i++,T++)
			if(!vis[i])
			{
				ok=0;
				dfs(i);
			}
		memset(vis,0,sizeof(vis));
		memset(dp,-1,sizeof(dp));
		LL ret=0;
		for(int i=0; i<n; i++)
		{
			if((!vis[i])&&ring[i])
			{
				rt=i,ri=no[i].p;
				ret+=gao(i,0,0,0);
				fill(i);
			}
		}
		printf("%lld\n",ret);
	}
	return 0;
}
