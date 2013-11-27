/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 09:33:34 AM
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
#define N 201000
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

double p[N],pp[N];

int main()
{
	int a,b,t,ca;
	double ret=inf,tmp;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		printf("Case #%d: ",ca);
		scanf("%d%d",&a,&b);
		ret=inf;
		pp[0]=1;
		for(int i=1; i<=a; i++)
		{
			scanf("%lf",&p[i]);
			pp[i]=p[i]*pp[i-1];
		}
		ret=pp[a]*(b-a+1)+(1-pp[a])*(2*(b+1)-a);
		ret=min(ret,1.0*(b+2));
		for(int i=1; i<=a; i++)
			ret=min(ret,pp[a-i]*(2*i+b-a+1)+(1-pp[a-i])*(2*i+2*b-a+2));
		printf("%.6lf\n",ret);
	}
	return 0;
}
