/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/09/2012 05:19:45 PM
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
#define inf 100000000
#define MAXN 5501
#define MAXS 1000101
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int max(int a,int b){ return a<b?b:a; }
//inline int min(int a,int b){ return a<b?a:b; }
inline int abs(int x){ return x<0?-x:x; }
inline int G(int i,int j,int n){ return n*i+j; }

struct edge{ int f,t,c,flow,n; }e[MAXS];
int list[MAXN],top,q[MAXS],v[MAXN],pre[MAXN],max_c[MAXN],max_flow;

void s_insert(int f,int t,int c,int flow)
{
	e[top].f=f,e[top].t=t,e[top].c=c,e[top].flow=flow;
	e[top].n=list[f],list[f]=top++;
}

void insert(int f,int t,int c,int flow)
{
	s_insert(f,t,c,flow);
	s_insert(t,f,-c,0);
}

int spfa(int n,int s,int t)
{
	int i,l,r,j;
	//printf("%d %d=>",n,t);
	for(i=0; i<n; i++)	pre[i]=-1,max_c[i]=-inf,v[i]=0;
	q[l=r=0]=s;
	max_c[s]=0,v[s]=1;
	for(; l<=r; )
	{
		i=q[l++];
		v[i]=0;
		for(j=list[i]; j!=-1; j=e[j].n)
			if(e[j].flow>0&&max_c[i]+e[j].c>max_c[e[j].t])
			{
				pre[e[j].t]=j;
				max_c[e[j].t]=max_c[i]+e[j].c;
				if(!v[e[j].t])
					v[e[j].t]=1,q[++r]=e[j].t;
			}
	}
	return max_c[t]>-inf;
}

int mcmf(int n,int s,int t)
{
	int ret=0,i,now_flow;
	max_flow=0;
	
	for(; spfa(n,s,t); )
	{
		now_flow=inf;
		for(i=pre[t]; i!=-1; i=pre[e[i].f])
			if(now_flow>e[i].flow)
				now_flow=e[i].flow;
		for(i=pre[t]; i!=-1; i=pre[e[i].f])
			e[i].flow-=now_flow,e[i^1].flow+=now_flow;
		max_flow+=now_flow;
		ret+=now_flow*max_c[t];
	}
	
	return ret;
}

int main()
{
	int n,k,S,T,x,N,ret,i,j;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		N=n*n;
		S=2*N,T=2*N+1;
		for(top=i=0; i<T+1; i++)
			list[i]=-1;
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
			{
				scanf("%d",&x);
				insert(G(i,j,n),G(i,j,n)+N,x,1);
				if(j+1<n)
				{
					insert(G(i,j,n),G(i,j+1,n),0,inf);
					insert(G(i,j,n)+N,G(i,j+1,n),0,inf);
				}
				if(i+1<n)
				{
					insert(G(i,j,n),G(i+1,j,n),0,inf);
					insert(G(i,j,n)+N,G(i+1,j,n),0,inf);
				}
			}
		insert(S,G(0,0,n),0,k);
		insert(G(n-1,n-1,n)+N,T,0,1);
		insert(G(n-1,n-1,n),T,0,k-1);
		ret=mcmf(2*N+2,S,T);
		printf("%d\n",ret);
	}
	return 0;
}

