/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  06/02/2012 10:07:02 AM
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

LL x,a,b;
LL ten[N];
int l;

void init()
{
	ten[0]=1;
	for(int i=1; i<20; i++)
		ten[i]=ten[i-1]*10;
}

int getlen(LL n)
{
	int ret=0;
	if(n==0)	return 1;
	for(; n;)
		n/=10,ret++;
	return ret;
}

LL calc(LL n,int ln)
{
	int y=ln-l-1;
	LL ret=0;
	if(y<0)
		return n>=x;
	ret=(n/ten[ln-1])*ten[y];
	ret+=calc(n%ten[ln-1],ln-1);
	return ret;
}

int main()
{
	int t,la,lb;
	init();
	scanf("%d",&t);
	for(; t--;)
	{
		cin>>x>>a>>b;
		l=getlen(x);
		la=getlen(a-1);
		lb=getlen(b);
		cout<<calc(b,lb)-calc(a-1,la)<<endl;
	}
	return 0;
}
