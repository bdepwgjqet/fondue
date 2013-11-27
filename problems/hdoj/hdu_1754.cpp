#include <cstdio>
#include <algorithm>
#define N 200011
using namespace std;

struct node{ int l,r,v;
	int gm(){ return (l+r)>>1; };
}no[3*N];
int dat[N];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r;
	if(l==r)
	{
		no[id].v=dat[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);
	no[id].v=max(no[L(id)].v,no[R(id)].v);
}

void update(int id,int p,int x)
{
	int mid=no[id].gm();
	if(no[id].l==no[id].r)
	{
		no[id].v=x;
		return ;
	}
	if(p<=mid)
		update(L(id),p,x);
	else
		update(R(id),p,x);
	no[id].v=max(no[L(id)].v,no[R(id)].v);
}

int query(int id,int ll,int rr)
{
	int mid=no[id].gm();
	if(ll==no[id].l&&rr==no[id].r)
		return no[id].v;
	if(rr<=mid)
		return query(L(id),ll,rr);
	else if(ll>mid)
		return query(R(id),ll,rr);
	else
		return max(query(L(id),ll,mid),query(R(id),mid+1,rr));
}

int main()
{
	int n,m,x,y;
	char s[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		build(1,1,n);
		for(int i=0; i<m; i++)
		{
			scanf("%s%d%d",s,&x,&y);
			if(s[0]=='Q')
				printf("%d\n",query(1,x,y));
			else
				update(1,x,y);
		}
	}
	return 0;
}
