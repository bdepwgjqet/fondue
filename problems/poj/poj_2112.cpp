/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/10/2012 04:24:49 PM
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

struct edge{ int f,t,n; }e[S];
int list[N],top,y[N],match[N][N],cnt[N],lim[N];
int mat[N][N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

void floyd(int n)
{
	int i,j,k;
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if(mat[i][j]>mat[i][k]+mat[k][j])
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
			if(cnt[to]<lim[to])
			{
				match[to][cnt[to]++]=now;
				return 1;
			}
			for(int j=0; j<cnt[to]; j++)
				if(find(match[to][j]))
				{
					match[to][j]=now;
					return 1;
				}
		}
	}
	return 0;
}

int multi_hungary(int c,int k)
{
	int ret=0,n=c+k;
	memset(cnt,0,sizeof(cnt));
	for(int i=k; i<n; i++)
	{
		memset(y,0,sizeof(y));
		if(!find(i))
			return 0;
	}
	return 1;
}

int ok(double x,int k,int c)
{
	int n=k+c;
	top=0;
	for(int i=0; i<n; i++)
		list[i]=-1;
	for(int i=k; i<n; i++)
		for(int j=0; j<k; j++)
			if(mat[i][j]<=x)
				insert(i,j);
	return multi_hungary(c,k);
}

double solve(int k,int c)
{
	int n=k+c;
	double l=0.0,r=0.0,mid;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			r=max(r,double(mat[i][j]));
	/*
	for(int i=0; i<n; i++,puts(""))
		for(int j=0; j<n; j++)
			printf("%d ",mat[i][j]);
	printf("%lf %lf\n",l,r);
	*/
	r=20000;
	for(; r-l>eps;)
	{
		mid=(r+l)/2;
		if(ok(mid,k,c))
			r=mid;
		else
			l=mid;
	}
	return r;
}


int main()
{
	int k,c,li,n;
	while(scanf("%d%d%d",&k,&c,&li)!=EOF)
	{
		n=k+c;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			{
				scanf("%d",&mat[i][j]);
				if(mat[i][j]==0)
					mat[i][j]=inf;
			}
		for(int i=0; i<n; i++)
			lim[i]=li;
		floyd(n);
		double ret=solve(k,c);
		printf("%.0f\n",ret);
	}
	return 0;
}
