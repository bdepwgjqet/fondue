/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/10/2012 05:28:10 PM
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
#define MAXM 1000010
#define MOD 1000000007
#define N 1011

#define DIGIT 4
#define DEPTH 10000
#define MAXN  2502
typedef int big_num[MAXN+1];

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }

void write(const big_num a)
{
    int i,j;
    for(printf("%d",a[i=a[0]]),i--; i; i--)
        for(j=DEPTH/10; j; j/=10)
            printf("%d",a[i]/j%10);
}

void add(big_num a,big_num b)
{
    int i;
    for(i=1; i<=b[0]; i++)
        if((a[i]+=b[i])>=DEPTH)
            a[i]-=DEPTH,a[i+1]++;
    if(b[0]>=a[0])      a[0]=b[0];
    else                for(; a[i]>=DEPTH && i<=a[0]; a[i]-=DEPTH,i++,a[i]++ );
    a[0]+=(a[a[0]+1]>0);
}

big_num g[N],f[N];

void init()
{
	int i;
	memset(g,0,sizeof(g));
	memset(f,0,sizeof(f));
	for(i=0; i<N; i++)
	{
		g[i][0]=1;
		f[i][0]=1;
	}
	g[1][1]=1;
	g[2][1]=1;
	g[3][1]=1;
	f[1][1]=1;
	f[2][1]=1;
	f[3][1]=2;
	for(i=4; i<N; i++)
	{
		add(g[i],g[i-1]);
		add(g[i],g[i-3]);
		add(f[i],f[i-1]);
		add(f[i],g[i-2]);
		add(f[i],g[i-3]);
	}
	/*
	for(i=1; i<20; i++)
	{
		write(f[i]);
		puts("");
	}
	*/
}

int main()
{
	int n;
	init();
	while(scanf("%d",&n)!=EOF)
	{
		write(f[n]);
		puts("");
	}
	return 0;
}
