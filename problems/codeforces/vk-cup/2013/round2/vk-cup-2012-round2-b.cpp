/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/25/2012 10:42:33 PM
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
#define eps 1e-8
#define N 100010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct lem{ double v; int w,i; }le[N];
double max_t;
int n,k;
double h;

int cmp(lem a,lem b){ return a.w==b.w?a.v<b.v:a.w<b.w; }
int ret[N];

int can(int id,double t,int i)
{
	return i*h<t*le[id].v+eps;
}

int too_low(double t)
{
	int j=0,i;
	for(i=1; i<=k&&j<n; )
	{
		if(can(j,t,i))
			i++;
		j++;
	}
	if(i>k)	return 0;
	return 1;
}

double solve()
{
	double l,r,m;
	int i;
	for(l=0,r=max_t,i=0; i<100; i++)
	{
		m=(l+r)/2;
		int b=too_low(m);
		if(b)
			l=m;
		else
			r=m;
	}
	return r;
}

int main()
{
	while(scanf("%d%d%lf",&n,&k,&h)!=EOF)
	{
		max_t=0;
		for(int i=0; i<n; i++)
		{
			scanf("%d",&le[i].w);
			le[i].i=i;
		}
		for(int i=0; i<n; i++)
		{
			scanf("%lf",&le[i].v);
			max_t=max(max_t,k*h/le[i].v);
		}
		sort(le,le+n,cmp);
		double t=solve();
		int j=0;
		for(int i=1; i<=k&&j<n; j++)
			if(can(j,t,i))
			{
				ret[i]=le[j].i+1;
				i++;
			}
		for(int i=1; i<=k; i++)
			printf("%d ",ret[i]);
		puts("");
	}
	return 0;
}
