/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/26/2012 06:36:49 PM
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
#define X 1000000
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
LL mod;
LL mat[2][2],tmp[2][2],ret[2][2];

int ok(LL id,LL l,LL r,LL k)
{
	return r/id-(l-1)/id>=k;
}

void cal(LL c[][2],LL a[][2],LL b[][2])
{
	memset(tmp,0,sizeof(tmp));
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			for(int k=0; k<2; k++)
				tmp[i][j]=(tmp[i][j]+a[i][k]*b[k][j])%mod;
	for(int i=0; i<2; i++)
		for(int j=0; j<2; j++)
			c[i][j]=tmp[i][j];
}

LL fib(LL n)
{
	if(n<=2) return 1%mod;
	mat[0][0]=1;
	mat[0][1]=1;
	mat[1][0]=1;
	mat[1][1]=0;
	ret[1][1]=ret[0][0]=1;
	ret[0][1]=ret[1][0]=0;
	n--;
	for(; n;)
	{
		if(n&1)
			cal(ret,ret,mat);
		cal(mat,mat,mat);
		n>>=1LL;
	}
	return ret[0][0]%mod;
}

int main()
{
	LL l,r,k,m,len,ll,rr;
	LL id;
	while(cin>>m>>l>>r>>k)
	{
		mod=m;
		ll=1,rr=r;
		rr=1;
		LL add=0,sq=(LL)sqrt(1.0*r);
		for(LL i=1; i<=sq; i++)
			if(ok(i,l,r,k))
				rr=i;
		for(LL i=1; i<=sq; i++)
			if(ok(r/i,l,r,k))
				rr=max(rr,r/i);
		cout<<fib(rr)<<endl;
	}
	return 0;
}
