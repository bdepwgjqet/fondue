/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/20/2012 01:44:24 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-6
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

double x[3],y[3],r[3],a[2],b[2],c[2],d[2],xx0,yy0,k,aa,bb,cc,as,bs,cs,delta;
inline double f(double x){ return x*x; }

int main()
{
	for(int i=0; i<3; i++)
		scanf("%lf%lf%lf",&x[i],&y[i],&r[i]);
	for(int i=0; i<2; i++)
	{
		a[i]=f(r[2])-f(r[i]);
		b[i]=-2*f(r[2])*x[i]+2*f(r[i])*x[2];
		c[i]=-2*f(r[2])*y[i]+2*f(r[i])*y[2];
		d[i]=f(r[2])*(f(x[i])+f(y[i]))-f(r[i])*(f(x[2])+f(y[2]));
	}
	aa=b[0]*a[1]-b[1]*a[0];
	bb=c[0]*a[1]-c[1]*a[0];
	cc=d[0]*a[1]-d[1]*a[0];
	if(fabs(aa)<eps)
	{
		if(fabs(bb)<eps)
		{
			if(fabs(cc)<eps)
			{
				aa=c[0]*b[1]-c[1]*b[0];
				bb=d[0]*b[1]-d[1]*b[0];
				yy0=-bb/aa;
				xx0=(-d[0]-y[0]*c[0])/b[0];
				printf("%.12lf %.12lf\n",xx0,yy0);
				return 0;
			}
			else
				return 0;
		}
		else
		{
			xx0=0;
			yy0=-cc/bb;
		}
	}
	else if(fabs(bb)<eps)
	{
		yy0=0;
		xx0=-cc/aa;
	}
	else
	{
		xx0=0;
		yy0=-cc/bb;
	}
	if(fabs(a[0])<eps)
		a[0]=a[1],b[0]=b[1],c[0]=c[1],d[0]=d[1];
	as=a[0]*f(bb)+a[0]*f(aa);
	bs=-2*xx0*bb*a[0]+2*aa*yy0*a[0]-b[0]*bb+c[0]*aa;
	cs=d[0]+b[0]*xx0+c[0]*yy0+a[0]*f(xx0)+a[0]*f(yy0);
	delta=f(bs)-4*as*cs;
	double rx,ry,tx,ty;
	if(delta<-eps)
		return 0;
	else
	{
		k=(-bs-sqrt(fabs(delta)))/2/as;
		rx=xx0-bb*k,ry=yy0+aa*k;
		k=(-bs+sqrt(fabs(delta)))/2/as;
		tx=xx0-bb*k,ty=yy0+aa*k;
		if(f(rx-x[0])+f(ry-y[0])>f(tx-x[0])+f(ty-y[0]))
			rx=tx,ry=ty;
	}
	printf("%.12lf %.12lf\n",rx,ry);
	return 0;
}
