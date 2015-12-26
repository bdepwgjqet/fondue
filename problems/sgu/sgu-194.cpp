#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#define inf 0x3fffffff
#define S 100011
#define N 211

using namespace std;

struct edge{ int f,t,n,c; }e[S];

int list[N],top,val[N],ans[S],q[S],lay[N];

void _insert(int f,int t,int c)
{
	e[top].f=f,e[top].t=t,e[top].c=c;
	e[top].n=list[f],list[f]=top++;
}

void insert(int f,int t,int c)
{
	_insert(f,t,c);
	_insert(t,f,0);
}

int bfs(int n,int f,int t)
{
	memset(lay,-1,sizeof(lay));
	int l,r;
	q[l=r=0]=f;
	lay[f]=0;
	for(; l<=r;)
	{
		int nw=q[l++];
		for(int i=list[nw]; i!=-1; i=e[i].n)
		{
			int to=e[i].t;
			if(lay[to]==-1&&e[i].c>0)
				lay[to]=lay[nw]+1,q[++r]=to;
		}
	}
	return lay[t]!=-1;
}

int dfs(int now,int t,int ttl)
{
	int ret=0;
	if(now==t) return ttl;
	for(int i=list[now]; i!=-1&&ttl>ret; i=e[i].n)
	{
		int to=e[i].t;
		if(lay[to]==lay[now]+1&&e[i].c>0)
		{
			int x=dfs(to,t,min(ttl-ret,e[i].c));
			ret+=x;
			e[i].c-=x;
			e[i^1].c+=x;
			ans[i]+=x;
			ans[i^1]-=x;
		}
	}
	if(ret==0) lay[now]=-1;
	return ret;
}

int max_flow(int n,int f,int t)
{
	int ret=0;
	while(bfs(n,f,t))
	{
		ret+=dfs(f,t,inf);
	}
	return ret;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)+1)
	{
		top=0;
		memset(val,0,sizeof(val));
		for(int i=0; i<n+2; i++)
			list[i]=-1;
		for(int i=0; i<m; i++)
		{
			int x,y,l,r;
			scanf("%d%d%d%d",&x,&y,&l,&r);
			x--,y--;
			val[y]+=l;
			val[x]-=l;
			ans[i<<1]=l;
			insert(x,y,r-l);
		}
		int ttl=0;
		for(int i=0; i<n; i++)
		{
			if(val[i]>0)
			{
				insert(n,i,val[i]);
				ttl+=val[i];
			}
			else if(val[i]<0)
				insert(i,n+1,-val[i]);
		}
		int mf=max_flow(n+2,n,n+1);
		if(ttl==mf)
		{
			puts("YES");
			for(int i=0; i<m; i++)
				printf("%d\n",ans[i<<1]);
		}
		else
			puts("NO");
	}
	return 0;
}
