/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/24/2012 12:14:24 AM
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
#define N 101000
#define M 1000010
#define inf 0x7fffffff
#define S 1000100
#define eps 1e-8
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct point{ LL x,y; }p[N],q[N];

inline LL min(LL a,LL b){ return a<b?a:b; }
inline LL max(LL a,LL b){ return a<b?b:a; }
inline LL xmult(point a,point b,point c)
{
	return (a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x);
}

int in_polygon(point a,int n,point p[])
{
	int l=1,r=n-1,m; 
	if(xmult(p[0],p[n-1],a)<=0||xmult(p[1],p[0],a)<=0)
		return 0;
	else
		for(; l<=r; )
		{
			m=(l+r)>>1;
			if(xmult(a,p[m],p[0])>=0)
				l=m+1;
			else
				r=m-1;
		}
	//printf("%d\n",l-1);
	return xmult(p[l-1],p[l],a)<0;
}

int put_YES(int n,int m)
{
	for(int i=0; i<m; i++)
	{
		if(in_polygon(q[i],n,p)==0)
			return 0;
	}
	return 1;
}

int main()
{
	int n,m;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
	//		scanf("%lld%lld",&p[i].x,&p[i].y);
			scanf("%I64d%I64d",&p[i].x,&p[i].y);
		}
		scanf("%d",&m);
		for(int i=0; i<m; i++)
		{
	//		scanf("%lld%lld",&q[i].x,&q[i].y);
			scanf("%I64d%I64d",&q[i].x,&q[i].y);
		}
		if(put_YES(n,m))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}


