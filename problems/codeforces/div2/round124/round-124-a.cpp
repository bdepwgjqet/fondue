/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/12/2012 08:59:09 PM
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
	int a,b,r;
	while(scanf("%d%d%d",&a,&b,&r)!=EOF)
	{
		int x,y;
		x=a/(2*r);
		y=b/(2*r);
		if(x==0||y==0)
			puts("Second");
		else
			puts("First");
	}
	return 0;
}
