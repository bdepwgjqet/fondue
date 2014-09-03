#include <cstdio>
#define N 101101

int dat[N],lev[N];

struct node{ int a,b,v,i; }no[N<<2];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void up(int id)
{
	if(no[L(id)].v>no[R(id)].v)
		no[id].v=no[L(id)].v,no[id].i=no[L(id)].i;
	else
		no[id].v=no[R(id)].v,no[id].i=no[R(id)].i;
	no[id].a=no[L(id)].a+no[R(id)].a;
	no[id].b=no[L(id)].b+no[R(id)].b;
}

void build(int id,int l,int r)
{
	int m=(l+r)>>1;
	if(l==r)
	{
		no[id].v=dat[l];
		no[id].i=l;
		no[id].a=(lev[l]==1)?1:0;
		no[id].b=(lev[l]==-1)?1:0;
		return;
	}
	build(L(id),l,m);
	build(R(id),m+1,r);
	up(id);
}

int query(int id,int l,int r,int ql,int qr,int &x)
{
	int m=(l+r)>>1;
	if(ql<=l&&r<=qr)
	{
		x=no[id].v;
		return no[id].i;
	}
	int lx=0,rx=0,li=-1,ri=-1;
	if(qr>=l&&ql<=m)
		li=query(L(id),l,m,ql,qr,lx);
	if(qr>=m+1&&ql<=r)
		ri=query(R(id),m+1,r,ql,qr,rx);
	if(lx>rx)
	{
		x=lx;
		return li;
	}
	x=rx;
	return ri;
}

int sum(int id,int l,int r,int ql,int qr,int t)
{
	if(l>r) return 0;
	int m=(l+r)>>1;
	if(ql<=l&&r<=qr)
	{
		if(t==0) return no[id].a;
		return no[id].b;
	}
	int ret=0;
	if(qr>=l&&ql<=m)
	{
		ret+=sum(L(id),l,m,ql,qr,t);
	}
	if(qr>=m+1&&ql<=r)
		ret+=sum(R(id),m+1,r,ql,qr,t);
	return ret;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++)
		scanf("%d",&dat[i]);
	lev[1]=0;
	for(int i=2; i<=n; i++)
	{
		if(dat[i]>dat[i-1]) lev[i]=1;
		else if(dat[i]<dat[i-1]) lev[i]=-1;
		else lev[i]=0;
	}
	build(1,1,n);
	for(int i=1; i<=m; i++)
	{
		int l,r,mx;
		scanf("%d%d",&l,&r);
		int id=query(1,1,n,l,r,mx);
		int po=sum(1,1,n,l+1,id,1),fu=sum(1,1,n,id+1,r,0);
		if(po==0&&fu==0)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
