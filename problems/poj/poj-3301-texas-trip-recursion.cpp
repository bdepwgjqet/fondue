/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/09/2012 08:22:05 PM
 ***/

#include <cstring>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define N 1010
#define eps 1e-6
#define M 21
#define MAXM 1000010
#define inf 1e8
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline double max(double a,double b){ return a<b?b:a; }
inline double min(double a,double b){ return a<b?a:b; }
struct point{ double x,y; }p[100];

const double pi=acos(-1);

double cal(int n,double u)
{
	int i;
	double lx=inf,rx=-inf,uy=-inf,dy=inf,x,y;
	for(i=0; i<n; i++)
	{
		x=p[i].x*cos(u)-p[i].y*sin(u);
		y=p[i].y*cos(u)+p[i].x*sin(u);
		lx=min(lx,x);
		rx=max(rx,x);
		dy=min(dy,y);
		uy=max(uy,y);
	}
	return max(fabs(uy-dy),fabs(rx-lx));
}

double solve(int n)
{
	int i;
	double ret=inf,l=0,r=pi/2,u,v,best,tmp;
	for(i=0; i<M&&(r-l>eps); i++)
	{
		v=(r-l)/N;
		best=l;
		for(u=l; u<=r; u+=v)
		{
			tmp=cal(n,u);
			if(tmp<ret)	
				ret=tmp,best=u;
		}
		if(best>l)
			l=best-v;
		if(best<r)
			r=best+v;
		//printf("%lf %lf\n",l,r);
	}
	return ret*ret;
}

int main()
{
	int t,n,i;
	double ret;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(i=0; i<n; i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		ret=solve(n);
		printf("%.2f\n",ret);
	}
	return 0;
}
