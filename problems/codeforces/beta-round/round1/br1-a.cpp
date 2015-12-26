/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  08/19/2012 06:46:43 PM
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

LL get(LL a,LL b)
{
	LL ret=a/b;
	if(b*ret==a)
		return ret;
	return ret+1;
}

int main()
{
	LL m,n,a;
	while(scanf("%I64d%I64d%I64d",&m,&n,&a)!=EOF)
	{
		printf("%I64d\n",get(m,a)*get(n,a));
	}
	return 0;
}
