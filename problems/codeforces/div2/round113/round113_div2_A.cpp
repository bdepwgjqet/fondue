/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/23/2012 11:30:12 PM
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

struct point{ int x,y,i; }p[N];

int cmp(point a,point b)
{
	return a.x==b.x?a.y<b.y:a.x>b.x; 
}

int main()
{
	int n,k,ret;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		for(int i=0; i<n; i++)
		{
			scanf("%d%d",&p[i].x,&p[i].y);
			p[i].i=i+1;
		}
		sort(p,p+n,cmp);
		ret=0;
		for(int i=0; i<n; i++)
			if(p[i].x==p[k-1].x&&p[i].y==p[k-1].y)
				ret++;
		printf("%d\n",ret);
	}
	return 0;
}


