/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/10/2012 10:22:19 AM
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

char s[MAXN][MAXN],t[MAXN][MAXN];

void check(int r,int c,int n)
{
	int i,j,u,v;
	/*
	printf("%d %d %d\n",r,c,n);
	for(i=0; i<r; i++,puts(""))
		for(j=0; j<c; j++)
			printf("%c",t[i][j]);
			*/
	for(i=0; i+r<=n; i+=r)
		for(j=0; j+c<=n; j+=c)
			for(u=0; u<r; u++)
				for(v=0; v<c; v++)
				{
					if(t[u][v]=='1')
					{
						printf("%c",s[i+u][j+v]);
					}
				}
}

void solve(int n)
{
	int r,c,u,v,i,j;
	for(r=c=n; ; )
	{
		check(r,c,n);
		if(c&1)	break;
		c>>=1;
		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
			{
				if(t[i][2*c-j-1]=='1')
					t[i][j]='1';
				else
					t[i][j]='0';
			}
		check(r,c,n);
		r>>=1;
		for(i=0; i<r; i++)
			for(j=0; j<c; j++)
			{
				if(t[2*r-i-1][j]=='1')
					t[i][j]='1';
				else
					t[i][j]='0';
			}
	}
}

int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0; i<n; i++)
			scanf("%s",s[i]);
		for(i=0; i<n; i++)
			scanf("%s",t[i]);
		solve(n);
		puts("");
	}
	return 0;
}
