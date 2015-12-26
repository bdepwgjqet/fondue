/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/16/2012 11:05:30 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <sstream>
#include <cmath>
#include <functional>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int main()
{
	double x1,y1,x2,y2,r1,r2,l,t;
	while(scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2)!=EOF)
	{
		l=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
		if(r1>r2)
			t=r1,r1=r2,r2=t;
		if(r1+r2<=l)
			printf("%.20lf\n",(l-r1-r2)/2);
		else if(l<=r2-r1)
			printf("%.20lf\n",(r2-l-r1)/2);
		else
			printf("%.20lf\n",0.0);
	}
	return 0;
}
