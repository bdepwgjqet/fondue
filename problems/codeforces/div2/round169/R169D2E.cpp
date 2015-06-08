#include <cstdio>
#include <algorithm>
#include <vector>
#define N 100010

using namespace std;

struct node{ int v; 
	node(){;}
	node(int x){ v=x; }
};

struct segtree
{
	node *no;
	int n;

	inline int L(int i){ return i<<1; }
	inline int R(int i){ return i<<1|1; }

	segtree(int m)
	{
		n=1;
		for(; n<m; n<<=1);
		no=new node[n<<1];
		fill(no,no+n+n,node(0));
	}

	void update(int id,int l,int r,int ul,int ur,int x)
	{
		if(l>=ul&&r<=ur)
		{
			no[id].v+=x;
			return;
		}
		int m=(l+r)>>1;
		if(l<=ur&&m>=ul)
			update(L(id),l,m,ul,ur,x);
		if(m+1<=ur&&r>=ul)
			update(R(id),m+1,r,ul,ur,x);
	}

	void update(int l,int r,int x)
	{
		update(1,1,n,l,min(r,n),x);
	}

	int query(int p)
	{
		p+=n;
		int ret=0;
		for(; p>0; p>>=1)
			ret+=no[p].v;
		return ret;
	}
};

segtree* seg[N];

vector<int> tr[N];
int id[N],dis[N];

void dfs(int now,int p,int i,int d)
{
	dis[now]=d;
	id[now]=i;
	for(int u=0; u<tr[now].size(); u++)
	{
		if(tr[now][u]==p) continue;
		dfs(tr[now][u],now,i,d+1);
	}
	if(tr[now].size()==1)
		seg[i]=new segtree(d);
}

int main()
{
	int n,q,tc;
	scanf("%d%d",&n,&q);
	for(int i=0; i<n-1; i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		x--,y--;
		tr[x].push_back(y);
		tr[y].push_back(x);
	}
	dis[0]=0;
	tc=tr[0].size();
	for(int i=0; i<tr[0].size(); i++)
	{
		dfs(tr[0][i],0,i,1);
	}
	seg[tc]=new segtree(N);
	for(int i=0; i<q; i++)
	{
		int x,p,d;
		scanf("%d",&x);
		if(x==0)
		{
			scanf("%d%d%d",&p,&x,&d);
			p--;
			if(p==0)
				seg[tc]->update(1,d+1,x);
			else if(d>=dis[p])
			{
				seg[id[p]]->update(d-dis[p]+1,d+dis[p],x);
				seg[tc]->update(1,d-dis[p]+1,x);
			}
			else
				seg[id[p]]->update(dis[p]-d,dis[p]+d,x);
		}
		else
		{
			scanf("%d",&p);
			p--;
			int ret=0;
			if(p==0)
				ret=seg[tc]->query(0);
			else
			{
				ret=seg[id[p]]->query(dis[p]-1);
				ret+=seg[tc]->query(dis[p]);
			}
			printf("%d\n",ret);
		}
	}
	return 0;
}
