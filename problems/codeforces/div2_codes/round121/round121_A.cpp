/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/29/2012 03:51:16 PM
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

int _ok(LL n)
{
	LL x=(LL)sqrt(2.0*n);
	for(; x*(x-1)<=2*n; x++) 
	{
		if(x*(x-1)==2*n)
			return 1;
	}
	return 0;
}

int ok(LL n)
{
	for(LL k=1; ; k++)
	{
		LL x=k*(k+1)/2;
		if(x>=n)
			break;
		if(_ok(n-x))
			return 1;
	}
	return 0;
}

int main()
{
	LL n;
	while(cin>>n)
	{
		if(ok(n))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
