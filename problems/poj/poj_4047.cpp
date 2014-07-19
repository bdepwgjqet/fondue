#include <cstdio>
#include <algorithm>
#define inf 0x3fffffff
#define N 200011
using namespace std;

int dat[N],sum[N];

struct node{ int l,r,v,c; }no[N<<2];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=0;
	if(l==r)
	{
		no[id].v=sum[l];
		return;
	}
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);
	no[id].v=max(no[L(id)].v,no[R(id)].v);
}

void down(int id,int l,int r)
{
	if(no[id].c!=0)
	{
		no[L(id)].c+=no[id].c;
		no[R(id)].c+=no[id].c;
		no[L(id)].v+=no[id].c;
		no[R(id)].v+=no[id].c;
		no[id].c=0;
	}
}

void update(int id,int ll,int rr,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l>=ll&&r<=rr)
	{
		no[id].c+=x;
		no[id].v+=x;
		return;
	}
	down(id,l,r);
	if(mid>=ll&&l<=rr)
		update(L(id),ll,rr,x);
	if(mid<rr&&r>=ll)
		update(R(id),ll,rr,x);
	no[id].v=max(no[L(id)].v,no[R(id)].v);
}

int query(int id,int ll,int rr)
{
	if(ll>rr)
		return 0;
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1,ret=-inf;
	if(l>=ll&&r<=rr)
		return no[id].v;
	down(id,l,r);
	if(mid>=ll&&l<=rr)
		ret=max(ret,query(L(id),ll,rr));
	if(mid<rr&&r>=ll)
		ret=max(ret,query(R(id),ll,rr));
	return ret;
}

int main()
{
	int n,m,k,nn,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		sum[1]=0;
		for(int i=1; i<=k; i++)
			sum[1]+=dat[i];
		for(int i=2; i+k-1<=n; i++)
			sum[i]=sum[i-1]+dat[i+k-1]-dat[i-1];
		nn=n-k+1;
		build(1,1,nn);
		int p,x,y,d;
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d",&p,&x,&y);
			if(p==0)
			{
				d=y-dat[x];
				update(1,max(1,x-k+1),min(x,nn),d);
				dat[x]=y;
			}
			else if(p==1)
			{
				d=dat[y]-dat[x];
				update(1,max(1,x-k+1),min(x,nn),d);
				d=dat[x]-dat[y];
				update(1,max(1,y-k+1),min(y,nn),d);
				swap(dat[x],dat[y]);
			}
			else
			{
				if(x>y)
					swap(x,y);
				printf("%d\n",query(1,x,y-k+1));
			}
		}
	}
	return 0;
}
