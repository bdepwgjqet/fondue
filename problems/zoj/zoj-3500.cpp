#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;
const double pi=acos(-1);

double f(double r,double x)
{
	return pi*r*r*x-1.0/3*pi*x*x*x;
}

double cal(double x,double y,double z)
{
	return sqrt(x*x+y*y+z*z);
}

struct cir{ double x,y,z,r; }c[2];

double cccs(double r1,double r2,double d)
{
	return (r1*r1+d*d-r2*r2)/(2*r1*d);
}

int main()
{
	int ts;
	scanf("%d",&ts);
	while(ts--)
	{
		for(int i=0; i<2; i++)
			scanf("%lf%lf%lf%lf",&c[i].x,&c[i].y,&c[i].z,&c[i].r);
		double d=cal(c[0].x-c[1].x,c[0].y-c[1].y,c[0].z-c[1].z);
		double ret=0;
		for(int i=0; i<2; i++)
			ret+=4.0/3*pi*c[i].r*c[i].r*c[i].r;
		if(d>=c[0].r+c[1].r)
		{
			;
		}
		else if(min(c[0].r,c[1].r)+d<=max(c[0].r,c[1].r))
		{
			double r=min(c[0].r,c[1].r);
			ret-=4.0/3*pi*r*r*r;
		}
		else
		{
			double rr=f(c[0].r,c[0].r)-f(c[0].r,c[0].r*cccs(c[0].r,c[1].r,d));
			rr+=f(c[1].r,c[1].r)-f(c[1].r,c[1].r*cccs(c[1].r,c[0].r,d));
			ret-=rr;
		}
		printf("%.2lf\n",ret);
	}
	return 0;
}
