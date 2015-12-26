#include <cstdio>
#include <algorithm>
#define N 200011
using namespace std;

struct node{ int l,r,s;
	int gm(){ return (l+r)>>1; }
};
struct point{ int x,y; }p[N];
int y[N],top,q[N];

inline int L(int i){ return i<<1; }
inline int R(int i){ return i<<1|1; }

class seg_tree
{
public:
	node no[N<<2];
	void build(int id,int l,int r)
	{
		no[id].l=l,no[id].r=r,no[id].s=0;
		if(l==r)
			return;
		int mid=(l+r)>>1;
		build(L(id),l,mid);
		build(R(id),mid+1,r);
	}
	void update(int id,int p,int x)
	{
		if(no[id].l==no[id].r)
		{
			no[id].s+=x;
			return;
		}
		if(p<=no[id].gm())
			update(L(id),p,x);
		else
			update(R(id),p,x);
		no[id].s=no[L(id)].s+no[R(id)].s;
	}
	int query(int id,int ll,int rr)
	{
		if(ll>rr) return 0;
		int ret=0,l=no[id].l,r=no[id].r,mid=(l+r)>>1;
		if(l>=ll&&r<=rr)
			return no[id].s;
		if(mid>=ll&&l<=rr)
			ret+=query(L(id),ll,rr);
		if(mid<rr&&r>=ll)
			ret+=query(R(id),ll,rr);
		return ret;
	}
}left,right;

int cmp1(int a,int b){ return a<b; }
int cmp2(point a,point b){ return a.x<b.x; }

int get_id(int x)
{
	int l=0,r=top-1,mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(y[mid]<x)
			l=mid+1;
		else if(y[mid]>x)
			r=mid-1;
		else
			return mid;
	}
	return -1; //imp
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		top=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			y[top++]=p[i].y;
		}
		sort(y,y+top,cmp1);
		sort(p,p+n,cmp2);
		int ntop=1;
		for(int i=1; i<top; i++)
		{
			if(y[i]==y[ntop-1])
				continue;
			else
				y[ntop++]=y[i];
		}
		top=ntop;
		left.build(1,1,top);
		right.build(1,1,top);
		for(int i=0; i<n; i++)
			right.update(1,get_id(p[i].y)+1,1);
		/*
		for(int i=0; i<top; i++)
			printf("%d ",y[i]);
		puts("");
		*/
		int j;
		int stan=-1,otop=0;
		for(int i=0; i<n; i=j)
		{
			for(j=i+1; j<n; j++)
				if(p[j].x!=p[i].x)
					break;
			for(int k=i; k<j; k++)
				right.update(1,get_id(p[k].y)+1,-1);
			int st,ol=-1,d,s,o;
			for(int k=i; k<j; k++)
			{
				d=get_id(p[k].y)+1;
				s=left.query(1,1,d-1)+right.query(1,d+1,top);
				o=left.query(1,d+1,top)+right.query(1,1,d-1);
				if(ol<o)
					ol=o,st=s;
				else if(ol==o)
					st=min(st,s);
			}
			if(st>stan)
				stan=st,q[otop=0]=ol,otop++;
			else if(st==stan)
				q[otop++]=ol;
			for(int k=i; k<j; k++)
				left.update(1,get_id(p[k].y)+1,1);
		}
		sort(q,q+otop,cmp1);
		printf("Stan: %d; Ollie:",stan);
		int pre=-1;
		for(int i=0; i<otop; i++)
		{
			if(q[i]==pre)
				continue;
			else
			{
				printf(" %d",q[i]);
				pre=q[i];
			}
		}
		puts(";");
	}
	return 0;
}
