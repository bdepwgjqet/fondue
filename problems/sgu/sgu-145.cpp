#include <cstdio>
#include <cstring>
#include <vector>
#define inf 0x3fffffff
#define N 111

using namespace std;

struct edge{ int t,l,n; }e[2*N*N];
int st,ed,q[N*N],vis[N],dis[N],top,list[N];
vector<int> path;

void insert(int f,int t,int l)
{
	e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

void spfa(int f,int t)
{
	int l,r;
	for(int i=0; i<N; i++)
		dis[i]=inf,vis[i]=0;
	q[l=r=0]=f;
	dis[f]=0;
	for(; l<=r;)
	{
		int now=q[l++];
		vis[now]=0;
		for(int i=list[now]; i!=-1; i=e[i].n)
		{
			int to=e[i].t;
			if(dis[now]+e[i].l<dis[to])
			{
				dis[to]=dis[now]+e[i].l;
				if(!vis[to])
					vis[to]=1,q[++r]=to;
			}
		}
	}
}

int minl,nowl;

int ida(int now,int ed,int l,int &cnt,int k)
{
	if(now==ed)
	{
		if(l!=nowl) return 0;
		cnt++;
		if(cnt==k)
		{
			path.clear();
			path.push_back(now);
			return 1;
		}
		return 0;
	}
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t,x=l+e[i].l+dis[to];
		if(x<=nowl)
		{
			if(!vis[to])
			{
				vis[to]=1;
				int ret=ida(to,ed,l+e[i].l,cnt,k);
				vis[to]=0;
				if(ret)
				{
					path.push_back(now);
					return 1;
				}
			}
		}
		else if(x<minl)
			minl=x;
	}
	return 0;
}

void gao(int k)
{
	int cnt=0;
	memset(vis,0,sizeof(vis));
	minl=inf,nowl=dis[st];
	vis[st]=1;
	for(; !ida(st,ed,0,cnt,k); nowl=minl,minl=inf);
	printf("%d %d\n",nowl,path.size());
	for(int i=path.size()-1; i>=0; i--)
		printf("%d%c",path[i]+1,i>0?' ':'\n');
}

int main()
{
	int n,m,k;
	while(scanf("%d%d%d",&n,&m,&k)+1)
	{
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<m; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			x--,y--;
			insert(x,y,z);
			insert(y,x,z);
		}
		scanf("%d%d",&st,&ed);
		st--,ed--;
		spfa(ed,st);
		gao(k);
	}
	return 0;
}
