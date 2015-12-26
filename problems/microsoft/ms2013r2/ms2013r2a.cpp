#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 310
#define S 200100
#define inf 1000000

using namespace std;

struct edge{ int f,t,w,n; }e[S];
int list[N],top,lay[N],q[S];

void insert(int f,int t,int w)
{
	e[top].f=f,e[top].t=t,e[top].w=w;
	e[top].n=list[f],list[f]=top++;
}

void _insert(int f,int t,int w)
{
	insert(f,t,w);
	insert(t,f,0);
}

int bfs(int s,int t,int n)
{
	int l,r;
	for(int i=0; i<n; i++)
		lay[i]=-1;
	q[l=r=0]=s;
	lay[s]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		for(int i=list[now]; i!=-1; i=e[i].n)
		{
			int to=e[i].t;
			if(lay[to]<0&&e[i].w>0)
				lay[to]=lay[now]+1,q[++r]=to;
		}
	}
	return lay[t]>=0;
}

int dfs(int now,int t,int now_flow)
{
	int ttl=0,single;
	if(now==t)	return now_flow;
	for(int i=list[now]; i!=-1&&now_flow>ttl; i=e[i].n)
	{
		int to=e[i].t;
		if(lay[to]==lay[now]+1&&e[i].w>0&&(single=dfs(to,t,min(now_flow-ttl,e[i].w))))
		{
			e[i].w-=single;
			e[i^1].w+=single;
			ttl+=single;
		}
	}
	if(ttl==0) lay[now]=-1;
	return ttl;
}

int dicnic(int s,int t,int n)
{
	int ret=0;
	while(bfs(s,t,n))
	{
		ret+=dfs(s,t,inf);
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		printf("Case #%d:\n",ca);
		int now=0,pre=0;
		int n,m;
		scanf("%d%d",&n,&m);
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<m; i++)
		{
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			_insert(x-1,y-1,c);
			_insert(y-1,x-1,c);
			now=dicnic(0,n-1,n);
			if(now>0)
				printf("%d %d\n",i+1,now);
			pre=now;
		}
	}
	return 0;
}
