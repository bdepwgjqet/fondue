//chose c++ to compile
#include <cstdio>
#include <algorithm>
#define N 1001
using namespace std;

struct sub_node{ int l,r,v; };
struct node
{
	int l,r;
	sub_node sub[N<<2];
	int gm(){ return (l+r)>>1; }
}no[440];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

void _build(int pid,int id,int l,int r)
{
	no[pid].sub[id].l=l,no[pid].sub[id].r=r,no[pid].sub[id].v=-1;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	_build(pid,L(id),l,mid);
	_build(pid,R(id),mid+1,r);
}

void build(int id,int l,int r)
{
	_build(id,1,1,N);
	no[id].l=l,no[id].r=r;
	if(l==r)
		return;
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid+1,r);
}

void _update(int pid,int id,int p,int x)
{
//	printf("%d %d %d %d\n",pid,id,p,x);
	int l=no[pid].sub[id].l,r=no[pid].sub[id].r,mid=(l+r)>>1;
	if(l==r)
	{
		no[pid].sub[id].v=max(no[pid].sub[id].v,x);
		return;
	}
	if(p<=mid)
		_update(pid,L(id),p,x);
	else
		_update(pid,R(id),p,x);
	no[pid].sub[id].v=max(no[pid].sub[L(id)].v,no[pid].sub[R(id)].v);
}

void update(int id,int p,int subp,int x)
{
//	printf("%d %d %d %d\n",id,p,subp,x);
	_update(id,1,subp,x);
	if(no[id].l==no[id].r)
		return;
	if(p<=no[id].gm())
		update(L(id),p,subp,x);
	else
		update(R(id),p,subp,x);
}

int _query(int pid,int id,int ll,int rr)
{
	int l=no[pid].sub[id].l,r=no[pid].sub[id].r,mid=(l+r)>>1,ret=-1;
	if(l>=ll&&r<=rr)
		return no[pid].sub[id].v;
	if(mid>=ll&&l<=rr)
		ret=_query(pid,L(id),ll,rr);
	if(mid<rr&&r>=ll)
		ret=max(ret,_query(pid,R(id),ll,rr));
	return ret;
}

int query(int id,int ll,int rr,int subll,int subrr)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1,ret=-1;
	if(l>=ll&&r<=rr)
		return _query(id,1,subll,subrr);
	if(mid>=ll&&l<=rr)
		ret=query(L(id),ll,rr,subll,subrr);
	if(mid<rr&&r>=ll)
		ret=max(ret,query(R(id),ll,rr,subll,subrr));
	return ret;
}

int main()
{
	int n,x,h1,h2;
	double y,z;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		build(1,1,101);
		char s[10];
		for(int i=0; i<n; i++)
		{
			scanf("%s",s);
			if(s[0]=='I')
			{
				scanf("%d%lf%lf",&x,&y,&z);
				update(1,x-99,int(y*10)+1,int(z*10));
			}
			else
			{
				scanf("%d%d%lf%lf",&h1,&h2,&y,&z);
				if(h1>h2) swap(h1,h2);
				if(y>z) swap(y,z);
				int ret=query(1,h1-99,h2-99,int(y*10)+1,int(z*10)+1);
				if(ret<0)
					puts("-1");
				else
					printf("%.1lf\n",0.1*ret);
			}
		}
	}
	return 0;
}
