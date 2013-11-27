/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/10/2012 10:32:43 AM
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
#define N 100010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 1e12
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

struct line{ double k,b; }l[N];
int cmp(line a,line b){ return a.b==b.b?a.k<b.k:a.b<b.b; }

int main()
{
	int n;
	double x1,y1,x2,y2;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
		l[i].k=(y2-y1)/(x2-x1);
		l[i].b=-x1*l[i].k+y1;
	}
	sort(l,l+n,cmp);
	for(int i=0; i<n; i++)
	{
		double ret=-inf;
		for(int j=0; j<n; j++)
		{
			if(i==j)	continue;
			if(l[i].k==l[j].k)	continue;
			ret=max(ret,(l[j].b-l[i].b)/(l[i].k-l[j].k));
		}
		printf("%.2lf\n",ret);
	}
	return 0;
}
