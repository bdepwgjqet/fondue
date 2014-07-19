#include <cstdio>
#include <cmath>
#include <algorithm>
#define N 50000

using namespace std;

int dat[N],dp[N][18],mi[N][18];

inline int B(int i){ return 1<<i; }
inline int big(int a,int b){ return a>b?a:b; }		//to be change
inline int small(int a,int b){ return a<b?a:b; }

void RMQ(int n)
{
	int k=int(log(1.0*n)/log(2.0));
	for(int i=1; i<=n; i++)
		dp[i][0]=mi[i][0]=dat[i];
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
