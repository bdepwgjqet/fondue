/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/13/2012 01:24:53 PM
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

LL dfs(LL a,LL b)
{
	LL x=a&1,y=b&1;
	if(x==1&&y==0)
		return -1;
	else if(a%b==0)
		return a/b;
	else if(a/2+x>b)
	{
		if((b+a%b)&1)
			return a/b+2;
		else
			return a/b+1;
	}
	else
	{
		if(x==0&&y==0)
			return 3;
		else if(x==1&&y==1)
			return 3;
		else
			return dfs(a,a-b);
	}
}

int main()
{
	LL a,b,ret;
	while(scanf("%I64d%I64d",&a,&b)!=EOF)
//	while(scanf("%lld%lld",&a,&b)!=EOF)
	{
		ret=dfs(a,b);
		if(ret<0)
			puts("No Solution!");
		else
			cout<<ret<<endl;
	}
	return 0;
}
