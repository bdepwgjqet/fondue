/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/15/2012 08:13:24 PM
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

LL f[N],d[N];

int main()
{
	int n;
	f[0]=d[0]=0;
	f[1]=2,d[1]=1;
	for(int i=2; i<21; i++)
	{
		f[i]=2*f[i-1]+2+d[i-1];
		d[i]=2*f[i-1]+1;
	}
	while(scanf("%d",&n)!=EOF)
		cout<<f[n]<<endl;
	return 0;
}


