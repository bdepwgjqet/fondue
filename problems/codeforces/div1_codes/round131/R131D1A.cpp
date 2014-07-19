/**
 *       Compiler:  gcc
 *         Author:  bdep__  
 *        Created:  07/30/2012 11:44:04 PM
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

int dat[N];
int mat[3][3]={{0,1,2},{2,0,1},{1,2,0}},in[N],tmp[N],num[3];
struct edge{ int f,t,n; }e[S];
int top,list[N],q[N],tt,vis[N];

void insert(int f,int t)
{
	e[top].f=f,e[top].t=t;
	e[top].n=list[f],list[f]=top++;
}

int solve(int n)
{
	int ret=inf,cnt,now;
	for(int i=0; i<3; i++)
	{
		cnt=0;
		for(int j=0; j<n; j++)
			tmp[j]=in[j];
		memset(vis,0,sizeof(vis));
		now=i;
		for(int j=0; j<n; )
		{
			int k=-1;
			for(int u=0; u<n; u++)
				if(tmp[u]==0&&!vis[u]&&dat[u]==now)
				{
					k=u;
					break;
				}
			if(k==-1)
			{
				cnt++,now=(now+1)%3;
				continue;
			}
			vis[k]=1;
			for(int u=list[k]; u!=-1; u=e[u].n)
				if(!vis[e[u].t])
					tmp[e[u].t]--;
			j++;
		}
		ret=min(ret,cnt);
	}
	return ret;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		top=0;
		for(int i=0; i<n; i++)
			list[i]=-1;
		memset(in,0,sizeof(in));
		for(int i=0; i<n; i++)
		{
			scanf("%d",&dat[i]);
			dat[i]--;
		}
		for(int i=0; i<n; i++)
		{
			int m;
			scanf("%d",&m);
			for(int j=0; j<m; j++)
			{
				int y;
				scanf("%d",&y);
				y--;
				insert(y,i);
				in[i]++;
			}
		}
		printf("%d\n",solve(n)+n);
	}
	return 0;
}
