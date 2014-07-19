/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/31/2012 06:50:46 PM
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
#define N 310
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

int dp[N<<1][N][N],mat[N][N];

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
				scanf("%d",&mat[i][j]);
		for(int i=0; i<=2*n; i++)
			for(int j=0; j<=n; j++)
				for(int k=0; k<=n; k++)
					dp[i][j][k]=-inf;
		dp[0][1][1]=0;
		int ux,uy,vx,vy,tmp,m;
		for(int i=1; i<=2*n-1; i++)
		{
			if(i>n)
				m=2*n-i;
			else
				m=i;
			for(int u=1; u<=m; u++)
			{
				if(i<=n)
					ux=u,uy=i-u+1;
				else
					ux=i-n+u,uy=n-u+1;
				for(int v=1; v<=m; v++)
				{
					if(i<=n)
						vx=v,vy=i-v+1;
					else
						vx=i-n+v,vy=n-v+1;
					if(u==v)
						tmp=mat[ux][uy];
					else
						tmp=mat[ux][uy]+mat[vx][vy];
					for(int w=0; w<2; w++)
						for(int s=0; s<2; s++)
						{
							if(i<=n)
								dp[i][u][v]=max(dp[i][u][v],dp[i-1][u-w][v-s]+tmp);
							else
								dp[i][u][v]=max(dp[i][u][v],dp[i-1][u+w][v+s]+tmp);
						}
				}
			}
		}
		printf("%d\n",dp[2*n-1][1][1]);
	}
	return 0;
}
