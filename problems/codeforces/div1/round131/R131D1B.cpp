/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/31/2012 12:45:25 AM
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
#define N 110
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

LL c[N][N],dp[N][N];
int a[10];

void solve()
{
	memset(c,0,sizeof(c));
	c[0][0]=1,c[1][1]=1,c[1][0]=1;
	for(int i=2; i<N; i++)
	{
		c[i][0]=1;
		for(int j=1; j<i; j++)
			c[i][j]=(c[i-1][j]+c[i-1][j-1])%MOD;
		c[i][i]=1;
	}
	memset(dp,0,sizeof(dp));
	for(int i=0; i<N; i++)
	{
		if(i<a[1])
			continue;
		dp[1][i]=1;
	}
	int ttl=0;
	for(int i=1; i<10; i++)
	{
		ttl+=a[i];
		if(ttl==0)
			dp[i][0]=1;
	}
	ttl+=a[0];
	if(ttl==0)
		dp[0][0]=1;
	ttl=a[1];
	for(int i=2; i<10; i++)
	{
		for(int j=1; j<N; j++)
		{
			for(int k=ttl; k<=j; k++)
			{
				if(j-k<a[i])
					continue;
				dp[i][j]=(dp[i][j]+dp[i-1][k]*c[j][j-k])%MOD;
			}
		}
		ttl+=a[i];
	}
	for(int j=1; j<N; j++)
	{
		for(int k=ttl; k<=j; k++)
		{
			if(k==0)
				continue;
			if(j-k>=a[0])
				dp[0][j]=(dp[0][j]+dp[9][k]*c[j-1][j-k])%MOD;
		}
	}
}

int main()
{
	int n,ttl,eze;
	while(scanf("%d",&n)!=EOF)
	{
		ttl=0;
		for(int i=0; i<10; i++)
		{
			scanf("%d",&a[i]);
			ttl+=a[i];
		}
		solve();
		LL ret=0;
		eze=ttl-a[0];
		for(int i=ttl; i<=n; i++)
		{
			if(i==0) continue;
				ret=(ret+dp[0][i])%MOD;
		}
		cout<<((ret%MOD)+MOD)%MOD<<endl;
	}
	return 0;
}
