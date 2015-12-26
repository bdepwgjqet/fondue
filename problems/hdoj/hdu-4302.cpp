#include <cstdio>
#include <cmath>
#include <algorithm>
#define inf 0x3ffffff
#define N 100001
typedef long long LL;
using namespace std;

struct node{ int l,r,lp,rp,cnt;
	int gm(){ return (l+r)>>1; }
}no[N<<2];
inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].cnt=0;
	if(l==r)
		return;
	build(L(id),l,no[id].gm());
	build(R(id),no[id].gm()+1,r);
}

void update(int id,int p,int x)
{
	int mid=no[id].gm();
	if(no[id].l==no[id].r)
	{
		no[id].cnt+=x;
		no[id].lp=no[id].rp=no[id].l;
		return;
	}
	if(p<=mid) update(L(id),p,x);
	else update(R(id),p,x);
	no[id].cnt=no[L(id)].cnt+no[R(id)].cnt;
	no[id].lp=no[L(id)].cnt>0?no[L(id)].lp:no[R(id)].lp;
	no[id].rp=no[R(id)].cnt>0?no[R(id)].rp:no[L(id)].rp;
}

int query(int id,int ll,int rr,int tag)
{
	if(no[id].cnt==0)
		return inf;
	int l=no[id].l,r=no[id].r,mid=no[id].gm(),ret;
	if(l>=ll&&r<=rr)
		return tag>0?no[id].lp:no[id].rp;
	if(tag==1)
	{
		ret=inf;
		if(mid>=ll&&l<=rr)
		{
			ret=query(L(id),ll,rr,tag);
			if(ret<inf)
				return ret;
		}
		if(mid<rr&&r>=ll)
		{
			ret=query(R(id),ll,rr,tag);
		}
	}
	else
	{
		ret=inf;
		if(mid<rr&&r>=ll)
		{
			ret=query(R(id),ll,rr,tag);
			if(ret<inf)
				return ret;
		}
		if(mid>=ll&&l<=rr)
			ret=query(L(id),ll,rr,tag);
	}
	return ret;
}

int main()
{
	int ts,len,n,pos,dir;
	scanf("%d",&ts);
	for(int ca=1; ca<=ts; ca++)
	{
		printf("Case %d: ",ca);
		scanf("%d%d",&len,&n);
		build(1,1,len+1);
		pos=1,dir=0;
		LL ret=0;
		for(int i=0; i<n; i++)
		{
			int x;
			scanf("%d",&x);
			if(x==1)
			{
				int lp,rp,nowp;
				lp=query(1,1,pos,-1);
				rp=query(1,pos,len+1,1);
				if(lp==inf&&rp==inf)
					continue;
				if(abs(pos-lp)==abs(rp-pos))
				{
					if(dir==1)
						nowp=rp;
					else
						nowp=lp;
				}
				else
				{
					if(abs(pos-lp)>abs(rp-pos))
						nowp=rp;
					else
						nowp=lp;
				}
				update(1,nowp,-1);
				ret+=abs(nowp-pos);
				if(nowp<pos)
					dir=-1;
				else if(nowp>pos)
					dir=1;
				pos=nowp;
			}
			else
			{
				scanf("%d",&x);
				x++;
				update(1,x,1);
			}
		}
		printf("%lld\n",ret);
	}
	return 0;
}
