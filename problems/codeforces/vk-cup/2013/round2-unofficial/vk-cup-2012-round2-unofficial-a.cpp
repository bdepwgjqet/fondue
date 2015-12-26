/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/26/2012 02:37:44 PM
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
#define N 10100
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int cmp(int a,int b){ return a<b; }
int dat[N];

int main()
{
	int n,a,b;
	while(scanf("%d%d%d",&n,&a,&b)!=EOF)
	{
		for(int i=1; i<=n; i++)
			scanf("%d",&dat[i]);
		sort(dat+1,dat+n+1,cmp);
		printf("%d\n",dat[b+1]-dat[b]);
	}
	return 0;
}


