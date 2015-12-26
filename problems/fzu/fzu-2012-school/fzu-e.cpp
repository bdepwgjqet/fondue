/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/28/2012 03:48:06 PM
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
#define N 1010
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

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct edge{ int f,t,v,n; }e[S];
int top,list[N];

void insert(int f,int t,int v)
{
	e[top].f=f,e[top].t=t,e[top].v=v;
	e[top].n=list[f],list[f]=top++;
}

int v[N],ret,ST,cnt;

void dfs(int now,int ttl,int pre)
{
	v[now]=1;
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int t=e[i].t;
		if(!v[t])
			dfs(t,ttl+e[i].v,now);
		else if(ST==t&&t!=pre)
		{
			if(ret>ttl+e[i].v)
				ret=ttl+e[i].v,cnt=1;
			else if(ret==ttl+e[i].v)
				cnt++;
		}
	}
	v[now]=0;
}

int main()
{
	int t,ca=1,n,m;
	scanf("%d",&t);
	for(ca=1; ca<=t; ca++)
	{
		ret=inf;
		cnt=0;
		scanf("%d%d",&n,&m);
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<m; i++)
		{
			int x,y,v;
			scanf("%d%d%d",&x,&y,&v);
			x--,y--;
			insert(x,y,v);
			insert(y,x,v);
		}
		for(int i=0; i<n; i++)
		{
			ST=i;
			memset(v,0,sizeof(v));
			dfs(i,0,-1);
		}
		printf("%d %d\n",ret,cnt);
	}
	return 0;
}
