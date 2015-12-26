/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/12/2012 09:02:14 PM
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
#define N 33
#define X 1111
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

double dp[N][N],p[X][N],mat[X][N],sum[X][N];
int n,m,k;

int main()
{
	double ret,tmp;
	while(scanf("%d%d%d",&m,&n,&k)!=EOF)
	{
		if(n==0&&m==0&&k==0)
			break;
		memset(p,0,sizeof(p));
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				scanf("%lf",&mat[i][j]);
		for(int i=1; i<=n; i++)
		{
			dp[0][0]=1;
			for(int u=1; u<=m; u++)
				dp[u][0]=dp[u-1][0]*(1-mat[i][u]);
			for(int u=1; u<=m; u++)
				for(int v=1; v<=u; v++)
					dp[u][v]=dp[u-1][v-1]*mat[i][u]+dp[u-1][v]*(1-mat[i][u]);
			for(int u=0; u<=m; u++)
				p[i][u]=dp[m][u];
			sum[i][0]=0;
			for(int u=1; u<=m; u++)
				sum[i][u]=sum[i][u-1]+p[i][u];
		}
		ret=0,tmp=1;
		for(int i=1; i<=n; i++)
			tmp*=sum[i][m];
		ret=tmp;
		tmp=1;
		for(int i=1; i<=n; i++)
			tmp*=sum[i][k-1];
		ret-=tmp;
		printf("%.3f\n",ret);
	}
	return 0;
}
