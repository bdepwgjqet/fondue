#include <cstdio>
#define N 100011

struct node{ int l,r,s,c; }no[N<<2];
inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

int build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=0;
	if(l==r)
		return no[id].s=1;
	int mid=(l+r)>>1;
	return no[id].s=build(L(id),l,mid)+build(R(id),mid+1,r);
}

void pushdown(int id,int l,int r)
{
	int m=(l+r)>>1;
	if(no[id].c)
	{
		no[L(id)].c=no[id].c;
		no[R(id)].c=no[id].c;
		no[L(id)].s=no[id].c*(m-l+1);
		no[R(id)].s=no[id].c*(r-m);
		no[id].c=0;
	}
}

void update(int id,int ll,int rr,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l>=ll&&r<=rr)
	{
		no[id].c=x;
		no[id].s=(r-l+1)*x;
		return;
	}
	pushdown(id,l,r);
	if(mid>=ll&&l<=rr) update(L(id),ll,rr,x);
	if(mid<rr&&r>=ll) update(R(id),ll,rr,x);
	no[id].s=no[L(id)].s+no[R(id)].s;
}

int query(int id,int ll,int rr)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l>=ll&&r<=rr)
		return no[id].s;
	pushdown(id,l,r);
	int ret=0;
	if(mid>=ll&&l<=rr) ret+=query(L(id),ll,rr);
	if(mid<rr&&r>=ll) ret+=query(R(id),ll,rr);
	return mid;
}

int main()
{
	int n,t,m;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		printf("Case %d: ",ca);
		scanf("%d%d",&n,&m);
		build(1,1,n);
		int x,y,z;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d",&x,&y,&z);
			update(1,x,y,z);
		}
		printf("The total value of the hook is %d.\n",query(1,1,n));
	}
	return 0;
}
