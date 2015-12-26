#include <cstdio>
#include <cstring>
#include <algorithm>
#define MAXN 1010
using std::sort;

struct edge{ int f,t,n; }e[MAXN];
struct node{ int sv,fv,n; }dp[MAXN];

int list[MAXN],top,v[MAXN],out[MAXN];

int cmp(int a,int b)
{
	return (dp[a].fv+2)*dp[b].n<(dp[b].fv+2)*dp[a].n;
}

int insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now)
{
	int i,tp=0,q[MAXN];
	if(out[now]==0)
	{
		dp[now].sv=dp[now].fv=0;
		dp[now].n=1;
	}

	for(i=list[now]; i!=-1; i=e[i].n)
	{
		q[tp++]=e[i].t;
		dfs(e[i].t);
		dp[now].n+=dp[e[i].t].n;
	}
	sort(q,q+tp,cmp);
	for(i=0; i<tp; i++)
	{
		dp[now].sv+=(dp[now].fv+1)*dp[q[i]].n+dp[q[i]].sv;
		dp[now].fv+=dp[q[i]].fv+2;
	}
	if(v[now])	dp[now].fv=0;
}

int main()
{
	int n,x,ret,i; char s[6];
	while(scanf("%d",&n)&&n)
	{
		memset(out,0,sizeof(out));
		for(top=i=0; i<n; i++)	list[i]=-1,dp[i].n=dp[i].sv=dp[i].fv=0;
		for(i=0; i<n; i++)
		{
			scanf("%d%s",&x,s);
			out[x-1]++;
			if(x>=0)
				insert(x-1,i);
			if(s[0]=='N')	v[i]=0;
			else	v[i]=1;
		}
		dfs(0);
		printf("%.4f\n",1.0*dp[0].sv/dp[0].n);
	}
	return 0;
}
