/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  03/30/2012 02:29:11 PM
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
#define X 10021
#define N 111
#define M 1000010
#define S 1000100
#define MOD 1000000007

typedef long long LL;
using namespace std;

inline int L(int i){ return i<<1; }
inline int R(int i){ return (i<<1)|1; }
inline int B(int i){ return 1<<i; }
inline int low_bit(int x){ return x&(-x); }

struct edge{ int f,t,n,i; }e[X];

int v[X],list[N],top,etop,in[N],ret[X][N],rtop[N],rnum;

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t,e[top].n=list[f];
	e[top].i=etop++;
	list[f]=top++;
}

int all0()
{
	for(int i=0; i<etop; i++)
		if(v[i]==0)
			return 0;
	return 1;
}

void dfs(int now,int cnt)
{
	//printf("%d=>",now);
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		if(!v[e[i].i])	
		{
			v[e[i].i]=1,cnt++;
		}
		ret[rnum][rtop[rnum]++]=e[i].t;
		//in[e[i].t]--;
		dfs(e[i].t,cnt);
		if(cnt>1)
			break;
	}
}

void solve(int now)
{
	rtop[rnum]=0;
	ret[rnum][rtop[rnum]++]=now;
	dfs(now,0);
	if(rtop[rnum]>1)
		rnum++;
}

int main()
{
	int n,i,x,y,m;
	while(scanf("%d",&n)!=EOF)
	{
		rnum=0;
		memset(rtop,0,sizeof(rtop));
		memset(ret,0,sizeof(ret));
		memset(in,0,sizeof(in));
		memset(v,0,sizeof(v));
		for(etop=top=i=0; i<n; i++)
			list[i]=-1;
		for(i=0; i<n; i++)
		{
			scanf("%d",&m);
			for(int j=0; j<m; j++)
			{
				scanf("%d",&x);
				in[x-1]++;
				insert(i,x-1);
			}
		}
		while(1)
		{
			for(i=0; i<n; i++)
				if(in[i]==0)
					solve(i);
			/*
			for(i=0; i<n; i++)
				printf("%d ",in[i]);
			puts("");
			*/
			if(all0())
				break;
		}
		printf("%d\n",rnum);
		for(i=0; i<rnum; i++)
		{
			printf("%d",ret[i][0]+1);
			for(int j=1; j<rtop[i]; j++)
				printf(" %d",ret[i][j]+1);
			puts("");
		}
	}
	return 0;
}
