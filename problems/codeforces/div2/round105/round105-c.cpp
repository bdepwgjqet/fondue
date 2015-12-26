/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/14/2012 11:51:22 AM
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

int ret[N],top,n,a,b;

int ok()
{
	int now,s,nnn=n;
	top=0;
	if(b==0)
	{
		ret[0]=2;
		top=1;
		if(n==1)
		{
			if(a==0)
				return 1;
			else
				return 0;
		}
		else
			ret[1]=1,top=2,now=3,s=3,n-=2;
	}
	else
	{
		if(n==1)
			return 0;
		else
			ret[0]=1,ret[1]=2,now=3,top=2,s=3,b--,n-=2;
	}
	for(int j=1; j<=b; j++)
	{
		if(s+1>50000)
			return 0;
		ret[top++]=s+1,now=s+2,s+=s+1;
	}
	for(int j=1; j<=a; j++)
	{
		if(now>50000)
			return 0;
		ret[top++]=now,s+=now,now++;
	}
	for(int j=1; j<=n-a-b; j++)
		ret[top++]=1;
	if(top>nnn)
		return 0;
	return 1;
}

int main()
{
	scanf("%d%d%d",&n,&a,&b);
	if(ok())
	{
		for(int i=0; i<top; i++)
			printf("%d ",ret[i]);
		puts("");
	}
	else
		puts("-1");
	return 0;
}
