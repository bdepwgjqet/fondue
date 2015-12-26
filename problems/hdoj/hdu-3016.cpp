#include <cstdio>
#include <algorithm>
#define inf 0x3ffffff
#define N 100011
using namespace std;

struct node{ int l,r,c; }no[N<<2];
struct segment{ int l,r,v,h; }seg[N];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

int dp[N],nx[N][2];

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=0;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);
}

void down(int id,int l,int r)
{
	if(no[id].c>=0)
	{
		no[L(id)].c=no[id].c;
		no[R(id)].c=no[id].c;
		no[id].c=-1;
	}
}

void update(int id,int ll,int rr,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l>=ll&&r<=rr)
	{
		no[id].c=x;
		return;
	}
	down(id,l,r);
	if(mid>=ll&&l<=rr)
		update(L(id),ll,rr,x);
	if(mid<rr&&r>=ll)
		update(R(id),ll,rr,x);
}

int query(int id,int p)
{
	if(no[id].c>=0)
		return no[id].c;
	int mid=(no[id].l+no[id].r)>>1;
	if(p<=mid)
		return query(L(id),p);
	else
		return query(R(id),p);
}

int cmp(segment a,segment b){ return a.h<b.h; }

int main()
{
	int n,mx;
	while(scanf("%d",&n)!=EOF)
	{
		mx=0;
		seg[0].v=0,seg[0].h=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d%d%d%d",&seg[i].h,&seg[i].l,&seg[i].r,&seg[i].v);
			mx=max(mx,seg[i].r);
		}
		sort(seg,seg+n+1,cmp);
		build(1,1,mx);
		for(int i=1; i<=n; i++)
		{
			nx[i][0]=query(1,seg[i].l);
			nx[i][1]=query(1,seg[i].r);
			update(1,seg[i].l,seg[i].r,i);
		}
		for(int i=0; i<=n; i++)
			dp[i]=-inf;
		dp[n]=100+seg[n].v;
		for(int i=n; i>0; i--)
		{
			int x=nx[i][0];
			if(dp[i]==inf||dp[i]<=0)
				continue;
			dp[x]=max(dp[x],dp[i]+seg[x].v);
			x=nx[i][1];
			dp[x]=max(dp[x],dp[i]+seg[x].v);
		}
		if(dp[0]>0)
			printf("%d\n",dp[0]);
		else
			puts("-1");
	}
	return 0;
}
