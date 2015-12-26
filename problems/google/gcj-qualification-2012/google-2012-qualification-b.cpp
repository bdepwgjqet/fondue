/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/14/2012 09:58:14 AM
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

int p,s;

int not_sur(int x)
{
	int mod=x%3;
	x/=3;
	if(x>=p)
		return 1;
	if(mod==0)
		return 0;
	else if(mod==1)
	{
		if(x+1>=p)
			return 1;
		return 0;
	}
	if(x+1>=p)
		return 1;
	return 0;
}

int sur_ok(int x)
{
	int mod=x%3;
	x/=3;
	if(mod==0)
	{
		if(x+1>=p&&x-1>=0)
			return 1;
		return 0;
	}
	else if(mod==1)
		return 0;
	if(x+2>=p)
		return 1;
	return 0;
}

int main()
{
	int T,ca,n,ret,x;
	scanf("%d",&T);
	for(ca=1; ca<=T; ca++)
	{
		ret=0;
		printf("Case #%d: ",ca);
		scanf("%d%d%d",&n,&s,&p);
		for(int i=0; i<n; i++)
		{
			scanf("%d",&x);
			if(not_sur(x))
				ret++;
			else if(sur_ok(x)&&s>0)
				ret++,s--;
		}
		printf("%d\n",ret);
	}
	return 0;
}
