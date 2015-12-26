#include <cstdio>
#include <vector>
#define N 50000
#define S 200000

using namespace std;

struct edge{ int f,t,l,n; }e[S];
struct node{ int t,r,i;
	node(int a,int b,int c){ t=a,r=b,i=c; }
};
vector<node> q[N];
int v[N],vis[N],len[N],ret[N],list[N],top;

void insert(int f,int t,int l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

struct ufind
{
	int p[N],t;
	void init(){ for(int i=0; i<N; p[i]=i++); }
	void run(int &x)
	{ 
		int y=x;
		for(; (t=p[x])!=x; x=p[x],p[t]=p[x]);
		for(; p[t=y]!=x; p[y]=x,y=p[t]);
	}
	int isfriend(int i,int j)
	{
		run(i); run(j);
		return i==j;
	}
	void setfriend(int i,int j)
	{
		run(i); run(j);
		p[i]=j;
	}
}uf;

void tarjan(int now,int l)
{
	len[now]=l;
	v[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(v[to])
			continue;
		tarjan(to,l+e[i].l);
		uf.setfriend(to,now);
	}
	vis[now]=1;
	for(int i=0; i<q[now].size(); i++)
	{
		int to=q[now][i].t;
		if(!vis[to])
			continue;
		int p=to,ii=q[now][i].i;
		uf.run(p);
		ret[ii]=l+len[to]-2*len[p];
		q[now][i].r=l+len[to]-2*len[p];
	}
}
