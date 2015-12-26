#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#define eps 1e-8
#define inf 100000000 
#define MAXN 50100
using std::sort;
typedef double elem_t;

struct point{ elem_t x,y; }p1,p[MAXN],converx[MAXN];
inline elem_t max(elem_t a,elem_t b){ return a>b?a:b; }
inline int zero(elem_t x){ return x>=-eps&&x<=eps; }

inline elem_t len(point a,point b)
{
	return sqrt((b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y));
}
inline elem_t xmult(point a,point b,point c)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

int cmp(point a,point b)
{
	elem_t x;
	x=xmult(a,b,p1);
	if(zero(x))	
		return len(a,p1)<len(b,p1);
	return x>0;
}

int _converx(int n,point p[],point con[])
{
	int i,s;
	p1.x=p1.y=inf;
	for(i=0; i<n; i++)
	{
		if(p[i].y<p1.y)	
			p1=p[i];
		else if(p[i].y==p1.y&&p[i].x<p1.x)
			p1=p[i];
	}
	sort(p,p+n,cmp);
	con[0]=p[0],con[1]=p[1],s=2;
	for(i=0; i<n; con[s++]=p[i++])
	for(; s>1&&xmult(con[s-1],p[i],con[s-2])<=eps; s--);
	//改为<-eps可保留共线点
	return s;
}
