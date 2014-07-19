/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/16/2012 11:20:05 PM
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
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

LL D[66];

void init(LL k)
{
	int i;
	D[0]=1;
	for(i=1; i<66; i++)
		D[i]=D[i-1]*k;
}

int too_small(LL m,LL n)
{
	LL ret=m,i;
	for(i=1; m/D[i]; i++)
		ret+=m/D[i];
	if(ret<n)	return 1;
	return 0;
}

int main()
{
	LL n,k,l,r,m;
	while(cin>>n>>k)
	{
		init(k);
		for(l=0,r=n+1; l<=r; )
		{
			m=(l+r)>>1;
			if(too_small(m,n))
				l=m+1;
			else
				r=m-1;
		}
		cout<<l<<endl;
	}
	return 0;
}
