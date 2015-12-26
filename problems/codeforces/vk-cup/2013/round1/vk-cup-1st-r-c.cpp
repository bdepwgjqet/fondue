/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/11/2012 10:56:30 PM
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
#define inf 0x7fffffff
#define MAXN 10100
#define MAXM 1000010
#define MOD 1000000007
#define X 33

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline LL max(LL a,LL b){ return a<b?b:a; }
inline LL min(LL a,LL b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

struct data{ LL l,r; }A[2][MAXN],tmp;
int top[2];
LL B[X];

void init()
{
	int i;
	B[0]=1;
	for(i=1; i<X; i++)
		B[i]=B[i-1]<<1;
}

void dfs(LL l,LL r,int id,int n)
{
	l=max(1,l);
	r=min(B[n]-1,r);
	if(l<=r)
	{
		tmp.l=l,tmp.r=r;
		A[id][top[id]++]=tmp;

		if(!((l<=1)&&(r>=B[n-1]-1)))
		{
			dfs(l,r,id,n-1);
			dfs(l-B[n-1],r-B[n-1],id,n-1);
		}
	}
}

int main()
{
	LL l1,r1,l2,r2,ret;
	int i,j;
	init();
	while(cin>>l1>>r1>>l2>>r2)
	{
		top[0]=top[1]=0;
		dfs(l1,r1,0,30);
		dfs(l2,r2,1,30);
		ret=0;
		for(i=0; i<top[0]; i++)
			for(j=0; j<top[1]; j++)
				ret=max(min(A[0][i].r,A[1][j].r)-max(A[0][i].l,A[1][j].l)+1,ret);
		cout<<ret<<endl;
	}
	return 0;
}


