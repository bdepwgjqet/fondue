/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:04:22 AM
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
#define N 101000
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

int cmp(int a,int b){ return a<b; }

int put_YES(int n)
{
	int j=0,pre=0,now;
	for(int i=0; i<n; i=j)
	{
		for(; j<n&&dat[j]==dat[i]; j++);
		if(dat[j]-dat[i]>1)	
			return 0;
		now=j-i;
	//	printf("%d %d\n",now,pre);
		if(j==n)
			return now==pre;
		if(now<=pre)
			return 0;
		now-=pre;
		pre=now;
	}
	return 0;	//impossible
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0; i<n; i++)
			scanf("%d",&dat[i]);
		sort(dat,dat+n,cmp);
		if(put_YES(n))
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
