/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/24/2012 04:53:29 PM
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
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		printf("%d\n",n*(n-1)/2+1);
	}
	return 0;
}
