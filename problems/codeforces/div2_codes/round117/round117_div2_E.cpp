/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/24/2012 10:57:34 PM
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
#define N 4010
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

int a[N],b[N],l,n;
int dp[110][2][N];

int dfs(int id,int cho,int ll)
{
	int ret=0,ppp,pre;
	if(id==-1)
		ppp=101;
	else
		ppp=id;
	if(id==-1)
		pre=101;
	else if(cho==0)
		pre=a[id];
	else
		pre=b[id];
//	printf("%d %d %d %d %d\n",ppp,id,cho,ll,l);
	if(ll>l)
		return dp[ppp][cho][ll]=0;
	if(ll==l)
		return dp[ppp][cho][ll]=1;
	if(dp[ppp][cho][ll]>=0)
		return dp[ppp][cho][ll];
	for(int i=0; i<n; i++)
		if(i!=id)
		{
			if(id==-1)
			{
				ret=(ret+dfs(i,1,ll+a[i]))%MOD;
				if(a[i]==b[i])	continue;
				ret=(ret+dfs(i,0,ll+b[i]))%MOD;
				continue;
			}
			if(a[i]==pre)
			{
				ret=(ret+dfs(i,1,ll+a[i]))%MOD;
			}
			else if(b[i]==pre)
			{
				ret=(ret+dfs(i,0,ll+b[i]))%MOD;
			}
		}
	return dp[ppp][cho][ll]=ret;
}

int main()
{
	while(scanf("%d%d",&n,&l)!=EOF)
	{
		memset(dp,-1,sizeof(dp));
		for(int i=0; i<n; i++)
			scanf("%d%d",&a[i],&b[i]);
		printf("%d\n",dfs(-1,0,0));
	}
	return 0;
}
