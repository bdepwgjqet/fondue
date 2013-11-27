/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/25/2012 12:58:18 PM
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
#define N 100010
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

int dat[N];
vector<int> e[N];

int main()
{
	int n,m,u,v,x,ret;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0; i<N; i++)
			e[i].clear();
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			e[dat[i]].push_back(i);
		}
		for(int i=0; i<m; i++)
		{
			scanf("%d%d%d",&u,&v,&x);
			printf("%d\n",upper_bound(e[x].begin(),e[x].end(),v)-lower_bound(e[x].begin(),e[x].end(),u));
		}
	}
	return 0;
}
