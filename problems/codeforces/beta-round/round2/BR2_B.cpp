/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/19/2012 09:25:02 PM
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

int n,dir[2][N][N];
struct node{ int f,t; }dp[N<<1][N],mat[N][N];
inline int inboard(int x,int y)
{
	return 1<=x&&x<=n&&1<=y&&y<=n;
}

void show(int x,int y,int i)
{
	if(x==1&&y==1)
		return;
	if(dir[i][x][y]==1)
	{
		show(x,y-1,i);
		printf("R");
	}
	else
	{
		show(x-1,y,i);
		printf("D");
	}
}

int main()
{
	int tag,zx,zy;
	while(scanf("%d",&n)!=EOF)
	{
		int cnt;
		tag=0;
		for(int i=1; i<=2*n-1; i++)
			for(int j=1; j<=n; j++)
				dp[i][j].t=dp[i][j].f=inf;
		for(int i=1; i<=n; i++)
			for(int j=1; j<=n; j++)
			{
				int x;
				cnt=0;
				scanf("%d",&x);
				if(x==0)
				{
					mat[i][j].f=mat[i][j].t=0;
					tag=1;
					zx=i,zy=j;
					continue;
				}
				for(; (!(x&1))&&x>0; )
					x>>=1,cnt++;
				mat[i][j].t=cnt;
				cnt=0;
				for(; (x%5==0)&&(x>0);)
					x/=5,cnt++;
				mat[i][j].f=cnt;
			}
		int m,x,y,five,two,xx,yy,ni,nj;
		dp[1][1]=mat[1][1];
		for(int i=1; i<2*n-1; i++)
		{
			if(i>n)
				m=2*n-i,x=n,y=i-n+1;
			else
				m=i,x=i,y=1;
			for(int j=1; j<=m; j++)
			{
				five=dp[i][j].f,two=dp[i][j].t;
				xx=x+1,yy=y;
				if(i>=n)
					ni=i+1,nj=j-1;
				else
					ni=i+1,nj=j;
				if(inboard(xx,yy))
				{
					if(two+mat[xx][yy].t<dp[ni][nj].t)
						dp[ni][nj].t=two+mat[xx][yy].t,dir[0][xx][yy]=0;
					if(five+mat[xx][yy].f<dp[ni][nj].f)
						dp[ni][nj].f=five+mat[xx][yy].f,dir[1][xx][yy]=0;
				}
				xx=x,yy=y+1;
				if(i>=n)
					ni=i+1,nj=j;
				else
					ni=i+1,nj=j+1;
				if(inboard(xx,yy))
				{
					if(two+mat[xx][yy].t<dp[ni][nj].t)
						dp[ni][nj].t=two+mat[xx][yy].t,dir[0][xx][yy]=1;
					if(five+mat[xx][yy].f<dp[ni][nj].f)
						dp[ni][nj].f=five+mat[xx][yy].f,dir[1][xx][yy]=1;
				}
				x--,y++;
			}
		}
		int ret=inf;
		ret=min(ret,min(dp[2*n-1][1].t,dp[2*n-1][1].f));
		if(tag)
			ret=min(ret,1);
		printf("%d\n",ret);
		if(tag&&ret==1)
		{
			for(int i=1; i<zx; i++)
				printf("D");
			for(int i=1; i<zy; i++)
				printf("R");
			for(int i=zx; i<n; i++)
				printf("D");
			for(int i=zy; i<n; i++)
				printf("R");
		}
		else if(dp[2*n-1][1].f<dp[2*n-1][1].t)
			show(n,n,1);
		else
			show(n,n,0);
		puts("");
	}
	return 0;
}
