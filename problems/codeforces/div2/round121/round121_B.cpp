/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/29/2012 04:09:44 PM
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

int dat[N];

int main()
{
	int n,ret;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
		scanf("%d",&dat[i]);
	ret=min(dat[0],dat[n-1]);
	for(int i=1; i<n-1; i++)
		ret=min(ret,max(dat[i],dat[i+1]));
	printf("%d\n",ret);
	return 0;
}
