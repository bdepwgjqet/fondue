/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/25/2012 11:24:58 PM
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
#define N 100010
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

int cnt[N];

int main()
{
	int n;
	while(scanf("%d",&n)+1)
	{
		memset(cnt,0,sizeof(cnt));
		for(int i=0; i<n; i++)
		{
			int x,y,nx;
			scanf("%d%d",&x,&y);
			nx=x*100+y;
			cnt[nx]++;
		}
		int ret=1;
		for(int i=0; i<N; i++)
			ret=max(ret,cnt[i]);
		printf("%d\n",ret);
	}
	return 0;
}

