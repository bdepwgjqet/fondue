/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/15/2012 01:37:57 PM
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
typedef long long LL;
#define MOD 1000000007LL
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)((a).size()))
#define ALL(a) (a).begin(),(a).end()
#define CLR(a,x) memset(a,x,sizeof(a))

using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

LL mat[2][2],now[2][2],tmp[2][2];

void m_mult(LL now[][2],LL mat[][2])
{
	int i,j;
	tmp[0][0]=(now[0][0]*mat[0][0]%MOD+now[0][1]*mat[1][0]%MOD)%MOD;
	tmp[1][0]=(now[1][0]*mat[0][0]%MOD+now[1][1]*mat[1][0]%MOD)%MOD;
	tmp[0][1]=(now[0][0]*mat[0][1]%MOD+now[0][1]*mat[1][1]%MOD)%MOD;
	tmp[1][1]=(now[1][0]*mat[0][1]%MOD+now[1][1]*mat[1][1]%MOD)%MOD;
	for(i=0; i<2; i++)
		for(j=0; j<2; j++)
			now[i][j]=tmp[i][j];
}

void matrix(LL n)
{
	LL x=n;
	memset(now,0,sizeof(now));
	now[0][0]=now[1][1]=1;
	for(; x; x>>=1)
	{
		if(x&1)
			m_mult(now,mat);
		m_mult(mat,mat);
	}
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			mat[i][j]=now[i][j];
}

LL fib(LL n)
{
	mat[0][0]=mat[0][1]=mat[1][0]=1;
	mat[1][1]=0;
	matrix(n-1);
	return (mat[1][0]+mat[1][1])%MOD;
}

LL solve(LL n)
{
	if(n<=0)	return 0LL;
	LL Q,R;
	Q=fib(2*n)*fib(2*n)%MOD;
	R=(fib(2*n+1)*fib(2*n+1)%MOD-1)%MOD;
	return (R-Q+MOD)%MOD;
}

int main()
{
	int q;
	LL x,y;
	scanf("%d",&q);
	while(q--)
	{
		cin>>x>>y;
	//	cout<<solve(x)<<" "<<solve(y)<<endl;
		cout<<(solve(y)-solve(x-1)+MOD)%MOD<<endl;
	}
	/*
	while(cin>>x)
	cout<<fib(x)<<endl;
	*/
	return 0;
}
