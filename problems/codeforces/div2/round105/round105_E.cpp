/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/14/2012 08:10:12 PM
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

int dp[111][11000],n,dat[111][111],lsum[111][111],rsum[111][111],best_s[111][111];

int dfs(int id,int m)
{
	int ret=0,a,b;
	if(dp[id][m]>=0)
		return dp[id][m];
	if(id==n)
		return dp[id][m]=0;
	if(m==0)
		return dp[id][m]=0;
	for(int i=0; i<=dat[id][0]&&i<=m; i++)
		ret=max(ret,dfs(id+1,m-i)+best_s[id][i]);
	return dp[id][m]=ret;
}

int main()
{
	int m,tmp=0;
	memset(dp,-1,sizeof(dp));
	scanf("%d%d",&n,&m);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&dat[i][0]);
		lsum[i][0]=0;
		rsum[i][dat[i][0]+1]=0;
		for(int j=1; j<=dat[i][0]; j++)
		{
			scanf("%d",&dat[i][j]);
			lsum[i][j]=lsum[i][j-1]+dat[i][j];
		}
		for(int j=dat[i][0]+1; j>=1; j--)
			rsum[i][j]=rsum[i][j+1]+dat[i][j];
	}
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=dat[i][0]; j++)
		{
			tmp=0;
			for(int k=0; k<=j; k++)
				tmp=max(tmp,lsum[i][k]+rsum[i][dat[i][0]+1-j+k]);
			best_s[i][j]=tmp;
		}
	}
	/*
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<=dat[i][0]; j++)
			printf("%d ",lsum[i][j]);
		puts("");
		for(int j=dat[i][0]+1; j>=1; j--)
			printf("%d ",rsum[i][j]);
		puts("");
	}
	*/
	printf("%d\n",dfs(0,m));
	return 0;
}
