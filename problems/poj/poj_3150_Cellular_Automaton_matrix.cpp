/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/09/2012 04:06:25 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 600
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

LL A[MAXN][MAXN],B[MAXN][MAXN],dat[MAXN],T[MAXN][MAXN];
int n;

void build(int d)
{
	int i,x,j;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			x=min(abs(i-j),n-abs(i-j));
			if(x<=d)
				A[i][j]=1;
			else
				A[i][j]=0;
			if(i==j)
				B[i][j]=1;
			else
				B[i][j]=0;
		}
	}
}

void mul(LL B[][MAXN],LL A[][MAXN],int m)
{
	int i,j;
	LL ret;
	for(j=0; j<n; j++)
	{
		for(ret=i=0; i<n; i++)
			ret=(ret+A[i][j]*B[0][i])%m;
		T[0][j]=ret;
	}
	for(i=0; i<n; i++)
		B[0][i]=T[0][i];
	for(i=1; i<n; i++)
		for(j=0; j<n; j++)
			B[i][j]=B[i-1][(j-1+n)%n];
}

void matrix_mul(int k,int m)
{
	for(; k>0; )
	{
		if(k&1)
			mul(B,A,m);
		k>>=1;
		mul(A,A,m);
	}
}

void solve(int m)
{
	int i,j;
	LL ret,ans[MAXN];
	for(i=0; i<n; i++)
	{
		for(ret=j=0; j<n; j++)
			ret=(ret+B[i][j]*dat[j])%m;
		ans[i]=ret;
	}
	for(i=0; i<n; i++)
		dat[i]=ans[i];
}

int main()
{
	int m,d,k,i;
	while(scanf("%d%d%d%d",&n,&m,&d,&k)!=EOF)
	{
		for(i=0; i<n; i++)
			scanf("%lld",&dat[i]);
		build(d);
		matrix_mul(k,m);
		solve(m);
		printf("%lld",dat[0]);
		for(i=1; i<n; i++)
			printf(" %lld",dat[i]);
		puts("");
	}
	return 0;
}


