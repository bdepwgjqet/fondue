/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/25/2012 01:19:35 PM
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

LL dp[N][N];
LL ans[N];

LL dfs(int l,int r)
{
	LL ret=0;
	if(dp[l][r]>=0)	return dp[l][r];
	if(l==0)	return dp[l][r]=1;
	if(r==0)	return dp[l][r]=1;
	ret=(ret+dfs(l-1,r))%MOD;
	ret=(ret+dfs(l,r-1))%MOD;
	return dp[l][r]=ret;
}

void init()
{
	memset(dp,-1,sizeof(dp));
	for(int i=0; i<101; i++)
		dp[i][0]=dp[0][i]=1;
	dfs(100,100);
	memset(ans,0,sizeof(ans));
	for(int i=0; i<101; i++)
		for(int j=0; j<i; j++)
			ans[i]=(ans[i]+dp[j][i-j-1])%MOD;
}

int main()
{
	int n;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		cout<<ans[n]<<endl;
	}
	return 0;
}
