/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/15/2012 08:00:24 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

LL dp[MAXN][MAXN];

LL dfs(int n,int k)
{
	int j,i=2*(k-1);
	LL ret=0;
	if(dp[n][k]>=0)	return dp[n][k];
	if(k==0)	return dp[n][k]=1;
	if(2*k>=n)	return dp[n][k]=0;
	for(j=n-2; j>=1&&j>i; j--)
	{
		ret=(ret+(n-j-1)*dfs(j,k-1))%MOD;
	}
	return dp[n][k]=ret;
}

int main()
{
	int n,m,k; LL ret;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		ret=dfs(n,k);
		memset(dp,-1,sizeof(dp));
		ret=ret*dfs(m,k)%MOD;
		cout<<ret<<endl;
	}
	return 0;
}
