/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/14/2012 07:35:52 PM
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

double dp[N][N][2];

double dfs(int w,int b,int u)
{
	//printf("%d %d %d %lf\n",w,b,u,dp[w][b][u]);
	if(dp[w][b][u]>=0)
		return dp[w][b][u];
	double ret=0;
	if(w==0)
		return dp[w][b][u]=0;
	if(u==0)
	{
		ret+=1.0*w/(w+b);
		if(b>0)
			ret+=1.0*b/(w+b)*dfs(w,b-1,u^1);
	}
	else
	{
		if(b>0)
		{
			ret+=1.0*b/(w+b)*w/(w+b-1)*dfs(w-1,b-1,u^1);
			if(b>1)
				ret+=1.0*b/(w+b)*(b-1)/(w-1+b)*dfs(w,b-2,u^1);
		}
	}
	return dp[w][b][u]=ret;
}

int main()
{
	int w,b;
	scanf("%d%d",&w,&b);
	for(int i=0; i<=w; i++)
		for(int j=0; j<=b; j++)
			dp[i][j][0]=dp[i][j][1]=-1;
	printf("%.9lf\n",dfs(w,b,0));
	return 0;
}
