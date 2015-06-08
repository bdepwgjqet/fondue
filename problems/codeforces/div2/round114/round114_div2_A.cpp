/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:37:48 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <iostream>
#include <algorithm>
#define N 1010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int main()
{
	int n,x,y;
	double xx;
	int ret;
	while(scanf("%d%d%d",&n,&x,&y)!=EOF)
	{
		xx=1.0*n*y/100.0;
		ret=ceil(xx)-x;
		if(ret<0)	ret=0;
		printf("%d\n",ret);
	}
	return 0;
}
