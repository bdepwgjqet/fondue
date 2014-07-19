/**
 *       compiler:  gcc
 *         author:  bdep__  
 *        created:  03/21/2012 06:59:31 pm
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define inf 1e8
#define eps 1e-8
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct point{ double x,y,z; }p1,p2,ans[N],py;
struct rectangle{ point l,r; }rec[N];

double xmult_x(point a,point b,point c)
{
	return (a.x-c.x)*(b.z-c.z)-(a.z-c.z)*(b.x-c.x); 
}
double xmult_y(point a,point b,point c)
{
	return (a.y-c.y)*(b.z-c.z)-(a.z-c.z)*(b.y-c.y); 
}

point get_point(int i,int v)
{
	if(v==0)	return rec[i].l;
	return rec[i].r;
}

int check_x(int i,int j,int n)
{
	for(int u=0; u<2; u++)
	{
		p1=get_point(i,u);
		for(int v=0; v<2; v++)
		{
			p2=get_point(j,v);
			int tag=0;
			for(int k=0; k<n; k++)
				if(xmult_x(rec[k].l,p2,p1)*xmult_x(rec[k].r,p2,p1)>eps)
					tag=1;
			if(tag==0)	return 1;
		}
	}
	return 0;
}

int exist_x(int n)
{
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			if(check_x(i,j,n))	return 1;
	return 0;
}

int check_y(int i,int n)
{
	point p0;
	p0.y=0,p0.z=0;
	for(int u=0; u<2; u++)
	{
		py=get_point(i,u);
		int tag=0;
		for(int k=0; k<n; k++)
			if(xmult_y(rec[k].l,py,p0)*xmult_y(rec[k].r,py,p0)>eps)
				tag=1;
		if(tag==0)	return 1;
	}
	return 0;
}

int exist_y(int n)
{
	for(int i=0; i<n; i++)
	{
		if(check_y(i,n))
			return 1;
	}
	return 0;
}


int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%lf%lf%lf%lf%lf",&rec[i].l.x,&rec[i].l.y,&rec[i].r.x,&rec[i].r.y,&rec[i].l.z);
			rec[i].r.z=rec[i].l.z;
		}
		if(exist_x(n))
		{
			if(exist_y(n))
			{
			//	printf("%lf %lf\n",p1.x,p1.y);
			//	printf("%lf %lf\n",p2.x,p2.y);
				double x0=(p1.x*p2.z-p1.z*p2.x)/(p2.z-p1.z);

				for(int i=0; i<n; i++)
				{
					ans[i].x=x0+rec[i].l.z*(p1.x-x0)/p1.z;
					ans[i].y=py.y*rec[i].l.z/py.z;
				}
				puts("SOLUTION");
				printf("%.6f\n",x0);
				for(int i=0; i<n; i++)
				{
					printf("%.6f %.6f %.6f\n",ans[i].x,ans[i].y,rec[i].l.z);
				}
			}
			else
				puts("UNSOLVABLE");
		}
		else
			puts("UNSOLVABLE");
	}
	return 0;
}
