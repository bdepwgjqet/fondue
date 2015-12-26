/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  09/20/2012 12:55:36 AM
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
#define N 10100
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

int vis[N];

int dat[N]={0,2, 3, 5, 7, 13, 17, 19, 31, 61, 89, 107, 127, 521, 607, 1279, 2203, 2281, 3217, 4253, 4423, 9689, 9941, 11213, 19937, 21701, 23209, 44497, 86243, 110503, 132049, 216091, 756839, 859433, 1257787, 1398269, 2976221, 3021377, 6972593, 13466917, 20996011, 24036583};

LL cal(int x)
{
	LL ret=1,y=2;
	for(; x;)
	{
		if(x&1)
			ret=(ret*y)%MOD;
		x>>=1;
		y=(y*y)%MOD;
	}
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		cout<<((cal(dat[n]-1)-1)%MOD+MOD)%MOD<<endl;
	}
}
