/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:37:53 PM
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

double t[N],v[N];
double ret[N];
double a,d;

double calc(int i)
{
	double x=v[i]*v[i]/(2*a);
	if(x>d)
		return t[i]+sqrt((2*d)/a);
	return t[i]+d/v[i]+v[i]/(2*a);
}

int main()
{
	int n;
	while(scanf("%d%lf%lf",&n,&a,&d)!=EOF)
	{
		for(int i=0; i<n; i++)
			scanf("%lf%lf",&t[i],&v[i]);
		ret[0]=calc(0);
		for(int i=1; i<n; i++)
		{
			ret[i]=calc(i);
			if(ret[i]<ret[i-1])
				ret[i]=ret[i-1];
		}
		for(int i=0; i<n; i++)
			printf("%.10lf\n",ret[i]);
	}
	return 0;
}

