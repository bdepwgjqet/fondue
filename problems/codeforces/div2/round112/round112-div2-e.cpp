/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/16/2012 11:20:19 PM
 ***/

#include <cstring>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <iostream>
#include <algorithm>
#define MAXN 1010
#define MAXM 1000010
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
#define N 4200000
#define B 22
#define M 0x3fffff

int dat[N],ret[N];
LL D[50];

void init()
{
	int i;
	D[0]=1;
	for(i=1; i<50; i++)
	{
		D[i]=(D[i-1]<<1);
	}
}

int main()
{
	int n,i,tmp,x,y,j;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		memset(ret,-1,sizeof(ret));
		for(i=0; i<n; i++)
		{
			scanf("%d",&dat[i]);
	//		printf("%d\n",M);
			ret[dat[i]^M]=dat[i];
		}
		for(i=M; i>=0; i--)
			if(ret[i]!=-1)
				for(j=0; j<B; j++)
					if(i&D[j])
					{
						if(ret[i^D[j]]==-1)
							ret[i^D[j]]=ret[i];
					}
		for(i=0; i<n; i++)
			printf("%d ",ret[dat[i]]);
		puts("");
	}
	return 0;
}
