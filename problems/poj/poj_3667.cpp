#include <cstdio>
#include <algorithm>
#define N 50011
using namespace std;

struct node{ int l,r,v,lv,rv,i,c;
	int len(){ return r-l+1; }
	int pos(){ return r-rv+1; }
}no[N<<2];
inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void up(int id,int l,int r)
{
	no[id].lv=no[L(id)].lv+(no[L(id)].lv==no[L(id)].len())*no[R(id)].lv;
	no[id].rv=no[R(id)].rv+(no[R(id)].rv==no[R(id)].len())*no[L(id)].rv;
	no[id].v=max(max(no[L(id)].v,no[R(id)].v),no[L(id)].rv+no[R(id)].lv);
	if(no[id].v==no[L(id)].v)
		no[id].i=no[L(id)].i;
	else if(no[id].v==no[L(id)].rv+no[R(id)].lv)
		no[id].i=no[L(id)].pos();
	else
		no[id].i=no[R(id)].i;
}

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=-1;
	if(l==r)
	{
		no[id].v=no[id].lv=no[id].rv=1;
		no[id].i=l;
		return;
	}
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);
	up(id,l,r);
}

void down(int id,int l,int r)
{
	if(no[id].c>=0)
	{
		no[L(id)].c=no[id].c;
		no[R(id)].c=no[id].c;
		no[L(id)].v=no[L(id)].lv=no[L(id)].rv=(1-no[id].c)*no[L(id)].len();
		no[R(id)].v=no[R(id)].lv=no[R(id)].rv=(1-no[id].c)*no[R(id)].len();
		no[L(id)].i=no[L(id)].l;
		no[R(id)].i=no[R(id)].l;
		no[id].c=-1;
	}
}

void update(int id,int ll,int rr,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l>=ll&&r<=rr)
	{
		no[id].c=x;
		if(x==0)
		{
			no[id].v=no[id].lv=no[id].rv=no[id].len();
			no[id].i=l;
		}
		else
			no[id].v=no[id].lv=no[id].rv=0;
		return;
	}
	down(id,l,r);
	if(mid>=ll&&l<=rr)
		update(L(id),ll,rr,x);
	if(mid<rr&&r>=ll)
		update(R(id),ll,rr,x);
	up(id,l,r);
}

int query(int id,int x)
{
	int mid=(no[id].l+no[id].r)>>1;
	if(no[id].v<x)
		return 0;
	if(no[L(id)].v>=x)
		return query(L(id),x);
	if(no[L(id)].rv+no[R(id)].lv>=x)
		return no[L(id)].pos();
	if(no[R(id)].v>=x)
		return query(R(id),x);
	return no[id].i;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		int x,y,id;
		build(1,1,n);
		for(int i=0; i<m; i++)
		{
			scanf("%d",&x);
			if(x==1)
			{
				scanf("%d",&x);
				id=query(1,x);
				printf("%d\n",id);
				if(id)
					update(1,id,id+x-1,1);
			}
			else
			{
				scanf("%d%d",&x,&y);
				update(1,x,x+y-1,0);
			}

		}
	}
	return 0;
}
