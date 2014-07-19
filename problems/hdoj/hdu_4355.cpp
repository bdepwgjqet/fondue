#include <cstdio>
#include <cmath>
#define eps 1e-4
#define N 50011

struct node{ double x,w; }no[N];

double get(double x,int n)
{
	double ret=0,d;
	for(int i=1; i<=n; i++)
	{
		d=fabs(no[i].x-x);
		ret+=d*d*d*no[i].w;
	}
	return ret;
}

double solve(int n)
{
	double l=no[1].x,r=no[n].x,m1,m2,f1,f2;
	for(; r-l>eps; )
	{
		m1=(2*l+r)/3;
		m2=(l+2*r)/3;
		f1=get(m1,n);
		f2=get(m2,n);
		if(f1<=f2)
			r=m2;
		else if(f1>f2)
			l=m1;
	}
	return get(l,n);
}

int main()
{
	int t,ca=1,n;
	scanf("%d",&t);
	for(; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
			scanf("%lf%lf",&no[i].x,&no[i].w);
		printf("%.0lf\n",solve(n));
	}
	return 0;
}
