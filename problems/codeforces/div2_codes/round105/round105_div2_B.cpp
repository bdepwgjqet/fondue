/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:45:20 PM
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
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int main()
{
	double f,c,t,a,b,l; int ret=0;
	while(scanf("%lf%lf%lf%lf%lf",&a,&b,&t,&f,&c)!=EOF)
	{
		l=a*t;
		ret=0;
		for(; l<c&&a<b; )
		{
			double x=l/(b-a);
			if(l+a*x>=c)	break;
			ret++;
			l=l+a*(x+f+x);
		}
		printf("%d\n",ret);
	}
	return 0;
}
