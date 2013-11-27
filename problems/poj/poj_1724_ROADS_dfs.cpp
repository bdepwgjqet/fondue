#include <cstdio>
#include <cstring>
#define inf 100000000
#define MAXN 110
#define MAXS 11000

struct edge{ int f,t,n,l,c; }e[MAXS];
struct node{ int v,l,c; }h_t;

int list[MAXN],top,v[MAXN],K,ret;

int insert(int f,int t,int l,int c)
{
	e[top].f=f,e[top].t=t,e[top].l=l,e[top].c=c;
	e[top].n=list[f],list[f]=top++;
}

void dfs(int now,int n,int fee,int len)
{
	int i;
	if(fee>K)		return;
	if(len>=ret)	return;
	if(now==n-1)
	{
		ret=len;
		return;
	}
	for(i=list[now]; i!=-1; i=e[i].n)
		if(!v[e[i].t])
		{
			v[e[i].t]=1;
			dfs(e[i].t,n,fee+e[i].c,len+e[i].l);
			v[e[i].t]=0;
		}
}

int main()
{
	int n,m,i,j,x,y,l,c;
	while(scanf("%d",&K)!=EOF)
	{
		memset(v,0,sizeof(v));
		scanf("%d%d",&n,&m);
		for(i=0; i<n; i++)	list[i]=-1;
		for(top=i=0; i<m; i++)
		{
			scanf("%d%d%d%d",&x,&y,&l,&c);
			insert(x-1,y-1,l,c);
		}
		ret=inf;
		dfs(0,n,0,0);
		if(ret<inf)
			printf("%d\n",ret);
		else
			puts("-1");
	}
	return 0; 
}
