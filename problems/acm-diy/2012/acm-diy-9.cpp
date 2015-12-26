/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/26/2012 03:13:58 PM
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

LL dat[N],des[N];

int solve(int l,int r)
{
//	printf("%d %d\n",l,r);
	if(r-l<=1)
	{
		for(int i=l; i<=r; i++)
			if(dat[i]!=des[i])
				return 0;
		return 1;
	}
	LL s=0;
	int i;
	for(i=l; i<r; i++)
	{
		s+=dat[i];
		if(s==des[l])
			break;
	}
	if(i>=r)
		return 0;
	if(i>l)
	{
		dat[i+1]=dat[i]+dat[i+1];
		for(int k=i; k>=l+2; k--)
			dat[k]=dat[k-1];
		dat[l+1]=-(s-dat[l]);
		dat[l]=s;
	}
	return solve(l+1,r);
}

int main()
{
	int n,t;
	scanf("%d",&t);
	for(; t--;)
	{
		scanf("%d",&n);
		for(int i=0; i<n; i++)
			cin>>dat[i];
		for(int i=0; i<n; i++)
			cin>>des[i];
		if(solve(0,n-1))
			puts("yes");
		else
			puts("no");
	}
	return 0;
}
