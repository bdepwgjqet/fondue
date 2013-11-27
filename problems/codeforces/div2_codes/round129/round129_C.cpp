/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/11/2012 11:45:29 PM
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

LL ten[21];

void init()
{
	ten[0]=1;
	for(int i=1; i<21; i++)
		ten[i]=ten[i-1]*10;
}

LL getl(LL x)
{
	LL ret=0;
	for(; x;)
		x/=10,ret++;
	return ret;
}

LL geth(LL x)
{
	for(;;)
	{
		if((x/10)==0)
			return x;
		x/=10;
	}
}

LL get(LL x)
{
	LL ret=0;
	if(x<=0)
		return 0LL;
	LL l=getl(x),y=l-2,low=x%10;
	LL hi=geth(x);
	if(y<0)
		return x;
	if(y==0)
		return LL((hi<=low)+hi-1+9);
	for(int i=0; i<y; i++)
		ret+=9*ten[i];
	LL tmp=x%ten[l-1];
	tmp/=10;
	ret+=tmp+1;
	if(low<hi)
		ret--;
	return ret+(hi-1)*ten[y]+9;
}

int main()
{
	LL l,r;
	init();
	while(cin>>l>>r)
	{
		cout<<get(r)-get(l-1)<<endl;
	}
	return 0;
}
