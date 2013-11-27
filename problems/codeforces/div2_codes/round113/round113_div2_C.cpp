/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/23/2012 11:43:26 PM
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

int main()
{
	int n,x,l,r,ret,k,y;
	while(scanf("%d%d",&n,&x)!=EOF)
	{
		y=-1; ret=0;
		for(int i=1; i<=n; i++)
		{
			scanf("%d",&dat[i]);
			if(dat[i]==x)
				y=i;
		}
		if(y==-1)	dat[++n]=x,ret++;
		sort(dat+1,dat+1+n,cmp);
		l=r=0;
		for(int i=1; i<=n; i++)
			if(dat[i]==x)
			{
				l=i;
				break;
			}
		for(int i=l; i<=n; i++)
			if(dat[i]==x)
			{
				r=i;
			}
		k=(n+1)/2;
		if(r<k)
		{
			for(; r<k; )
				ret++,n++,k=(n+1)/2,r++;
		}
		else if(l>k)
		{
			for(; l>k; )
				n++,ret++,k=(n+1)/2;
		}
		printf("%d\n",ret);
	}
	return 0;
}


