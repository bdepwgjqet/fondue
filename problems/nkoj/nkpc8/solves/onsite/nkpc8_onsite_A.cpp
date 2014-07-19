/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/24/2012 03:58:34 PM
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
#define X 9

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int main()
{
	int n,t;
	while(scanf("%d",&n)!=EOF)
	{
		for(t=0; n;)
			t=(t+n%10)%X,n/=10;
		printf("%d\n",9-t);
	}
	return 0;
}


