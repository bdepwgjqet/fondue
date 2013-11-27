#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 2101
using namespace std;

struct node{ int l,r,c; double s,ss;  }no[N<<3];
struct segment{ double x,y1,y2; int tag; }seg[N];

inline int L(int i){ return i<<1; } 
inline int R(int i){ return i<<1|1; }

double y[N];
int top,stop;

double len(int l,int r)
{
	return y[r-1]-y[l-1];
}

void build(int id,int l,int r)
{
	no[id].l=l,no[id].r=r,no[id].c=0,no[id].s=no[id].ss=0;
	if(l==r-1) return;
	int mid=(l+r)>>1;
	build(L(id),l,mid);
	build(R(id),mid,r);
}

void up(int id,int l,int r)
{
	if(no[id].c>0) no[id].s=len(l,r);
	else if(r==l+1) no[id].s=0;
	else no[id].s=no[L(id)].s+no[R(id)].s;

	if(no[id].c>1) no[id].ss=len(l,r);
	else if(r==l+1) no[id].ss=0;
	else if(no[id].c>0) no[id].ss=no[L(id)].s+no[R(id)].s;
	else no[id].ss=no[L(id)].ss+no[R(id)].ss;
}

void update(int id,int ll,int rr,int x)
{
	int l=no[id].l,r=no[id].r,mid=(l+r)>>1;
	if(l>=ll&&r<=rr)
	{
		no[id].c+=x;
		up(id,l,r);
		return;
	}
	if(mid>ll&&l<rr)
		update(L(id),ll,rr,x);
	if(mid<rr&&r>ll)
		update(R(id),ll,rr,x);
	up(id,l,r);
}

int cmp1(double a,double b){ return a<b; }
int cmp2(segment a,segment b){ return a.x==b.x?a.tag>b.tag:a.x<b.x; }

int getid(double x)
{
	int l=0,r=top-1,mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(x>y[mid])
			l=mid+1;
		else if(x<y[mid])
			r=mid-1;
		else
			return mid;
	}
	return -1; //impossible
}

int main()
{
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		top=0;
		stop=0;
		double x1,y1,x2,y2;
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
			seg[stop].x=x1,seg[stop].y1=y1,seg[stop].y2=y2,seg[stop++].tag=1;
			seg[stop].x=x2,seg[stop].y1=y1,seg[stop].y2=y2,seg[stop++].tag=-1;
			y[top++]=y1;
			y[top++]=y2;
		}
		sort(y,y+top,cmp1);
		sort(seg,seg+stop,cmp2);
		int ntop=1;
		for(int i=1; i<top; i++)
		{
			if(y[i]==y[ntop-1])
				continue;
			else
				y[ntop++]=y[i];
		}
		top=ntop;
		build(1,1,top);
		double nowx,prex=seg[0].x,ret=0,tmp;
		for(int i=0; i<stop; i++)
		{
			int l=getid(seg[i].y1)+1,r=getid(seg[i].y2)+1;
			nowx=seg[i].x;
			tmp=no[1].ss;
			ret+=tmp*(nowx-prex);
			prex=nowx;
			update(1,l,r,seg[i].tag);
		}
		printf("%.2lf\n",ret);
	}
	return 0;
}
