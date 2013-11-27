/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/15/2012 11:03:00 PM
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

LL D[100];

void init()
{
	int i;
	D[0]=1;
	for(i=1; i<63; i++)
		D[i]=10*D[i-1];
}

LL dfs2(LL x,int l)
{
	if(l==1)	return 1;
	LL b=x%D[l-1],a=x/D[l-1];
	LL ret=0;
	if(a>0)
	{
		ret+=D[l-1];
		ret+=(a-1)*D[l-2]*(l-1);
		ret+=dfs2(D[l-1]-1,l-1);
	}
	else
		ret+=b+1;
	ret+=dfs2(b,l-1);
	return ret;
}

LL dfs(LL x,int l)
{
	if(l==1) return 1;

	LL b=x%D[l-1],a=x/D[l-1];
	LL ret=(a-1)*D[l-2]*(l-1);
	ret+=dfs(D[l-1]-1,l-1);
	ret+=dfs2(b,l-1);
	return ret;
}

LL cal(LL x)
{
	LL y; int l=0;
	if(x<0)
		return 0;
	for(y=x; y; )
		l++,y/=10;
	if(x==0)	l=1;
	return dfs(x,l);
}

int main()
{
	LL m,n;
	init();
	while(scanf("%lld%lld",&m,&n)&&m>=0)
		printf("%lld\n",cal(n)-cal(m-1));
	return 0;
}
