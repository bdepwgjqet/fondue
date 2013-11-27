/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/12/2012 07:12:43 PM
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
#define eps 1e-6
#define inf 1e8
#define MOD 1000000007
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

typedef long long LL;
using namespace std;

struct point{ double x,y,z; }p[N];
double dis[N][N],cost[N][N],mat[N][N],min_l[N],vis[N];

inline double length(double x,double y,double a,double b)
{
	return sqrt((x-a)*(x-a)+(y-b)*(y-b));
}

double mst(int n,double k)
{
	double ret=0;
	for(int i=0; i<n; i++)
		min_l[i]=inf,vis[i]=0;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		{
			mat[j][i]=mat[i][j]=cost[i][j]-k*dis[i][j];
		}
	int nx,j;
	min_l[0]=0;
	for(int i=0; i<n; i++)
	{
		for(nx=-1,j=0; j<n; j++)
			if(!vis[j]&&(nx==-1||(min_l[j]<min_l[nx])))
				nx=j;
		vis[nx]=1;
		for(ret+=min_l[nx],j=0; j<n; j++)
			if(!vis[j]&&min_l[j]>mat[nx][j])
				min_l[j]=mat[nx][j];
	}
	return ret;
}

double solve(int n)
{
	double l=0,r=inf,mid,maxcost=-inf,mindis=inf,maxdis=-inf,mincost=inf;
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
		{
			maxcost=max(cost[i][j],maxcost);
			mindis=min(mindis,dis[i][j]);
			maxdis=max(dis[i][j],maxdis);
			mincost=min(mincost,cost[i][j]);
		}
	l=mincost/maxdis;
	r=maxcost/mindis;
	for(; r-l>eps;)
	{
		mid=(r+l)/2;
		if(mst(n,mid)>0.0)
			l=mid;
		else
			r=mid;
	}
	return r;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0) break;
		for(int i=0; i<n; i++)
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
			{
				if(i==j) continue;
				cost[i][j]=cost[j][i]=fabs(p[i].z-p[j].z);
				dis[i][j]=dis[j][i]=length(p[i].x,p[i].y,p[j].x,p[j].y);
			}
		printf("%.3f\n",solve(n));
	}
	return 0;
}
