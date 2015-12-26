#include <cstdio>
#include <algorithm>
#define N 200111
typedef long long LL;
using namespace std;

struct node{ int l,r,v; }no[N<<2];
int h,w,n;

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

LL dat[N];

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].v=l;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);

}

int query(int id,int l,int r,LL x)
{
	if(x>dat[no[id].v])
		return -1;
	int mid=(l+r)>>1,ret;
	if(l==r)
	{
		dat[l]-=x;
		return l;
	}
	if(x<=dat[no[L(id)].v])
		ret=query(L(id),l,mid,x);
	else
		ret=query(R(id),mid+1,r,x);
	no[id].v=dat[no[L(id)].v]>dat[no[R(id)].v]?no[L(id)].v:no[R(id)].v;
	return ret;
}

int main()
{
	int nn;
	while(scanf("%d%d%d",&h,&w,&n)!=EOF)
	{
		nn=min(h,n);
		for(int i=1; i<=n; i++)
			dat[i]=w;
		build(1,1,nn);
		for(int i=1; i<=n; i++)
		{
			int x;
			scanf("%d",&x);
			printf("%d\n",query(1,1,nn,(LL)x));
		}
	}
	return 0;
}
