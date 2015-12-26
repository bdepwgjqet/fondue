/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/10/2012 11:03:17 AM
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
#define N 500010
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffffffffffffffLL
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

LL ret[N],top;

LL gcd(LL a,LL b){ return b?gcd(b,a%b):a; }

int ok(LL a,LL b,int l)
{
	if(l>50)	return 0;
	ret[l]=a;
	if(a>=inf+1||a<=0)
		return 0;
	if((a*b)%(a+b)==0)
	{
		top=l;
		return 1;
	}
	LL g=gcd(a,b);
	if(ok(a*(a/g-1),b,l+1))
		return 1;
	if(ok(a/g,b,l+1))
		return 1;
	return 0;
}

int main()
{
	int a,b;
	while(scanf("%d%d",&a,&b)!=EOF)
	{
		if(ok((LL)a,(LL)b,0))
		{
			for(int i=0; i<top; i++)
				printf("%lld ",ret[i]);
			printf("%lld\n",b);
		}
		else
			puts("0");
	}
	return 0;
}
