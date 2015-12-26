/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/09/2012 03:06:52 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define eps 1e-6
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
inline int cmp(double a,double b){ return a>b; }

double tmp[MAXN],a[MAXN],b[MAXN];

int too_small(double x,int k,int n)
{
	int i; double ret=0;
	for(i=0; i<n; i++)
		tmp[i]=a[i]-x*b[i];
	sort(tmp,tmp+n,cmp);
	for(i=0; i<k; i++)
		ret+=tmp[i];
	return ret>0?1:0;
}

int main()
{
	int n,k,i;
	double l,r,m;
	while(scanf("%d%d",&n,&k)&&(n||k))
	{
		for(i=0; i<n; i++)
			scanf("%lf",&a[i]);
		for(i=0; i<n; i++)
			scanf("%lf",&b[i]);
		for(l=0,r=1; r-l>=eps; )
		{
			m=(l+r)/2;
			if(too_small(m,n-k,n))
				l=m;
			else
				r=m;
		}
		m=(l+r)/2;
		printf("%.0f\n",m*100);
	}
	return 0;
}
