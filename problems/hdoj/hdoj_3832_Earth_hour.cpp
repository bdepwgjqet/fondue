/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  04/04/2012 03:12:41 PM
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
#define inf 100000000
#define eps 1e-8
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

struct edge{ int f,t,n,l; }e[S];
struct circle{ double x,y,r; }c[N];
struct heap_t{ int v,l;
	friend int operator<(heap_t a,heap_t b)
	{
		return a.l>b.l; 
	}
}h_t;
int top,list[N],min_l[N],v[N];

void insert(int f,int t,int l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

priority_queue<heap_t> q;

void dijkstra(int n,int s)
{
	int i;
	for(; !q.empty(); q.pop());
	for(i=0; i<n; i++)
		v[i]=0,min_l[i]=inf;
	min_l[h_t.v=s]=h_t.l=0;
	q.push(h_t);
	for(; !q.empty();)
	{
		h_t=q.top();
		q.pop();
		if(!v[h_t.v])
			for(v[h_t.v]=1,i=list[h_t.v]; i!=-1; i=e[i].n)
				if(!v[e[i].t]&&min_l[e[i].f]+e[i].l<min_l[e[i].t])
					min_l[h_t.v=e[i].t]=h_t.l=min_l[e[i].f]+e[i].l,q.push(h_t);
	}
}

double len(int i,int j)
{
	return sqrt((c[i].x-c[j].x)*(c[i].x-c[j].x)+(c[i].y-c[j].y)*(c[i].y-c[j].y));
}

int connect(int i,int j)
{
	return len(i,j)<=c[i].r+c[j].r;
}

int main()
{
	int t,ret,n;
	scanf("%d",&t);
	for(;t--;)
	{
		scanf("%d",&n);
		top=0;
		for(int i=0; i<=n; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
			scanf("%lf%lf%lf",&c[i].x,&c[i].y,&c[i].r);
		for(int i=0; i<n; i++)
			for(int j=0; j<i; j++)
				if(connect(i,j))
				{
					insert(i,j,1);
					insert(j,i,1);
				}
		ret=inf;
		for(int i=0; i<n; i++)
		{
			dijkstra(n,i);
			ret=min(ret,min_l[0]+min_l[1]+min_l[2]);
		}
		if(ret>=inf)
			puts("-1");
		else
			printf("%d\n",n-ret-1);
	}
	return 0;
}
