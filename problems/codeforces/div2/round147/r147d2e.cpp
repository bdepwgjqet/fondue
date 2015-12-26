/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  10/26/2012 12:27:06 AM
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
#define N 3101
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
#define X 26

typedef long long LL;
using namespace std;

char s[N],ts[111][111];
int cnt[N];
int sn[X],tn[N][X];

struct edge{ int f,t,c,flow,n; }e[S];
int list[N],top,q[S],v[N],pre[N],minv[N],max_flow;

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
	for(i=0; i<n; i++)	pre[i]=-1,minv[i]=inf,v[i]=0;
	q[l=r=0]=s;
	minv[s]=0,v[s]=1;
	for(; l<=r; )
	{
		i=q[l++];
		v[i]=0;
		for(j=list[i]; j!=-1; j=e[j].n)
			if(e[j].flow>0&&minv[i]+e[j].c<minv[e[j].t])
			{
				pre[e[j].t]=j;
				minv[e[j].t]=minv[i]+e[j].c;
				if(!v[e[j].t])
					v[e[j].t]=1,q[++r]=e[j].t;
			}
	}
	return minv[t]!=inf;
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
		ret+=now_flow*minv[t];
	}
	return ret;
}



int main()
{
	int n;
	while(scanf("%s",s)+1)
	{
		top=0;
		for(int i=0; i<N; i++)
			list[i]=-1;
		memset(sn,0,sizeof(sn));
		memset(tn,0,sizeof(tn));
		for(int i=0; s[i]; i++)
			sn[s[i]-'a']++;
		scanf("%d",&n);
		for(int i=0; i<n; i++)
		{
			scanf("%s%d",ts[i],&cnt[i]);
			for(int j=0; ts[i][j]; j++)
				tn[i][ts[i][j]-'a']++;
		}
		int nn=n*27;
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<X; j++)
			{
				insert(i*27+j,i*27+26,i+1,tn[i][j]);
				insert(nn+j,i*27+j,0,sn[j]);
			}
			insert(i*27+26,nn+27,0,cnt[i]);
		}
		for(int i=0; i<X; i++)
			insert(nn+26,nn+i,0,sn[i]);
		int ret=mcmf(nn+28,nn+26,nn+27);
		if(max_flow==strlen(s))
			printf("%d\n",ret);
		else
			puts("-1");
	}
	return 0;
}
