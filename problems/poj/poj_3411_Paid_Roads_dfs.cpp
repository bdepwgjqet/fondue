#include <cstdio>
#define inf 100000000
#define MAXN 20
#define MAXS 200

struct edge{ int f,t,c,p,r,n,v; }e[MAXS];

int list[MAXN],top,min[MAXN],n,v[MAXN],ret;

inline int B(int x){ return 1<<x; }

void insert(int f,int t,int c,int p,int r)
{
	e[top].f=f,e[top].t=t,e[top].c=c;
	e[top].p=p,e[top].r=r,e[top].v=0;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int s,int cost)
{
	if(cost>=ret)	return;
	if(now==n-1)
	{
		ret=cost;
		return;
	}

	int i,f;
	s^=B(now);
	for(i=list[now]; i!=-1; i=e[i].n)
		if(e[i].v<=2)
		{
			e[i].v++;
			
			if((B(e[i].c)&s)>0&&e[i].c!=now)
				f=e[i].p;
			else
				f=e[i].r;
			dfs(e[i].t,s,cost+f);
			e[i].v--;
		}
	s^=B(now);
}

int main()
{
	int m,a,b,c,p,r,i;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(top=i=0; i<n; i++)
			list[i]=-1,v[i]=0;
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d%d%d",&a,&b,&c,&p,&r);
			insert(a-1,b-1,c-1,p,r);
		}
		ret=inf;
		dfs(0,0,0);
		
		if(ret!=inf)
			printf("%d\n",ret);
		else
			puts("impossible");
	}
	return 0;
}

