/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:38:02 PM
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
#define N 210
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

double dp[N][N][N];
int n,l,k;
struct node{ double p; int a; }to[N];
int cmp(node a,node b){ return a.a>b.a; }

double dfs(int i,int cnt,int v)
{
	if(v>200)	v=200;
	double ret=0;
	if(i==n-1)
	{
		if(v+to[i].a>=0&&cnt+1>=l)
			ret+=to[i].p;
		if(cnt>=l)
			ret+=1-to[i].p;
		return dp[i][cnt][v]=ret;
	}
	if(dp[i][cnt][v]>=0)
		return dp[i][cnt][v];
	if(v+to[i].a>=0)
		ret+=to[i].p*dfs(i+1,cnt+1,v+to[i].a);
	ret+=(1-to[i].p)*dfs(i+1,cnt,v);
	return dp[i][cnt][v]=ret;
}

int main()
{
	while(scanf("%d%d%d",&n,&l,&k)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%lf",&to[i].p);
			to[i].p/=100;
		}
		for(int i=0; i<n; i++)
			scanf("%d",&to[i].a);
		sort(to,to+n,cmp);
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				for(int t=0; t<N; t++)
					dp[i][j][t]=-1;
		printf("%.12lf\n",dfs(0,0,k));
	}
	return 0;
}


