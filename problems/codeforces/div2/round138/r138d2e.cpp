/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/17/2012 10:17:45 AM
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
#define N 2010
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

int mat[N][N],tmp[N][N],ret[N][N];
int dat[N];

void show(int mat[][N],int n)
{
	for(int i=0; i<n; i++,puts(""))
		for(int j=0; j<n; j++)
			printf("%d ",mat[i][j]);
	puts("");
}

inline int mul(int a,int b)
{
	return int(LL(a)*b%MOD);
}

void mul(int c[][N],int a[][N],int b[][N],int n)
{
	int i,k,j;
	for(i=0; i<n; i++)
	{
		tmp[i][0]=0;
		for(k=0; k<=i; k++)
		{
			tmp[i][0]+=mul(a[i][k],b[k][0]);

			if(tmp[i][0]>MOD)
				tmp[i][0]-=MOD;
		}
	}

	for(j=1; j<n; j++)
		for(i=j; i<n; i++)
			tmp[i][j]=tmp[i-1][j-1];
	for(i=0; i<n; i++)
		for(j=0; j<=i; j++)
			c[i][j]=tmp[i][j];
}

void solve(int n,int k)
{
	memset(ret,0,sizeof(ret));
	for(int i=0; i<n; i++)
		ret[i][i]=1;
	for(; k; )
	{
		if(k&1)
		{
			mul(ret,ret,mat,n);
		}
		mul(mat,mat,mat,n);
		k>>=1;
	}
}

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++)
		for(int j=0; j<=i; j++)
			mat[i][j]=1;
	for(int i=0; i<n; i++)
		scanf("%d",&dat[i]);
	solve(n,k);
	int ans;
	for(int i=0; i<n; i++)
	{
		ans=0;
		for(int j=0; j<=i; j++)
		{
			ans=ans+mul(ret[i][j],dat[j]);
			if(ans>MOD)
				ans-=MOD;
		}
		printf("%d ",ans);
	}
	puts("");

	return 0;
}
