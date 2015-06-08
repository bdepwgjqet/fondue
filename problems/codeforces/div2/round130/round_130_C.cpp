/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/23/2012 11:12:47 PM
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
#define N 111
#define M 1000010
#define S 1000100
#define eps 1e-8
#define inf 0x3fffff
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

int vis[N],mat[N][N],dis1[N],dis2[N];
double dp1[N],dp2[N];

void dijkstra(int dis[],double dp[],int n,int s)
{
	for(int i=0; i<n; i++)
		dp[i]=0,dis[i]=inf,vis[i]=0;
	dp[s]=1,dis[s]=0;
	int next;
	for(int i=0; i<n; i++)
	{
		next=-1;
		for(int j=0; j<n; j++)
			if(!vis[j]&&(next==-1||dis[j]<dis[next]))
				next=j;
		vis[next]=1;
		for(int j=0; j<n; j++)
		{
			if(!vis[j])
			{
				if(mat[next][j]+dis[next]<dis[j])
				{
					dis[j]=mat[next][j]+dis[next];
					dp[j]=dp[next];
				}
				else if(mat[next][j]+dis[next]==dis[j])
					dp[j]+=dp[next];
			}
		}
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				mat[i][j]=inf;
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			mat[x][y]=mat[y][x]=1;
		}
		dijkstra(dis1,dp1,n,0);
		dijkstra(dis2,dp2,n,n-1);
		double ret=0,tmp;
		for(int i=0; i<n; i++)
		{
			tmp=0;
			for(int u=0; u<n; u++)
				if(mat[i][u]<inf)
				{
					if(dis1[i]+dis2[u]+1==dis1[n-1])
						tmp+=1.0*dp1[i]*dp2[u];
					if(dis2[i]+dis1[u]+1==dis1[n-1])
						tmp+=1.0*dp1[u]*dp2[i];
				}
			ret=max(ret,tmp);
		}
		printf("%.12lf\n",ret/dp1[n-1]);
	}
	return 0;
}
