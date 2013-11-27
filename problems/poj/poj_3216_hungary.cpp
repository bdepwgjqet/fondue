/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/12/2012 01:42:21 PM
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
#define N 210
#define M 1000010
#define S 80100
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

int mat[N][N];
struct task{ int p,t,d; }tsk[N];
struct edge{int f,t,n; }e[S];
int list[N],top,y[N],match[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void floyd(int n)
{
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(mat[i][k]+mat[k][j]<mat[i][j])
					mat[i][j]=mat[i][k]+mat[k][j];
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
	for(int i=0; i<n; i++)
	{
		memset(y,0,sizeof(y));
		if(find(i))
			ret++;
	}
	return ret;
}

int main()
{
	int q,m;
	while(scanf("%d%d",&q,&m)!=EOF)
	{
		if(q==0&&m==0)
			break;
		top=0;
		for(int i=0; i<m; i++)
			list[i]=-1;
		for(int i=0; i<q; i++)
			for(int j=0; j<q; j++)
			{
				scanf("%d",&mat[i][j]);
				if(mat[i][j]<0)
					mat[i][j]=inf;
			}
		floyd(q);
		for(int i=0; i<m; i++)
			scanf("%d%d%d",&tsk[i].p,&tsk[i].t,&tsk[i].d);
		for(int i=0; i<m; i++)
			for(int j=0; j<m; j++)
			{
				if(i==j)
					continue;
				int x=tsk[i].p,y=tsk[j].p;
				x--,y--;
				if(tsk[i].t+tsk[i].d+mat[x][y]<=tsk[j].t)
				{
					insert(i,j);
				}
			}
		printf("%d\n",m-hungary(m));
	}
	return 0;
}
