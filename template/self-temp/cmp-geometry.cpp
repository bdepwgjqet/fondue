//求两直线交点，面积法
//须先判u1u2与v1v2是否平行
#include <cstdio>
#include <cmath>

typedef double elem_t;
struct point{ elem_t x,y; };

inline elem_t xmult(point a,point b,point c,point d)
{
	return (b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x);
}
point intersection(point a,point b,point c,point d)
{
	point ret=a;
	elem_t up,dw,t;
	up=xmult(c,d,c,a);
	dw=xmult(a,b,c,d);
	t=up/dw;
	ret.x+=(b.x-a.x)*t;
	ret.y+=(b.y-a.y)*t;
	return ret;
}


//判断点与任意多边形的关系
#include <cstdio>
#include <cmath>
#define MAXN 10001
#define eps 1e-8
typedef double elem_t;

struct point{ elem_t x,y; }p[MAXN];

inline int min(elem_t a,elem_t b){ return a<b?a:b; }
inline int max(elem_t a,elem_t b){ return a<b?b:a; }
inline double xmult(point a,point b,point c,point d)
{
	return (b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x);
}
inline int zero(double x){ return x>=-eps&&x<=eps;
}

int in_polygon(point a,int n,point p[],int on_edge)
{
	point low_p,high_p;
	int i,cnt=0;
	for(i=0; i<n; i++)
	{
		if(p[i].y<p[(i+1)%n].y)	low_p=p[i],high_p=p[(i+1)%n];
		else	high_p=p[i],low_p=p[(i+1)%n];
		if(xmult(a,low_p,a,high_p)>eps&&a.y>=low_p.y&&a.y<high_p.y)
			cnt++;
		else if(zero(xmult(a,low_p,a,high_p))&&a.y>=low_p.y&&a.y<=high_p.y&&a.x>=min(low_p.x,high_p.x)&&a.x<=max(low_p.x,high_p.x))
			return on_edge;
	}
	return cnt&1;
}
