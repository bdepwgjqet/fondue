#include <cstdio>
#include <cstring>
#include <algorithm>
using std::sort;
#define inf 0x7ffffffffffffff
#define MAXN 100011
typedef long long LL;

struct edge{ int f,t,n; }e[2*MAXN];
struct data{ int x,y; }dat[10*MAXN];
LL val[MAXN],dp[MAXN],sum,ret;
int v[MAXN],list[MAXN],top;

inline int cmp(data a,data b){ return a.x==b.x?a.y<b.y:a.x<b.x; }
inline LL abs(LL a){ return a<0?-a:a; }

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now)
{
	int i; LL t;
	dp[now]=val[now];
	v[now]=1;
	for(i=list[now]; i!=-1; i=e[i].n)
		if(!v[e[i].t])
		{
			dfs(e[i].t);
			dp[now]+=dp[e[i].t];
			t=abs(sum-2*dp[e[i].t]);
			if(ret>t)	ret=t;
		}
}

int main()
{
	int n,m,ca=1,x,y,i;
	while(scanf("%d%d",&n,&m)&&(n||m))
	{
		memset(v,0,sizeof(v));
		memset(dp,0,sizeof(dp));
		printf("Case %d: ",ca++);
		ret=inf;
		for(top=i=0; i<n; i++)
			list[i]=-1;
		for(sum=i=0; i<n; i++)
		{
			scanf("%lld",&val[i]);
			sum+=val[i];
		}
		for(i=0; i<m; i++)
			scanf("%d%d",&dat[i].x,&dat[i].y);
		sort(dat,dat+m,cmp);
		x=-1,y=-1;
		for(i=0; i<m; i++)
		{
			if(x==dat[i].x&&y==dat[i].y)
				continue;
			x=dat[i].x,y=dat[i].y;
			insert(x-1,y-1);
			insert(y-1,x-1);
		}
		dfs(0);
		/*
		for(i=0; i<n; i++)
			printf("%lld ",dp[i]);
		puts("");
		*/
		printf("%lld\n",ret);
	}
	return 0;
}
