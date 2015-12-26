#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 51000
#define eps 1e-10

using namespace std;

struct node{ double x,y,yy; }no[N];
struct seg{ double x,y; }seg[N];

const double inf=10000000;

int cmp(node a,node b){ return a.y>b.y; }

int n;

int ok(double R,double &p)
{
	double rr=R*R,d,l,r;
	if(no[0].y>R)
		return 0;
	d=sqrt(rr-no[0].yy);
	l=no[0].x-d;
	r=no[0].x+d;
	for(int i=1; i<n; i++)
	{
		if(no[i].y>R)
			return 0;
		d=sqrt(rr-no[i].yy);
		l=max(l,no[i].x-d);
		r=min(r,no[i].x+d);
		if(l>r)
			return 0;
	}
	p=(l+r)*0.5;
	return 1;
}

double gao()
{
	double l=0,r=inf,m,p;
	for(; r-l>eps;)
	{
		m=(l+r)*0.5;
		if(ok(m,p))
			r=m;
		else
			l=m;
	}
	ok((l+r)*0.5,p);
	return p;
}

int main()
{
	int T;
	scanf("%d",&T);
	for(int ca=1; ca<=T; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf",&no[i].x,&no[i].y);
			no[i].yy=no[i].y*no[i].y;
		}
		sort(no,no+n,cmp);
		printf("%.6lf\n",gao());
	}
	return 0;
}
