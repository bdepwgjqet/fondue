/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/24/2012 12:01:55 AM
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
#define N 10000010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

LL dp[N],f[N];

int main()
{
	int n;
	dp[1]=0;
	dp[0]=1;
	f[0]=0;
	f[1]=1;
	for(int i=2; i<N; i++)
	{
		f[i]=(dp[i-1]+f[i-1]*2)%MOD;
		dp[i]=(3*f[i-1])%MOD;
	}
	while(scanf("%d",&n)!=EOF)
	{
		cout<<dp[n]<<endl;
	}
	return 0;
}


