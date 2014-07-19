#include <cstdio>
#include <algorithm>
#define N 200011
using namespace std;

struct edge{ int f,t,n,l,i; }e[N];
int n,m,k,mx,add,ttl;

struct ufind
{
	int p[N];
	void init(){ for(int i=0; i<n; i++) p[i]=i; }
	void run(int &x)
	{
		int y=x,t;
		for(; p[x]!=x; x=p[p[x]]);
		for(; p[t=y]!=x; y=p[y],p[t]=x);
	}
	void setfriend(int i,int j)
	{
		run(i);
		run(j);
		p[i]=j;
	}
	int isfriend(int i,int j)
	{
		run(i);
		run(j);
		return i==j;
	}
}uf;

int cmp(edge a,edge b)
{ 
	int la=a.l+(a.i==0)*add,lb=b.l+(b.i==0)*add;
	return la==lb?a.i<b.i:la<lb;
}

int counta()
{
	int ret=0,f,t,j=0;
	ttl=0;
	uf.init();
	for(int i=0; i<m&&j<n; i++)
	{
		f=e[i].f,t=e[i].t;
		if(uf.isfriend(f,t))
			continue;
		uf.setfriend(f,t);
		j++;
		ttl+=e[i].l;
		if(e[i].i==0)
			ret++,ttl+=add;
	}
	return ret;
}

void solve()
{
	int l=-mx,r=mx,mid,c;
	for(; l<=r; )
	{
		mid=(l+r)>>1;
		add=mid;
		sort(e,e+m,cmp);
		c=counta();
		if(c>=k)
			l=mid+1;
		else
			r=mid-1;
	}
	add=r;
	sort(e,e+m,cmp);
	c=counta();
}

int main()
{
	int ca=1;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		mx=0;
		printf("Case %d: ",ca++);
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d%d",&e[i].f,&e[i].t,&e[i].l,&e[i].i);
			e[i].l*=2;
			mx=max(e[i].l,mx);
		}
		solve();
		printf("%d\n",(ttl-k*add)/2);
	}
	return 0;
}
