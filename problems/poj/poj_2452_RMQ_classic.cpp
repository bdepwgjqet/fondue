/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/17/2012 10:39:15 AM
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
#define N 50100
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

int dat[N],dp[N][18],mi[N][18];

inline int B(int i){ return 1<<i; }
int big(int i,int j){ return dat[i]>dat[j]?i:j; }
int small(int i,int j){ return dat[i]<dat[j]?i:j; }

void RMQ(int n)
{
	int k=int(log(1.0*n)/log(2.0));
	for(int i=1; i<=n; i++)
		dp[i][0]=mi[i][0]=i;
	for(int j=1; j<=k; j++)
		for(int i=1; i<=n; i++)
		{
			if(i+B(j)-1>n)
				break;
			dp[i][j]=big(dp[i][j-1],dp[i+B(j-1)][j-1]);
			mi[i][j]=small(mi[i][j-1],mi[i+B(j-1)][j-1]);
		}
}

int query(int l,int r,int tag)
{
	int k=int(log(1.0*(r-l+1))/log(2.0));
	if(tag==1)
		return big(dp[l][k],dp[r-B(k)+1][k]);
	else
		return small(mi[l][k],mi[r-B(k)+1][k]);
}

int solve(int n)
{
	int ret=0,l,r,mid;
	for(int i=1; i<n; i++)
	{
		l=i+1,r=n;
		for(; l<=r; )
		{
			mid=(l+r)>>1;
			if(dat[query(i+1,mid,0)]>dat[i])
				l=mid+1;
			else
				r=mid-1;
		}
		if(r<=i)
			continue;
		ret=max(ret,query(i+1,r,1)-i);
	}
	if(ret<=0)
		return -1;
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		memset(dat,0,sizeof(dat));
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		RMQ(n);
		printf("%d\n",solve(n));
	}
	return 0;
}
