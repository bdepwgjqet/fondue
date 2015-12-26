/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/27/2012 10:56:28 AM
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
#define inf 1e10
#define N 501
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

map<string,int> id;
char s[30],t[30];

struct edge{ int f,t,n; double l; }e[S];
struct heap_t{
	int v; double l;
	friend bool operator<(heap_t a,heap_t b)
	{
		return a.l>b.l;
	}
}h_t;
int top,list[N],st,ed,v[N];
double min_l[N];
priority_queue<heap_t> q;

void insert(int f,int t,double l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

double dijkstra(int st,int ed,int n)
{
	int now,to,i;
	for(; !q.empty(); q.pop());
	for(int i=0; i<n; i++)
		min_l[i]=inf,v[i]=0;
	min_l[h_t.v=st]=h_t.l=0;
	q.push(h_t);
	for(; !q.empty(); )
	{
		h_t=q.top();
		q.pop();
		now=h_t.v;
		if(!v[now])
		for(v[now]=1,i=list[now]; i!=-1; i=e[i].n)
		{
			to=e[i].t;
			if(!v[to]&&min_l[to]>min_l[now]+e[i].l)
				h_t.v=to,h_t.l=min_l[to]=min_l[now]+e[i].l,q.push(h_t);
		}
	}
}

int main()
{
	int n,m,x,y;
	double u,v;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<n; i++)
		{
			scanf("%s",s);
			id[string(s)]=i;
		}
		for(int i=0; i<m; i++)
		{
			scanf("%s%s%lf%lf",s,t,&u,&v);
			x=id[string(s)];
			y=id[string(t)];
			u/=v;
			insert(x,y,u);
			insert(y,x,u);
		}
		st=id[string("China")];
		ed=id[string("Mauritius")];
		dijkstra(st,ed,n);
		printf("%.2lf\n",min_l[ed]);
	}
	return 0;
}
