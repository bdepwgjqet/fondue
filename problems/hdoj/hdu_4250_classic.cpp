//classic
#include <cstdio>
#include <map>
#include <algorithm>
#include <cstring>
#define S 200001
using namespace std;

struct edge{ int f,t,n,i; }e[S<<1],es[S];
int n,m,in[S],top,list[S],vis[S],del[2],deg[S],odd[S];
int eg[S][2];
int ca=1;
map<pair<int,int>,int> ids;

struct ufind
{
	int p[S];
	void init(){ for(int i=0; i<n; i++) p[i]=i; }
	void run(int &x)
	{
		int y=x,t;
		for(; p[x]!=x; x=p[x]);
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

}uf,uf1;

pair<int,int> mp(int x,int y){ return make_pair(min(x,y),max(x,y)); }

void insert(int f,int t,int i)
{
	e[top].f=f,e[top].t=t,e[top].i=i;
	e[top].n=list[f],list[f]=top++;
}

int con(int u,int v)
{
	int ret=0;
	uf1.init();
	for(int i=0; i<m; i++)
	{
		if(i==u||i==v)
			continue;
		if(uf1.isfriend(es[i].f,es[i].t)==0)
			ret++;
		uf1.setfriend(es[i].f,es[i].t);
	}
	return (ret==n-1);
}

int ok(int &cnt)
{
	cnt=0;
	top=0;
	ids.clear();
	for(int i=0; i<n; i++)
		in[i]=0,list[i]=-1;
	for(int i=0; i<m; i++)
	{
		scanf("%d%d",&es[i].f,&es[i].t);
		es[i].f--,es[i].t--;

		ids[mp(es[i].f,es[i].t)]=i;
		es[i].i=i;
		in[es[i].f]++,in[es[i].t]++;
		insert(es[i].f,es[i].t,i);
		insert(es[i].t,es[i].f,i);
	}
	for(int i=0; i<n; i++)
	{
		if(in[i]<=1)
			return 0;
		else if(in[i]&1)
			odd[cnt++]=i;
	}
	return 1;
}

int solve()
{
	int cnt;
	if(!ok(cnt))
		return 0;
	if(!con(-1,-1))
		return 0;
	if(cnt>=6||(cnt&1)||cnt==0)
		return 0;
	if(cnt==4)
	{
		int c,x,y,a[2],u,v,i=0;
		del[0]=S,del[1]=S;
		for(int j=1; j<4; j++)
		{
			c=0;
			for(int k=0; k<4; k++)
			{
				if(k==i||k==j)
					continue;
				a[c++]=odd[k];
			}
			x=odd[i],y=odd[j];
			if(ids.count(mp(x,y))>0&&ids.count(mp(a[0],a[1]))>0)
			{
				u=ids[mp(x,y)];
				v=ids[mp(a[0],a[1])];
				if(con(u,v)&&min(u,v)<del[0])
				{
					del[0]=min(u,v);
					del[1]=max(u,v);
				}
			}
		}
		return del[0]<S;
	}
	int c=2,x,y;
	for(int i=0; i<n; i++)
		deg[i]=0;
	for(int i=0; i<m; i++)
	{
		x=es[i].f,y=es[i].t;
		if(x==odd[0]||x==odd[1])
		{
			eg[y][deg[y]]=i,deg[y]++;
		}
		if(y==odd[0]||y==odd[1])
		{
			eg[x][deg[x]]=i,deg[x]++;
		}
	}
	uf.init();
	for(int i=0; i<m; i++)
	{
		x=es[i].f,y=es[i].t;
		if(x==odd[0]||x==odd[1]||y==odd[0]||y==odd[1])
			continue;
		uf.setfriend(x,y);
	}
	for(int i=0; i<n; i++)
		in[i]=0;
	for(int i=0; i<n; i++)
	{
		if(i==odd[0]||i==odd[1])
			continue;
		int p=i;
		uf.run(p);
		in[p]+=deg[i];
	}
	int prb[2],p;
	c=0;
	for(int i=0; i<m&&c<2; i++)
	{
		x=es[i].f,y=es[i].t;
		if((x==odd[0]||x==odd[1])&&(y==odd[0]||y==odd[1]))
			continue;
		if(x==odd[0]||x==odd[1])
		{
			if(deg[y]<2)
				continue;
			p=y;
			uf.run(p);
			if(in[p]>=3)
			{
				if(c==0)
					prb[c++]=y;
				else if(prb[0]!=y)
					prb[c++]=y;

			}
		}
		if(y==odd[0]||y==odd[1])
		{
			if(deg[x]<2)
				continue;
			p=x;
			uf.run(p);
			if(in[p]>=3)
			{
				if(c==0)
					prb[c++]=x;
				else if(prb[0]!=x)
					prb[c++]=x;
			}
		}
	}
	if(c==0)
		return 0;
	int now=prb[0];
	if(con(eg[now][0],eg[now][1]))
	{
		del[0]=eg[now][0];
		del[1]=eg[now][1];
		return 1;
	}
	else if(c==2)
	{
		now=prb[1];
		del[0]=eg[now][0];
		del[1]=eg[now][1];
		return 1;
	}
	return 0;
}

int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("Case %d: ",ca++);
		if(solve())
		{
			puts("YES");
			printf("%d %d\n",del[0]+1,del[1]+1);
		}
		else
			puts("NO");
	}
	return 0;
}
