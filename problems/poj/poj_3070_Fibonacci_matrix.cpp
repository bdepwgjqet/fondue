/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/09/2012 06:23:14 PM
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
#define MAXN 1010
#define MAXM 1000010
#define MOD 10000
#define N 2

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

int A[N][N]={1,1,1,0},B[N][N],T[N][N];

void mul(int B[][N],int A[][N])
{
	int ret=0,i,j,k;
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			for(ret=k=0; k<N; k++)
				ret=(ret+B[i][k]*A[k][j])%MOD;
			T[i][j]=ret;
		}
	}
	for(i=0; i<N; i++)
		for(j=0; j<N; j++)
			B[i][j]=T[i][j];
}

void matrix_mul(int n)
{
	memset(B,0,sizeof(B));
	memset(A,0,sizeof(A));
	B[0][0]=B[1][1]=1;
	A[0][0]=A[0][1]=A[1][0]=1;
	for(; n>0;)
	{
		if(n&1)
			mul(B,A);
		n>>=1;
		mul(A,A);
	}
}

int cal(int n)
{
	matrix_mul(n-1);
	return B[0][0];
}

int main()
{
	int n,ret;
	while(scanf("%d",&n)&&(n>=0))
	{
		if(n<2)	
		{
			printf("%d\n",n);
			continue;
		}
		ret=cal(n);
		printf("%d\n",ret);
	}
	return 0;
}
