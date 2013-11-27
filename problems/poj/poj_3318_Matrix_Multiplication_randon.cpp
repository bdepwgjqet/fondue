/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/09/2012 09:30:40 PM
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

int A[MAXN][MAXN],B[MAXN][MAXN],C[MAXN][MAXN],x[MAXN],l[MAXN],r[MAXN],n,tmp[MAXN];

void cal(int ret[],int x[],int A[][MAXN])
{
	int i,res,j;
	for(i=0; i<n; i++)
	{
		for(res=j=0; j<n; j++)
			res+=x[j]*A[j][i];
		tmp[i]=res;
	}
	for(i=0; i<n; i++)
		ret[i]=tmp[i];
}

int the_same()
{
	int i;
	for(i=0; i<n; i++)
		if(l[i]!=r[i])
			return 0;
	return 1;
}

int main()
{
	int i,j;
	for(i=0; i<MAXN; i++)
		x[i]=i+1;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%d",&A[i][j]);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%d",&B[i][j]);
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				scanf("%d",&C[i][j]);
		cal(l,x,A);
		cal(l,l,B);
		cal(r,x,C);
		if(the_same())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
