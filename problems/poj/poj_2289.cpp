/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/11/2012 08:23:38 PM
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
#define N 1610
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
char s[N];
int mat[N][N],cnt[N],list[N],top,y[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int find(int now,int lim)
{
	for(int i=list[now]; i!=-1; i=e[i].n)
	{
		int to=e[i].t;
		if(!y[to])
		{
			y[to]=1;
			if(cnt[to]<lim)
			{
				mat[to][cnt[to]++]=now;
				return 1;
			}
			for(int j=0; j<cnt[to]; j++)
				if(find(mat[to][j],lim))
				{
					mat[to][j]=now;
					return 1;
				}
		}
	}
	return 0;
}

int ok(int lim,int n)
{
	memset(mat,0,sizeof(mat));
	memset(cnt,0,sizeof(cnt));
	for(int i=0; i<n; i++)
	{
		memset(y,0,sizeof(y));
		if(!find(i,lim))
			return 0;
	}
	return 1;
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		if(n==0&&m==0)
			break;
		for(int i=0; i<n; i++)
		{
			scanf("%s",s);
			while(1)
			{
				int x;
				scanf("%d",&x);
				insert(i,x);
				if(getchar()=='\n')
					break;
			}
		}
		int l=0,r=n,mid;
		for(; l<=r;)
		{
			mid=(l+r)>>1;
			if(ok(mid,n))
				r=mid-1;
			else
				l=mid+1;
		}
		printf("%d\n",l);
	}
	return 0;
}
