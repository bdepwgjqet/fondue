/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/16/2012 11:21:21 PM
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
#define N 70
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

int mat[N][N],dp[N][N][N];

int main()
{
	int n,m,r;
	while(scanf("%d%d%d",&n,&m,&r)!=EOF)
	{
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
		for(int k=0; k<n; k++)
			dp[i][j][k]=inf;
		for(int u=0; u<m; u++)
		{
			for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				scanf("%d",&mat[i][j]);
			for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
			for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				dp[i][j][0]=min(dp[i][j][0],mat[i][j]);
		}
		for(int k=1; k<n; k++)
		for(int u=0; u<n; u++)
		for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			dp[i][j][k]=min(dp[i][j][k],dp[i][u][k-1]+dp[u][j][0]);
		for(int i=0; i<r; i++)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			if(z>=n)
				z=n-1;
			printf("%d\n",dp[x-1][y-1][z]);
		}
	}
	return 0;
}
