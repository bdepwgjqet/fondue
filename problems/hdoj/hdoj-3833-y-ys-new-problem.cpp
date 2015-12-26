/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/04/2012 01:32:09 PM
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

int n;
int id[N],dat[N];

int is_ok()
{
	int i,v;
	for(int i=1; i<=n; i++)
		for(int v=1; i-v>0&&i+v<=n; v++)
		{
			if(id[i+v]>id[i])
			{
				if(id[i]>id[i-v])
					return 1;
			}
			else
			{
				if(id[i]<id[i-v])
					return 1;
			}
		}
	return 0;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			id[dat[i]]=i;
		}
		if(is_ok())
			puts("Y");
		else
			puts("N");
	}
	return 0;

}
