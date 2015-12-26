#include <cstdio>
#define N 101001
typedef long long LL; 

int dat[N];
struct node{ int l,r; LL s,a;
	int gm(){ return (l+r)>>1; }
}no[N<<2];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

LL build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].a=0;
	if(l==r)
		return no[id].s=dat[l];
	int mid=(l+r)>>1;
	return no[id].s=build(L(id),l,mid)+build(R(id),mid+1,r);
}

void pushdown(int id,int l,int r)
{
	int mid=no[id].gm();
	if(no[id].a)
	{
		no[L(id)].a+=no[id].a;
		no[R(id)].a+=no[id].a;
		no[L(id)].s+=no[id].a*(mid-l+1);
		no[R(id)].s+=no[id].a*(r-mid);
		no[id].a=0;
	}
}

void update(int id,int ll,int rr,LL x)
{
	int l=no[id].l,r=no[id].r,mid=no[id].gm();
	if(l>=ll&&r<=rr)
	{
		no[id].a+=x;
		no[id].s+=(r-l+1)*x;
		return;
	}
	pushdown(id,l,r);
	if(ll<=mid&&l<=rr) update(L(id),ll,rr,x);
	if(rr>mid&&r>=ll) update(R(id),ll,rr,x);
	no[id].s=no[L(id)].s+no[R(id)].s;
}

LL query(int id,int ll,int rr)
{
	int l=no[id].l,r=no[id].r,mid=no[id].gm();
	if(l>=ll&&r<=rr)
		return no[id].s;
	pushdown(id,l,r);
	LL ret=0;
	if(mid>=ll&&l<=rr) ret+=query(L(id),ll,rr);
	if(mid<rr&&r>=ll) ret+=query(R(id),ll,rr);
	return ret;
}

int main()
{
	int n,m;
	char s[10];
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		build(1,1,n);
		int x,y; LL z;
		for(int i=0; i<m; i++)
		{
			scanf("%s%d%d",s,&x,&y);
			if(s[0]=='Q')
				printf("%lld\n",query(1,x,y));
			else
			{
				scanf("%lld",&z);
				update(1,x,y,z);
			}
		}
	}
	return 0;
}
