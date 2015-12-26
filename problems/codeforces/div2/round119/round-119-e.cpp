/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/25/2012 09:05:06 PM
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
#define N 200100
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

struct edge{ int f,t,n; }e[S];
struct node{ int i,l; }q[S];
int top,list[N],tag[N],st,ed,dis[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int ok(int d)
{
	int l,r;
	memset(dis,0,sizeof(dis));
	node tmp;
	tmp.i=st,tmp.l=d;
	dis[st]=d;
	q[l=r=0]=tmp;
	for(; l<=r;)
	{
		node now=q[l++];
		int ii=now.i;
		if(now.l<dis[ii]||now.l<=0)
			continue;
		for(int i=list[ii]; i!=-1; i=e[i].n)
		{
			int to=e[i].t;
			if(to==ed)
				return 1;
			if(now.l-1>dis[to]||(tag[to]&&dis[to]<d))
			{
				int dd;
				if(tag[to])
					dd=d;
				else
					dd=now.l-1;
				dis[to]=dd;
				++r;
				q[r].l=dd;
				q[r].i=to;
			}
		}
	}
	return 0;
}

int solve(int n)
{
	int l=0,r=n,mid;
	for(; l<=r;)
	{
		mid=(l+r)>>1;
		if(ok(mid))
			r=mid-1;
		else
			l=mid+1;
	}
	if(r>=n)
		return -1;
	return l;
}

int main()
{
	int n,m,k,ret;
	while(scanf("%d%d%d",&n,&m,&k)!=EOF)
	{
		memset(tag,0,sizeof(tag));
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		for(int i=0; i<k; i++)
		{
			int x;
			scanf("%d",&x);
			tag[x-1]=1;
		}
		for(int i=0; i<m; i++)
		{
			int x,y;
			scanf("%d%d",&x,&y);
			x--,y--;
			insert(x,y);
			insert(y,x);
		}
		scanf("%d%d",&st,&ed);
		st--,ed--;
		ret=solve(n);
		printf("%d\n",ret);
	}
	return 0;
}
