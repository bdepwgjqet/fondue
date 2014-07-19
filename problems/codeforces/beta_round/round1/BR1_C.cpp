/** *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/19/2012 07:41:22 PM
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
#define eps 1e-4
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

struct point{ double x,y; };
struct line{ point a,b; };

inline double xmult(point a,point b,point c,point d)
{
	return (b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x);
}

double len(point a,point b){ return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)); }

point inters(point a,point b,point c,point d)
{
	point ret=a;
	double up,dw,t;
	up=xmult(c,d,c,a);
	dw=xmult(a,b,c,d);
	t=up/dw;
	ret.x+=(b.x-a.x)*t;
	ret.y+=(b.y-a.y)*t;
	return ret;
}

point getp(point a,point b,point c){
	line u,v;
	u.a.x=(a.x+b.x)/2;
	u.a.y=(a.y+b.y)/2;
	u.b.x=u.a.x-a.y+b.y;
	u.b.y=u.a.y+a.x-b.x;
	v.a.x=(a.x+c.x)/2;
	v.a.y=(a.y+c.y)/2;
	v.b.x=v.a.x-a.y+c.y;
	v.b.y=v.a.y+a.x-c.x;
	return inters(u.a,u.b,v.a,v.b);
}

int main()
{
	point a,b,c,cen;
	double pi=acos(-1),r;
	while(scanf("%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y)!=EOF)
	{
		cen=getp(a,b,c);
		r=len(cen,a);
		double si,tmp;
		for(int i=3; i<=100; i++)
		{
			si=2*pi/i;
			tmp=2*asin(len(a,b)/2/r);
			tmp/=si;
			if(fabs(tmp-int(tmp+0.5))>eps)
				continue;
			tmp=2*asin(len(a,c)/2/r);
			tmp/=si;
			if(fabs(tmp-int(tmp+0.5))>eps)
				continue;
			printf("%.12lf\n",i*(r*r*sin(si)/2));
			break;
		}
	}
	return 0;
}
