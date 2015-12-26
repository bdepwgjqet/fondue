/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 02:47:57 PM
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
#define N 10100
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

int dp[202][11][11][11][11],m,n,p,T;
char mat[11][11];

struct shuijing
{
	int x,y,v,t;
}ji[N];

int val[220][11][11];

int dir[5][2]={{1,0},{-1,0},{0,1},{0,-1},{0,0}};

int inboard(int x,int y)
{
	return 0<=x&&x<m&&y<n&&0<=y&&mat[x][y]!='#';
}

int dfs(int t,int x,int y,int u,int v)
{
	int ret=0;
	if(dp[t][x][y][u][v]>=0)
		return dp[t][x][y][u][v];
	if(t==T)
		return dp[t][x][y][u][v]=0;
	for(int i=0; i<5; i++)
	{
		int nx=x+dir[i][0],ny=y+dir[i][1];
		if(!inboard(nx,ny))
			continue;
		for(int j=0; j<5; j++)
		{
			int nu=u+dir[j][0],nv=v+dir[j][1];
			if(!inboard(nu,nv))
				continue;
		//	printf("%d %d %d %d %d\n",t,nx,ny,nu,nv);
			int tmpv=0;
			tmpv+=val[t+1][nx][ny];
			if(!(nx==nu&&ny==nv))
				tmpv+=val[t+1][nu][nv];
			ret=max(ret,dfs(t+1,nx,ny,nu,nv)+tmpv);
		}
	}
	return dp[t][x][y][u][v]=ret;
}

int main()
{
	int t,ca;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		memset(val,0,sizeof(val));
		memset(dp,-1,sizeof(dp));
		scanf("%d%d",&m,&n);
		for(int i=0; i<m; i++)
			scanf("%s",mat[i]);
		scanf("%d",&p);
		T=0;
		for(int i=0; i<p; i++)
		{
			int x,y,tt,vv;
			scanf("%d%d%d%d",&tt,&x,&y,&vv);
			x--,y--;
			val[tt][x][y]+=vv;
			T=max(T,tt);
		}
		printf("%d\n",dfs(0,0,0,0,0));
	}
	return 0;
}
