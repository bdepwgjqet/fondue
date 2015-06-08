/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/07/2012 02:01:49 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define inf 0x7ffffff
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int n,ret;

int dfs(int a,int b)
{
	if(a<1)	return inf;
	if(a==1)	return b-1;
	return dfs(b%a,a)+b/a;
}

int main()
{
	int m;
	while(scanf("%d",&n)!=EOF)
	{
		ret=inf;
		if(n>1)
			m=n>>1;
		else
			m=1;
		for(int i=1; i<=m; i++)
			ret=min(ret,dfs(i,n));
		printf("%d\n",ret);
	}
	return 0;
}
