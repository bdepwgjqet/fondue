#include <cstdio>
#include <algorithm>
#define N 50010

typedef long long LL;
using namespace std;

const LL inf=0x3ffffffffffffLL;

struct node{ int l,r; LL v; 
	int gm(){ return (l+r)>>1; }
}no[N<<2];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

int dat[N],val[N];

void init(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].v=inf;
	if(l==r) return;
	int m=no[id].gm();
	init(L(id),l,m);
	init(R(id),m+1,r);
}

void update(int id,int p,LL x)
{
	int l=no[id].l,r=no[id].r,m=no[id].gm();
	if(l==r)
	{
		no[id].v=min(x,no[id].v);
		return;
	}
	if(p<=m)
		update(L(id),p,x);
	else
		update(R(id),p,x);
	no[id].v=min(no[L(id)].v,no[R(id)].v);
}

LL query(int id,int ll,int rr)
{
	int l=no[id].l,r=no[id].r,m=no[id].gm();
	if(ll<=l&&rr>=r)
		return no[id].v;
	LL ret=inf;
	if(rr>=l&&ll<=m)
		ret=min(ret,query(L(id),ll,rr));
	if(ll<=r&&rr>m)
		ret=min(ret,query(R(id),ll,rr));
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&val[i]);
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		init(1,1,n);
		update(1,min(dat[1],n),val[1]);
		for(int i=2; i<=n; i++)
		{
			LL x=query(1,i-1,n);
			update(1,min(i+dat[i]-1,n),x+val[i]);
		}
		printf("%lld\n",query(1,n,n));
	}
	return 0;
}
