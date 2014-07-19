/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/26/2012 06:17:00 PM
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

LL pow(LL a,LL b,LL mod)
{
	LL ret=1;
	for(; b;)
	{
		if(b&1)
			ret=ret*a%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ret;
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<(((pow(3,n,m)-1)+m)%m)<<endl;
	return 0;
}
