#include <cstdio>
#include <vector>
#include <algorithm>
#define inf 0x3fffffff
#define N 410
#define S 160010

using namespace std;

struct edge{ int f,t,n,c; }e[S];

int top,list[N],lay[N],q[S];
int ans[N],atop;

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

int bfs(int f,int t,int n)
{
	int l,r;
	for(int i=0; i<n; i++) lay[i]=-1;
	q[l=r=0]=f;
	lay[f]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=list[now]; i!=-1; i=e[i].n)
		{
			int to=e[i].t;
			if(lay[to]==-1&&e[i].c>0)
				lay[to]=lay[now]+1,q[++r]=to;
		}
	}
	return lay[t]>=0;
}

int dfs(int now,int t,int ttl)
{
	int ret=0;
	if(now==t)
		return ttl;
	for(int i=list[now]; i!=-1&&ttl>ret; i=e[i].n)
	{
		int to=e[i].t;
		if(lay[to]==lay[now]+1&&e[i].c>0)
		{
			int x=dfs(to,t,min(ttl-ret,e[i].c));
			if(x)
			{
				ret+=x;
				e[i].c-=x;
				e[i^1].c+=x;
			}
		}
	}
	if(ret==0) lay[now]=-1;
	return ret;
}

int max_flow(int f,int t,int n)
{
	int ret=0;
	while(bfs(f,t,n))
	{
		ret+=dfs(f,t,inf);
	}
	return ret;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	top=0;
	for(int i=0; i<n+m+2; i++)
		list[i]=-1;
	for(int i=0; i<n; i++)
		insert(n+m,i,1);
	for(int i=n; i<n+m; i++)
		insert(i,n+m+1,2);
	for(int i=0; i<n; i++)
	{
		int u;
		scanf("%d",&u);
		for(int j=0; j<u; j++)
		{
			int x;
			scanf("%d",&x);
			x--;
			insert(i,n+x,1);
		}
	}
	int mf=max_flow(n+m,n+m+1,n+m+2);
	if(mf==m*2)
	{
		puts("YES");
		for(int i=n; i<n+m; i++)
		{
			atop=0;
			for(int j=list[i]; j!=-1; j=e[j].n)
			{
				if(e[j].t!=n+m+1&&e[j].c==1)
					ans[atop++]=e[j].t;
			}
			printf("%d",atop);
			for(int j=0; j<atop; j++)
				printf(" %d",ans[j]+1);
			puts("");
		}
	}
	else
		puts("NO");
	return 0;
}
