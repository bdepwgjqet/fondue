/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  05/26/2012 03:43:05 PM
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
int t,n,m;
int cnt[N];

int ok()
{
	int x,y,tag=1;
	for(int i=0; i<m; i++)
	{
		scanf("%d%d",&x,&y);
		if(cnt[x]==inf)
			cnt[x]=y;
		else if(cnt[x]!=y)
			tag=0;
	}
	if(tag==0)
		return 0;
	int s=0;
	for(int i=1; i<=n; i++)
	{
		if(cnt[i]==inf)
			continue;
		if(cnt[i]<0||cnt[i]>n-1)
			return 0;
		s+=cnt[i];
	}
	if(s>n-1)
		return 0;
	return 1;
}

int main()
{
	scanf("%d",&t);
	for(; t--;)
	{
		for(int i=0; i<N; i++)
			cnt[i]=inf;
		scanf("%d%d",&n,&m);
		if(ok())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
