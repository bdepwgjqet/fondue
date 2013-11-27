#include <cstdio>
#include <iostream>
#include <cstring>
#define N 50001
using namespace std;

struct node{ int l,r,s; }no[N<<2];
int dat[N];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r;
	int mid=(l+r)>>1;
	if(l==r)
	{
		no[id].s=dat[l];
		return ;
	}
	build(L(id),l,mid);
	build(R(id),mid+1,r);
	no[id].s=no[L(id)].s+no[R(id)].s;
}

void update(int id,int p,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l==r)
	{
		no[id].s+=x;
		return ;
	}
	if(p<=mid) update(L(id),p,x);
	else update(R(id),p,x);
	no[id].s=no[L(id)].s+no[R(id)].s;
}

int query(int id,int ll,int rr)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1,ret=0;
	if(l==ll&&r==rr)
		return no[id].s;
	if(rr<=mid)
		ret+=query(L(id),ll,rr);
	else if(ll>mid)
		ret+=query(R(id),ll,rr);
	else
	{
		ret+=query(L(id),ll,mid);
		ret+=query(R(id),mid+1,rr);
	}
	return ret;
}

char qq[20];

int main()
{
	int n,t,ca=1;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		printf("Case %d:\n",ca);
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		build(1,1,n);
		int x,y;
		while(scanf("%s",qq))
		{
			if(qq[0]=='E')
				break;
			if(qq[0]=='Q')
			{
				scanf("%d%d",&x,&y);
				printf("%d\n",query(1,x,y));
			}
			else if(qq[0]=='A')
			{
				scanf("%d%d",&x,&y);
				update(1,x,y);
			}
			else
			{
				scanf("%d%d",&x,&y);
				update(1,x,-y);
			}
		}
	}
	return 0;
}
