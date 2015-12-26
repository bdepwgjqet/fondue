/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/13/2012 09:34:35 PM
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
#define X 5
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

int mat[370][X][X],dp[370][3][3][2401];
int dd[4][2]={{-1,-1},{-1,0},{0,-1},{0,0}};
int dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
int n,tmp[4];

int getid(int x,int y)
{
	if(x==0&&y==0)
		return 0;
	if(x==0&&y==3)
		return 1;
	if(x==3&&y==0)
		return 2;
	if(x==3&&y==3)
		return 3;
	return -1;
}

inline int inboard(int x,int y)
{
	return 1<=x&&x<=3&&1<=y&&y<=3;
}

int dfs(int lay,int x,int y,int st)
{
	int ss=st;
//	printf("%d %d %d %d\n",lay,x,y,st);
	if(lay==n)
		return dp[lay][x][y][st]=1;
	if(dp[lay][x][y][st]>0)
		return 1;
	else if(dp[lay][x][y][st]==0)
		return 0;
	for(int i=0; i<4; i++)
	{
		int xx=x+dd[i][0],yy=y+dd[i][1];
		if(mat[lay][xx][yy]==1)
			return dp[lay][x][y][st]=0;
	}
	for(int i=3; i>=0; i--)
	{
		tmp[i]=ss%7,ss/=7;
//		printf("%d ",tmp[i]);
	}
//	puts("=>");
	for(int i=0; i<4; i++)
	{
		tmp[i]++;
	}
	for(int i=0; i<4; i++)
	{
		int xx=x+dd[i][0],yy=y+dd[i][1];
		int id=getid(xx,yy);
		if(id<0)
			continue;
		tmp[id]=0;
	}
	for(int i=0; i<4; i++)
		if(tmp[i]>6)
			return dp[lay][x][y][st]=0;
	int ns=0;
	for(int i=0; i<4; i++)
		ns*=7,ns+=tmp[i];
	for(int k=0; k<=2; k++)
	{
		for(int i=0; i<4; i++)
		{
			int xx=x+k*dir[i][0],yy=y+k*dir[i][1];
			if(!inboard(xx,yy))
				continue;
			if(dfs(lay+1,xx,yy,ns))
				return dp[lay][x][y][st]=1;
		}
	}
	return dp[lay][x][y][st]=0;
}

int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		if(n==0)
			break;
		for(int i=0; i<n; i++)
			for(int u=0; u<4; u++)
				for(int v=0; v<4; v++)
					scanf("%d",&mat[i][u][v]);
		memset(dp,-1,sizeof(dp));
		if(dfs(0,2,2,0))
			puts("1");
		else
			puts("0");
	}
	return 0;
}
