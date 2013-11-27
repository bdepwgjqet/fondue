/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/19/2012 11:33:16 PM
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
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007
#define N 201

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
inline int lower_bound(int x){ return x&(-x); }
int cmp(int a,int b){ return a<b; }

struct point{ double x,y; }p[N],tmpp[N],retp[N];

int rtop,ttop;
double a,b,c;
inline double f(double x,double y){ return a*x+b*y+c; }

void get_line(int i)
{
	a=p[i+1].y-p[i].y;
	b=p[i].x-p[i+1].x;
	c=p[i+1].x*p[i].y-p[i+1].y*p[i].x;
}

inline double xmult(point a,point b,point c,point d)
{
	return (b.x-a.x)*(d.y-c.y)-(b.y-a.y)*(d.x-c.x);
}

point intersection(point a,point b,point c,point d)
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

void cut(int id)
{
	int i;
	get_line(id);
	ttop=1;
	for(i=1; i<=rtop; i++)
	{
		if(f(retp[i].x,retp[i].y)>=0)
			tmpp[ttop++]=retp[i];
		else
		{
			if(f(retp[i-1].x,retp[i-1].y)>=0)
				tmpp[ttop++]=intersection(p[id],p[id+1],retp[i],retp[i-1]);
			if(f(retp[i+1].x,retp[i+1].y)>=0)
				tmpp[ttop++]=intersection(p[id],p[id+1],retp[i],retp[i+1]);
		}
	}
	tmpp[0]=tmpp[ttop-1],tmpp[ttop]=tmpp[1];
	for(i=0; i<=ttop; i++)
		retp[i]=tmpp[i];
	rtop=ttop-1;
}

int main()
{
	int n,t,i;
	scanf("%d",&t);
	for(; t--; )
	{
		scanf("%d",&n);
		for(i=1; i<=n; i++)
		{
			scanf("%lf%lf",&p[i].x,&p[i].y);
		}
		p[n+1]=p[1];
		p[0]=p[n];
		for(i=0; i<=n+1; i++)
			retp[i]=p[i];
		rtop=n;
		for(i=1; i<=n&&rtop>0; i++)
			cut(i);
		if(rtop<=0)	puts("NO");
		else	puts("YES");
	}
	return 0;
}


