/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/04/2012 12:27:52 PM
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
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

char s[20];
int n,k;
LL ret=0;

void dfs(int id,int cnt,LL sum,LL mul)
{
	if(cnt+n-id<k)
		return;
	if(id==n)
	{
		ret=max(ret,mul);
		return ;
	}
	dfs(id+1,cnt,sum*10+s[id],mul);
	if(cnt<k)
		dfs(id+1,cnt+1,0,mul*(sum*10+s[id]));
}

int main()
{
	scanf("%d%d%s",&n,&k,s);
	for(int i=0; i<n; i++)
		s[i]-='0';
	dfs(0,0,0,1);
	printf("%lld\n",ret);
	return 0;
}
