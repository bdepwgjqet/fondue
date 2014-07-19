//spfa
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#define inf 1e8
#define MAXS 2000001
#define MAXN 1001

typedef double elem_t;
struct edge{ int f,t,n; elem_t l; }e[MAXS];
int list[MAXN],top=0,v[MAXN],in[MAXN],q[MAXS];
elem_t min[MAXN];

void insert(int f,int t,elem_t l)
{
	e[top].f=f,e[top].t=t,e[top].l=l;
	e[top].n=list[f],list[f]=top++;
}

bool spfa(int n,int s)
{
	int i,j,l,r; 
	for(i=0; i<n; i++)	v[i]=0,min[i]=inf,in[i]=0;
	l=r=min[s]=0,q[l]=s,in[s]++;
	for(; l<=r; )
	{
		i=q[l++],v[i]=0;
		if(in[i]>n)	return 0;
		for(j=list[i]; j!=-1; j=e[j].n)
			if(min[i]+e[j].l<min[e[j].t])
			{
				min[e[j].t]=min[i]+e[j].l;
				if(!v[e[j].t])
				{
					v[e[j].t]=1;
					in[e[j].t]++;
					q[++r]=e[j].t;
				}
			}
	}
	return 1;
}
