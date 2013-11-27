/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/12/2012 02:28:46 PM
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
#define N 1031
#define M 1100010
#define S 1100100
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

struct edge{ int f,t,n; }e[S];
int mat[N][N],m,n,list[N],top,match[N],y[N],dir[4][2]={{1,0},{-1,0},{0,-1},{0,1}};
int poi[N],pt;

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int inboard(int x,int y)
{
	return 0<=x&&x<m&&0<=y&&y<n;
}

int find(int now)
{
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!y[to])
		{
			y[to]=1;
			if(match[to]<0||find(match[to]))
			{
				match[to]=now;
				return 1;
			}
		}
	}
	return 0;
}

int hungary(int n)
{
	int ret=0;
	memset(match,-1,sizeof(match));
	for(int i=0; i<pt; i++)
	{
		memset(y,0,sizeof(y));
		if(find(poi[i]))
			ret++;
	}
	return ret;
}

int main()
{
	int k;
	while(scanf("%d%d%d",&m,&n,&k)!=EOF)
	{
		top=0;
		pt=0;
		for(int i=0; i<m*n; i++)
			list[i]=-1;
		memset(mat,0,sizeof(mat));
		for(int i=0; i<k; i++)
		{
			int x,y;
			scanf("%d%d",&y,&x);
			x--,y--;
			mat[x][y]=1;
		}
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				if(mat[i][j]==0)
					poi[pt++]=i*m+j;
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
			{
				int f=i*m+j,t;
				if(mat[i][j])
					continue;
				for(int d=0; d<4; d++)
				{
					int x=i+dir[d][0],y=j+dir[d][1];
					if(inboard(x,y)&&!mat[x][y])
					{
						t=x*m+y;
						insert(f,t);
					}
				}
			}
		int pi=hungary(m*n-k);
		if(pi==m*n-k)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
