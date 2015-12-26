/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 01:01:17 PM
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

LL a,b,c;

int main()
{
	int t,ret;
	scanf("%d",&t);
	for(int ca=1; ca<=t; ca++)
	{
		ret=0;
		cin>>a>>b;
		c=a+b;
		if(c<0)	c=-c;
		for(; c;)
		{
			ret+=((c%10)==5);
			c/=10;
		}
		printf("%d\n",ret);
	}
	return 0;
}
