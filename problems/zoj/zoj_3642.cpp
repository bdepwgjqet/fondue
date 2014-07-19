#include <cstdio>
#include <map>
#define inf 0x3fffffff
#define N 100001

using namespace std;

struct edge{ int f,t,n,w; }e[N];

int top,list[500];

void _insert(int f,int t,int w)
{
	e[top].f=f,e[top].t=t,e[top].w=w;
	e[top].n=list[f],list[f]=top++;
}

void insert(int f,int t,int w)
{
	_insert(f,t,w);
	_insert(t,f,0);
}

map<int,int> id;
int ids,up[300],lay[500],q[N];

int bfs(int f,int t,int n)
{
	int l,r;
	for(int i=0; i<n; i++)
		lay[i]=-1;
	q[l=r=0]=f;
	lay[f]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=list[now]; i!=-1; i=e[i].n)
		{
			int to=e[i].t;
			if(lay[to]==-1&&e[i].w>0)
				lay[to]=lay[now]+1,q[++r]=to;
		}
	}
	return lay[t]>=0;
}

int dfs(int now,int t,int now_flow)
{
	int ret=0;
	if(now==t) return now_flow;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		if(ret>=now_flow)
			break;
		int to=e[i].t,x;
		if(lay[to]==lay[now]+1&&e[i].w>0)
		{
			x=dfs(to,t,min(now_flow-ret,e[i].w));
			ret+=x;
			e[i].w-=x;
			e[i^1].w+=x;
		}
	}
	if(ret==0) lay[now]=-1;
	return ret;
}

int max_flow(int f,int t,int n)
{
	int ret=0;
	while(bfs(f,t,n))
		ret+=dfs(f,t,inf);
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		ids=n;
		id.clear();
		for(int i=0; i<500; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
		{
			int m,l,r,x,y;
			scanf("%d%d%d",&m,&l,&up[i]);
			for(int j=0; j<m; j++)
			{
				scanf("%d",&x);
				if(id.count(x)<=0)
				{
					id[x]=ids++;
				}
				y=id[x];
				insert(i,y,1);
			}
		}
		int x;
		scanf("%d",&x);
		x--;
		for(int i=0; i<n; i++)
		{
			if(i!=x)
				insert(ids,i,up[i]);
			else
				insert(ids,i,inf);
		}
		for(int i=n; i<ids; i++)
			insert(i,ids+1,1);
		printf("%d\n",max_flow(ids,ids+1,ids+2));
	}
	return 0;
}
