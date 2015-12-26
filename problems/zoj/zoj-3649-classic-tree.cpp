#include <cstdio>
#include <cstring>
#include <algorithm>
#define inf 0x3ffffff
#define X 18
#define N 60011

using namespace std;

struct edge{ int f,t,n,l; }e[N<<1],es[N<<1];
struct ufind
{
	int p[N];
	void init(int n){ for(int i=0; i<=n; i++) p[i]=i; }
	int pa(int x)
	{
		int y=x,t;
		for(; x!=p[x]; x=p[x]);
		for(; y!=p[t=y]; y=p[y],p[t]=x);
		return x;
	}
}uf;
int val[N],top,list[N],pa[N][X],mi[N][X],mx[N][X],dp1[N][X],dp2[N][X],lay[N];

inline int B(int i){ return 1<<i; }

void insert(int f,int t,int l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

int cmp(edge a,edge b){ return a.l>b.l; }

int kruskal(int m,int n)
{
	int ret=0;
	uf.init(n);
	for(int i=0; i<m; i++)
	{
		int f=uf.pa(es[i].f),t=uf.pa(es[i].t);
		if(f==t)
			continue;
		uf.p[f]=t;
		ret+=es[i].l;
		insert(es[i].f,es[i].t,es[i].l);
		insert(es[i].t,es[i].f,es[i].l);
	}
	return ret;
}

void dfs(int now,int p,int l)
{
	lay[now]=l;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(to==p) continue;
		pa[to][0]=now;
		mi[to][0]=min(val[now],val[to]);
		mx[to][0]=max(val[now],val[to]);
		dp1[to][0]=val[now]-val[to];
		dp2[to][0]=val[to]-val[now];
		for(int u=1; u<X; u++)
		{
			int pp=pa[to][u-1];
			pa[to][u]=pa[pp][u-1];
			mi[to][u]=min(mi[to][u-1],mi[pp][u-1]);
			mx[to][u]=max(mx[to][u-1],mx[pp][u-1]);
			dp1[to][u]=max(max(dp1[to][u-1],dp1[pp][u-1]),mx[pp][u-1]-mi[to][u-1]);
			dp2[to][u]=max(max(dp2[to][u-1],dp2[pp][u-1]),mx[to][u-1]-mi[pp][u-1]);
		}
		dfs(to,now,l+1);
	}
}

int lca(int x,int y)
{
	if(lay[x]<lay[y]) swap(x,y);
	if(lay[x]>lay[y])
	{
		int d=lay[x]-lay[y];
		for(int i=0; i<X; i++)
			if(B(i)&d)
				x=pa[x][i];
	}
	if(x!=y)
	{
		for(int i=X-1; i>=0; i--)
			if(pa[x][i]!=pa[y][i])
				x=pa[x][i],y=pa[y][i];
		x=pa[x][0],y=pa[y][0];
	}
	return x;
}

int getmx(int x,int p)
{
	int d=lay[x]-lay[p],ret=0;
	if(d<0)
		for(;;);
	for(int i=X-1; i>=0; i--)
		if(d&B(i))
		{
			ret=max(ret,mx[x][i]);
			x=pa[x][i];
		}
	return ret;
}

int getmi(int x,int p)
{
	int d=lay[x]-lay[p],ret=inf;
	if(d<0)
		for(;;);
	for(int i=X-1; i>=0; i--)
		if(d&B(i))
		{
			ret=min(ret,mi[x][i]);
			x=pa[x][i];
		}
	return ret;
}

int get1(int x,int p)
{
	int d=lay[x]-lay[p],ret=0,y=inf;
	if(d<0)
		for(;;);
	for(int i=X-1; i>=0; i--)
		if(d&B(i))
		{
			ret=max(ret,max(dp1[x][i],mx[x][i]-y));
			y=min(y,mi[x][i]);
			x=pa[x][i];
		}
	return ret;
}

int get2(int x,int p)
{
	int d=lay[x]-lay[p],ret=0,y=0;
	if(d<0)
		for(;;);
	for(int i=X-1; i>=0; i--)
		if(d&B(i))
		{
			ret=max(ret,max(dp2[x][i],y-mi[x][i]));
			y=max(y,mx[x][i]);
			x=pa[x][i];
		}
	return ret;
}

int solve(int x,int y)
{
	int p=lca(x,y);
	int g1=get1(x,p);
	int g2=get2(y,p);
	int gx=getmx(y,p);
	int gi=getmi(x,p);
	return max(max(g1,g2),gx-gi);
}

int main()
{
	int n,m;
	while(scanf("%d",&n)+1)
	{
		top=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&val[i]);
			list[i]=-1;
		}
		list[0]=-1;
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			es[i].f=x,es[i].t=y,es[i].l=z;
		}
		sort(es,es+m,cmp);
		int ret=kruskal(m,n),qs;
		printf("%d\n",ret);
		memset(pa,0,sizeof(pa));
		fill(mx[0],mx[n+1],-inf);
		fill(mi[0],mi[n+1],inf);
		fill(dp1[0],dp1[n+1],-inf);
		fill(dp2[0],dp2[n+1],-inf);
		lay[0]=0;
		dfs(1,0,1);

		scanf("%d",&qs);
		for(int i=0; i<qs; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",solve(x,y));
		}
	}
	return 0;
}
